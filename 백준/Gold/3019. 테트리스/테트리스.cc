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
using namespace std;
int N, C;
int arr[100];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> C >> N;
    for (int i = 0; i < C; ++i)
        cin >> arr[i];
    // C열, 행은 무한대, 7개의 블럭
    int cnt = 0;
    if (N == 1) {
        cnt += C;
        for (int i = 3; i < C; ++i) {
            if (arr[i] == arr[i - 1] && arr[i - 1] == arr[i - 2]
                && arr[i - 2] == arr[i - 3]) {
                cnt++;
            }
        }
    }
    else if(N == 2) {
        for (int i = 1; i < C; ++i) {
            if (arr[i] == arr[i - 1]) {
                cnt++;
            }
        }
    }
    else if (N == 3) {
        for (int i = 2; i < C; ++i) {
            if (arr[i - 1] == arr[i - 2] && arr[i - 1] == arr[i] - 1) {
                cnt++;
            }
        }
        for (int i = 1; i < C; ++i) {
            if (arr[i - 1] - 1 == arr[i]) {
                cnt++;
            }
        }
    }
    else if (N == 4) {
        for (int i = 2; i < C; ++i) {
            if (arr[i] == arr[i - 1] && arr[i - 1] == arr[i - 2] - 1) {
                cnt++;
            }
        }
        for (int i = 1; i < C; ++i) {
            if (arr[i] - 1 == arr[i - 1]) {
                cnt++;
            }
        }
    }
    else if (N == 5) {
        for (int i = 2; i < C; ++i) {
            if (arr[i] == arr[i - 1] && arr[i - 1] == arr[i - 2]) {
                cnt++;
            }
            if (arr[i] - 1 == arr[i - 1] && arr[i - 2] - 1 == arr[i - 1]) {
                cnt++;
            }
        }
        for (int i = 1; i < C; ++i) {
            if (arr[i] == arr[i - 1] - 1) cnt++;
            if (arr[i] - 1 == arr[i - 1]) cnt++;
        }
    }
    else if (N == 6) {
        for (int i = 2; i < C; ++i) {
            if (arr[i] == arr[i - 1] && arr[i - 1] == arr[i - 2]) cnt++;
            if (arr[i - 2] == arr[i - 1] - 1 && arr[i - 1] == arr[i]) cnt++;
        }
        for (int i = 1; i < C; ++i) {
            if (arr[i] == arr[i - 1])cnt++;
            if (arr[i - 1] - 2 == arr[i]) cnt++;
        }
    }
    else if (N == 7) {
        for (int i = 2; i < C; ++i) {
            if (arr[i] == arr[i - 1] - 1 && arr[i - 1] == arr[i - 2]) cnt++;
            if (arr[i] == arr[i - 1] && arr[i - 1] == arr[i - 2]) cnt++;
        }
        for (int i = 1; i < C; ++i) {
            if (arr[i] == arr[i - 1])cnt++;
            if (arr[i - 1] == arr[i] - 2) cnt++;
        }
    }
    cout << cnt;
    return 0;
}