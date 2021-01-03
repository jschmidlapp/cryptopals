#ifndef _DATA_UTILS_H_
#define _DATA_UTILS_H_

#include <string>
#include <vector>

std::vector<uint8_t> hex_to_bin(std::string hex);
std::string bin_to_hex(std::vector<uint8_t> bin);
std::vector<uint8_t> string_to_bin(std::string str);
std::string bin_to_string(std::vector<uint8_t> bin);
std::string bin_to_base64(std::vector<uint8_t> data);
std::vector<uint8_t> bin_xor(std::vector<uint8_t> input);
std::vector<std::vector<uint8_t>> read_hex_file(std::string filepath);

#endif /* _DATA_UTILS_H_ */