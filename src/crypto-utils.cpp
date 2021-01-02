#include <map>
#include <math.h>
#include "crypto-utils.h"

namespace {
    std::map<char, double> englishCharFrequency() {
        std::map<char, double> result;

        result['A'] = 0.0834;
        result['B'] = 0.0154;
        result['C'] = 0.0273;
        result['D'] = 0.0414;
        result['E'] = 0.1260;
        result['F'] = 0.0203;
        result['G'] = 0.0192;
        result['H'] = 0.0611;
        result['I'] = 0.0671;
        result['J'] = 0.0023;
        result['K'] = 0.0087;
        result['L'] = 0.0424;
        result['M'] = 0.0253;
        result['N'] = 0.0680;
        result['O'] = 0.0770;
        result['P'] = 0.0166;
        result['Q'] = 0.0009;
        result['R'] = 0.0568;
        result['S'] = 0.0611;
        result['T'] = 0.0937;
        result['U'] = 0.0285;
        result['V'] = 0.0106;
        result['W'] = 0.0234;
        result['X'] = 0.0020;
        result['Y'] = 0.0204;
        result['Z'] = 0.0006;

        return result;
    }

    std::map<char, double> englishCharFrequencyMap = englishCharFrequency();
} // anonymous namespace

double english_score(std::string in) {
	std::map<char, int> occurrences;
	for (char c = 'A'; c <= 'Z'; c++) {
		occurrences[c] = 0;
	}

	double addToScore = 0;
	int numberOfChars = 0;
	for (unsigned int i = 0; i < in.size(); i++) {
		
        if (isupper(in[i])) {
            addToScore += 0.01;
        }   
        char c = toupper(in[i]);
		if (isupper(c)) {
			occurrences[c] += 1;
		} else if (c > 32 && c < 127) {
			addToScore += 0.03;
		} else if ((c < 32 && c != 10 && c != 13) || (c > 126)) {
			addToScore += 0.1;
		}
		numberOfChars++;
	}

	double score = addToScore;
	for (char c = 'A'; c <= 'Z'; c++) {
		double englishFrq = englishCharFrequencyMap[c];
		double currentFrq = double(occurrences[c]) / numberOfChars;

		score += pow(englishFrq - currentFrq, 2);
	}

	return score;
}