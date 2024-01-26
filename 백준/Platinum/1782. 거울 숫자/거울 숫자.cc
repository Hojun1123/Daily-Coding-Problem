#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
using namespace std;
unsigned long long startNum, endNum;
//0 , 101, 1521 은 거울 수
//현재 수가
unsigned long long currNum;
unsigned long long tmp, tmp2;
string tmpNum, resultNum;
vector<int> v = { 0, 1, 2, 5, 8 }; 
int answer = 0;
void recursion(int depth)
{
    if (depth > 9)
        return;
    //1. depth * 2 - 1 길이 경우
    if ((currNum % 10 != 2) && (currNum % 10 != 5))
    {
        tmpNum = to_string(currNum);
        resultNum = tmpNum;
        for (int i = tmpNum.size() - 2; i >= 0; --i)
        {
            if (tmpNum[i] == '2')
            {
                resultNum +='5';
            }
            else if (tmpNum[i] == '5')
            {
                resultNum += '2';
            }
            else
            {
                resultNum += tmpNum[i];
            }
        }
        tmp = stoull(resultNum);
        //cout << "1 : " << tmp << "\n";
        if (tmp > endNum)
            return;
        else if(startNum <= tmp)
            answer++;
    }

    tmpNum = to_string(currNum);
    resultNum = tmpNum;
    for (int i = tmpNum.size() - 1; i >= 0; --i)
    {
        if (tmpNum[i] == '2')
        {
            resultNum += '5';
        }
        else if (tmpNum[i] == '5')
        {
            resultNum += '2';
        }
        else
        {
            resultNum += tmpNum[i];
        }
    }
    tmp = stoull(resultNum);
    if (tmp > endNum)
        return;
    else if(startNum <= tmp)
        answer++;


    //백트래킹
    for (int i = 0; i < v.size(); ++i)
    {
        currNum *= 10LL;
        currNum = currNum + v[i];
        recursion(depth + 1);
        currNum /= 10LL;
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> startNum >> endNum;
    if (0 >= startNum)
    {
        answer++;
    }
    for (int i = 1; i < v.size(); ++i)
    {
        currNum = v[i];
        recursion(1);
    }
    cout << answer;
    return 0;
}