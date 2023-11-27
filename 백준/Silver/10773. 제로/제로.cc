#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int temp;
    vector<int> result;
    for (int i = 0; i < T; ++i)
    {
        cin >> temp;
        if (temp != 0)
            result.push_back(temp);
        else
            result.pop_back();
    }
    cout << accumulate(result.begin(), result.end(), 0);
    return 0;
}