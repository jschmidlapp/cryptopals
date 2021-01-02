#include <iomanip>
#include <string>
#include <sstream>
#include "data-utils.h"

namespace {
    char base64_lookup[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
} // anonymous namespace

std::vector<uint8_t> hex_to_bin(std::string hex) {

    std::vector<uint8_t> data = {};

    for (size_t i=0; i<hex.length(); i += 2) {

        std::string digit = hex.substr(i,2);

        data.push_back(std::stoi(digit,nullptr,16));
    }

    return data;
}

std::string bin_to_hex(std::vector<uint8_t> bin) {
    std::ostringstream out;

    for (auto digit : bin) {
        out << std::setfill('0') << std::setw(2) << std::hex << (int) digit;
        //out += boost::str(boost::format("%1$x") % digit);
        //printf("%x\n", digit);
    }

    return out.str();
}

std::string bin_to_base64(std::vector<uint8_t> data)
{
    std::string out;

    for (size_t i=0; i < data.size() - 2; i += 3) {
        uint32_t word = data[i] << 16 | data[i+1] << 8 | data[i+2];
        out += base64_lookup[word >> 18 & 0x3f];   
        out += base64_lookup[word >> 12 & 0x3f];
        out += base64_lookup[word >> 6 & 0x3f];
        out += base64_lookup[word & 0x3f];
    }

    switch (data.size() % 3) {
        case 2:
        {
            uint32_t word = data[data.size() - 2] << 16 | data[data.size() - 1] << 8;
            out += base64_lookup[word >> 18 & 0x3f];
            out += base64_lookup[word >> 12 & 0x3f];
            out += base64_lookup[word >> 6 & 0x3f];
            out += "=";
            break;
        }
        case 1:
        {
            uint32_t word = data[data.size() - 1] << 16;            
            out += base64_lookup[word >> 18 & 0x3f];
            out += base64_lookup[word >> 12 & 0x3f];            
            out += "==";
            break;
        }
    }

    return out;
}

std::string bin_to_string(std::vector<uint8_t> bin) {
    return std::string(bin.begin(), bin.end());
}