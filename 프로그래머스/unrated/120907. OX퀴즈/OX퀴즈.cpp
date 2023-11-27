#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    string buffer;
    int result = 0;
    string temp;
    int num;
    for(auto iter = quiz.begin(); iter != quiz.end(); ++iter)
    {
        istringstream iss(*iter);
        getline(iss, buffer, ' ');
        result = stoi(buffer);
        getline(iss, buffer, ' ');
        cout << buffer;
        if(!buffer.compare("+")){
            getline(iss, buffer, ' ');
            result += stoi(buffer);
        }
        else
        {   
            getline(iss, buffer, ' ');
            result -= stoi(buffer);    
        }
        getline(iss, buffer, ' ');
        getline(iss, buffer, ' ');
        num = stoi(buffer);
        if(num == result)
            answer.push_back("O");
        else
            answer.push_back("X");
    }
    return answer;
}