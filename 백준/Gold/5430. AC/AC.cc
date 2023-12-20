#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <numeric>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;
int T;
string p;
int n;
string arr;

int q[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> p;
        cin >> n;
        cin >> arr;

        int left = 0;
        int right = 0;
        string buffer;
        istringstream is(arr.substr(1, arr.size() - 2));
        while (getline(is, buffer, ','))
        {
            q[right] = stoi(buffer);
            right += 1;
        }

        int reverseFlag = 0;
        int checkError = 0;
        for (int j = 0; j < p.size(); ++j)
        {
            if (p[j] == 'D')
            {
                if (left == right)
                {
                    checkError = 1;
                    break;
                }
                else
                {
                    if (reverseFlag)
                        right -= 1;
                    else
                        left += 1;
                }
            }
            else
            {
                reverseFlag ^= 1;
            }
        }

        if (checkError)
        {
            cout << "error\n";
        }
        else
        {
            cout << "[";
            if (reverseFlag)
            {
                for (int k = right - 1; k >= left; k--)
                {
                    cout << q[k] << ((k == left) ? "" : ",");
                }
            }
            else
            {
                for (int k = left; k < right; k++)
                {
                    cout << q[k] << ((k == right - 1) ? "" : ",");
                }
            }
            cout << "]";
            if (i != T - 1)
                cout << "\n";
        }


    }
    return 0;
}

