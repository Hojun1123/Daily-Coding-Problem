#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string myString) {
    string answer = "";
    char a;
    for(string::iterator iter = myString.begin(); iter != myString.end(); ++iter)
    {
        if((char)*iter >= 'a')
        {
            *iter -= 32;
        }
    }
    return myString;
}