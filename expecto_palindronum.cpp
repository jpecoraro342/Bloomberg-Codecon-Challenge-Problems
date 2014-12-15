#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(string theString) {
    const char* letters = theString.c_str();
    int head = 0;
    int tail = theString.length() - 1;
    while (head < tail) {
        if (letters[head] != letters[tail]) {
            return false;
        }
        head++;
        tail--;
    }
	return true;
}

string adjustedString(string original, int originalSize) {
    const char *oldString = original.c_str();
	int lengthDifference = original.length() - originalSize;
    char newString[original.length()+2];

    for (int i = 0; i < lengthDifference; i++) {
		newString[i] = oldString[i];
	}
	newString[lengthDifference] = oldString[originalSize-1];
	
	for (int i = 0; i < originalSize; i++) {
		newString[i+lengthDifference+1] = oldString[lengthDifference+i];
	}
	newString[lengthDifference+originalSize+1] = '\0'; //gotta get that null ending
    return string(newString);
}

string getShortestPalindrome(string input) {
    int originalLength = input.length();
    while (!isPalindrome(input)) {
        input = adjustedString(input, originalLength);
    }
    return input;
}

int main() {
    string input;
    cin >> input;
    cout << getShortestPalindrome(input).length() << endl;
    return 0;
}



