#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int inputSize;
    string word;
    cin >> inputSize;
    int answer = 0;
    for (int i = 0; i < inputSize; ++i)
    {
        int table[26];
        for (int j = 0; j < 26; ++j)
            table[j] = 0;

        cin >> word;
        int prevA = word[0];
        int currA;
        for (int j = 0; j < word.size(); ++j)
        {
            currA = word[j];
            if (prevA != currA && table[currA - 'a'] == 1)
            {
                answer -= 1;
                break;
            }
            table[currA - 'a'] = 1;
            prevA = currA;
        }
        answer += 1;
    }

    cout << answer;
    return 0;
}