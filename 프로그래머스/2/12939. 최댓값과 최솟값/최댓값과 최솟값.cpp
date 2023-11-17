#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
	ss.str(s);
    int initValue;
    ss >> initValue;
    int num;
    int minValue = initValue;
    int maxValue = initValue;
	while (ss >> num) {
		if(num > maxValue)
            maxValue = num;
        if(num < minValue)
            minValue = num;
	}
    return to_string(minValue) + " " + to_string(maxValue);
}