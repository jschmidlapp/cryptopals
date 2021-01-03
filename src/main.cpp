#include <iostream>
#include "data-utils.h"
#include "set1.h"

void set1_challenge1() {
	std::string input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f";

	auto bin = hex_to_bin(input);

	auto encoded = bin_to_base64(bin);

	printf("encoded = %s\n", encoded.c_str());
}

int main(int argc, char *argv[])
{
	argc=argc;
	argv=argv;

	set1_challenge5();
}
