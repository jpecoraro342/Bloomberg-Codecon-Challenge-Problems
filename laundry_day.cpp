//Problem        : Mug Color
//Language       : C++
//Compiled Using : g++
//Version        : GCC 4.8.2
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
#include <vector>
#include <map>

using namespace std;

int main() {
    map<string, int> clothes;
    
    while (true) {
		string line;
		getline(cin, line);
		if (line.compare("") == 0) {
		    break;
		} 
		else {
			map<string, int>::iterator it;
			it = clothes.find(line);
			if (it != clothes.end()) {
				clothes[line] = it->second+1;
			}
			else {
				clothes[line] = 1;
			}
		}
    }
	
	vector<string> allItems;
	
	for (map<string, int>::iterator it=clothes.begin(); it!=clothes.end(); it++) {
	   allItems.push_back(it->first);
	}
	
	for (int i = 0; i < allItems.size(); i++) {
		string value = allItems.at(i);
		int count = clothes.find(value)->second;
		if (value.find("sock")!=string::npos) {
			cout << count/2 << "|" << value << endl;
				
			if((count%2 != 0) && (count/2 != 0)) {
				cout << "0|" << value << endl;
			}
			
		}
		else {
			cout << count << "|" << value << endl;
		}
	}
	
    return 0;
}