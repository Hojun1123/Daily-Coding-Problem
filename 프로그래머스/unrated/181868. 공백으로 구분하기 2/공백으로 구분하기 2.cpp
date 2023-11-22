#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    istringstream ss(my_string);
    string buffer;
    while(getline(ss, buffer, ' '))
    {
        if(buffer.length())
            answer.push_back(buffer);
    }
    return answer;
}