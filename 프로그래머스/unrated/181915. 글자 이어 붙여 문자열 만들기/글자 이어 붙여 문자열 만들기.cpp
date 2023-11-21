#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> index_list) {
    string answer;
    for(auto iter = index_list.begin(); iter < index_list.end(); ++iter)
    {
        answer += my_string[*iter];
    }
    return answer;
}