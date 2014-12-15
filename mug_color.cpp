//Problem        : Mug Color
//Language       : C++ 11
//Compiled Using : g++
//Version        : GCC 4.8.2
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
#include <map>

using namespace std;

int main() {
    map<string, bool> colors;
    colors["White"] = true;
    colors["Yellow"] = true;
    colors["Blue"] = true;
    colors["Black"] = true;
    colors["Red"] = true;
    
    int numCases = 0;
    cin >> numCases;
    
    for (int i = 0; i < numCases; i++) {
        string color;
        cin >> color;
        colors[color] = false;
    }
    
    for (map<string, bool>::iterator it=colors.begin(); it!=colors.end(); it++) {
        if (it->second) {
            cout << it->first << endl;
            break;
        }
    }
    
    return 0;
}

