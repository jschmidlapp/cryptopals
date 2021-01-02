
#include "set1.h"
#include "data-utils.h"
#include "crypto-utils.h"

namespace {

    std::vector<uint8_t> encrypt_xor(std::vector<uint8_t> input, std::vector<uint8_t> key) {
        std::vector<uint8_t> encoded;
        for (size_t i=0; i<input.size(); i++) {
            encoded.push_back(input[i] ^ key[i]);
        }


        return encoded;
    }

    std::vector<uint8_t> encrypt_xor(std::vector<uint8_t> input, uint8_t key) {
        std::vector<uint8_t> encoded;
        for (size_t i=0; i<input.size(); i++) {
            encoded.push_back(input[i] ^ key);
        }

        return encoded;
    }


    std::string decrypt_xor(std::vector<uint8_t> ciphertext) {
        std::string plaintext;
        double max_score = 5.0;

        for (uint8_t i=0; i<255; i++) {
            auto dec = bin_to_string(encrypt_xor(ciphertext, i));
            auto score = english_score(dec);
            if (score < max_score) {
                max_score = score;
                plaintext = dec;
            }
        }

        return plaintext;
    }

} // anonymous namespace


void set1_challenge2() {
    auto input = hex_to_bin("1c0111001f010100061a024b53535009181c");
    auto key = hex_to_bin("686974207468652062756c6c277320657965");

    auto output = bin_to_hex(encrypt_xor(input, key));

    printf("encoded = %s\n", output.c_str());
}

void set1_challenge3() {
    auto input = hex_to_bin("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736");

//    auto output = bin_to_string(encrypt_xor(input, 88));
    auto output = decrypt_xor(input);

    printf("%s\n", output.c_str());
}