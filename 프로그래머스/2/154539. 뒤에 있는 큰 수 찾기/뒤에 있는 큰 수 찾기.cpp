#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int nSize = numbers.size();
    vector<int> answer(nSize);
    stack<int> s;
    int check = 0;
    int nNow = 0;
    for(int i = nSize - 1; i >= 0; i--)
    {
        answer[i] = -1;
        while(!s.empty())
        {
            if(s.top() > numbers[i])
            {
                answer[i] = s.top();
                break;
            }
            else
                s.pop();
        }
        s.push(numbers[i]);
    }
    return answer;
}