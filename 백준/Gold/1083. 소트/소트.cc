#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
int N, S;
int arr[50];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    cin >> S;
    
    for (int i = 0; i < N; ++i)
    {
        //for (int i = 0; i < N; ++i) cout << arr[i] << " "; cout << ": ";

        int maxIndex = i;
        for (int j = i + 1; (j - i) <= S && j < N; ++j)
        {
            if (arr[maxIndex] < arr[j])
            {
                maxIndex = j;
            }
        }
        int tmp = arr[maxIndex];
        for (int j = maxIndex - 1; j >= i; --j) {
            arr[j + 1] = arr[j];
        }
        arr[i] = tmp;
        S -= (maxIndex - i);
        //cout << S << "\n";
    }
    for (int i = 0; i < N; ++i) cout << arr[i] << " ";
    return 0;
}