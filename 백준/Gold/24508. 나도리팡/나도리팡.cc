#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <regex>
using namespace std;
int N, K, T;
long long arr[100001];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K >> T;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    //N개의 바구니고 각 바구니에는 arr[i]
    //한마리를 다른 바구니로 옮김 T번.
    //모든 나도리들을 터트릴 수 있는가?
    sort(arr, arr + N);
    
    long long ss = 0;
    int left = 0;
    int right = N - 1;
    while (left < right) {
        long long diff = K - arr[right];
        if (diff <= arr[left]) {
            ss += diff;
            arr[left] -= diff;
            arr[right] += diff;
            right--;
        }
        else {
            ss += arr[left];
            arr[right] += arr[left];
            arr[left] = 0;
            left++;
        }

        //for (int i = 0; i < N; ++i) cout << arr[i] << " ";
    }
    if (ss > T) cout << "NO";
    else {
        for (int i = 0; i < N; ++i) {
            if (arr[i] == 0 || arr[i] == K) continue;
            cout << "NO"; return 0;
        }
        cout << "YES";
    }
    return 0;
}