#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    istringstream ss(my_string);
    string buffer;
    while (getline(ss, buffer, ' ')){
        answer.push_back(buffer);
    }
    return answer;
}