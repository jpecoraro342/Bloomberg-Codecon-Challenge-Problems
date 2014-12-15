//Problem        : Base Arithmetic
//Language       : C++11 (Beta)
//Compiled Using : g++
//Version        : GCC 4.8.2
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
#include <math.h>
#include <unordered_map>

using namespace std;

int getInt(char num, unordered_map<char, int>* largeValues) {
    int value;
    if (num > '9') {
        value = largeValues->find(num)->second;
    }
    else {
        value = num-'0';
    }
	return value;
}

int getBase(string number, unordered_map<char, int>* largeValues) {
    const char *num = number.c_str();
    char maxChar = 0;
    for (int i = 0; i < number.length(); i++) {
        if (num[i] > maxChar) 
            maxChar = num[i];
    }
    
    return getInt(maxChar, largeValues) + 1;
}

long long getDecimalValue(string number, unordered_map<char, int>* largeValues) {
    int base = getBase(number, largeValues);
    const char* num = number.c_str(); 
    int numberSize = number.length();
    long long sum = 0;
    for (int i = numberSize - 1; i >= 0; i--) {
        long multiplier = numberSize - i - 1;
        multiplier = pow(base, multiplier);
        sum += getInt(num[i], largeValues) * multiplier;
    }

    return sum;
}

int main() {
    unordered_map<char, int> hexValues;
    hexValues.insert(pair<char, int>('A', 10));
    hexValues.insert(pair<char, int>('B', 11));
    hexValues.insert(pair<char, int>('C', 12));
    hexValues.insert(pair<char, int>('D', 13));
    hexValues.insert(pair<char, int>('E', 14));
    hexValues.insert(pair<char, int>('F', 15));
    
    string firstNum;
    string secondNum;
    
    cin >> firstNum >> secondNum;
    
    int baseFirst = getBase(firstNum, &hexValues);
    int baseSecond = getBase(secondNum, &hexValues);
    
    long long value1 = getDecimalValue(firstNum, &hexValues);
    long long value2 = getDecimalValue(secondNum, &hexValues);
    
    cout << value1 + value2 << endl;
    
    return 0;
}

