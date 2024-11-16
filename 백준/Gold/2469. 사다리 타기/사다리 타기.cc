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
int K, N;
string result;
string arr[1001];
int ret1[30];
int ret2[30];
int ans[30];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> K >> N;
    cin >> result;
    int br = 0;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        if (arr[i][0] == '?') br = i;
    }
    //0~br - 1
    for (int idx = 0; idx < K; ++idx) {
        int start = idx;
        for (int i = 0; i < br; ++i) {
            if (start - 1 >= 0 && arr[i][start - 1] == '-') {
                start--;
            }
            else if (start < K - 1 && arr[i][start] == '-') {
                start++;
            }
        }
        ret1[idx] = start;
    }
    //br + 1 ~ N
    for (int idx = 0; idx < K; ++idx) {
        int start = idx;
        for (int i = N - 1; i > br; --i) {
            if (start - 1 >= 0 && arr[i][start - 1] == '-') {
                start--;
            }
            else if (start < K - 1 && arr[i][start] == '-') {
                start++;
            }
        }
        ret2[result[idx] - 'A'] = start;
    }
    //for (int i = 0; i < K - 1; ++i) cout << ret1[i] << " "; cout << "\n";
    //for (int i = 0; i < K - 1; ++i) cout << ret2[i] << " "; cout << "\n";
    int ff = 0;
    for (int i = 0; i < K; ++i) {
        if (ret1[i] == ret2[i]) {
            if (ret1[i] - 1 >= 0) {
                if (ans[ret1[i] - 1] == 1) {
                    ff = 1;
                }
                ans[ret1[i] - 1] = 2;
            }
            if (ans[ret1[i]] == 1) ff = 1;
            ans[ret1[i]] = 2;
        }
        else if (ret1[i] - 1 == ret2[i]) {
            if (ret1[i] - 1 >= 0) {
                if (ans[ret1[i] - 1] == 2) {
                    ff = 1;
                }
                ans[ret1[i] - 1] = 1;
            }
        }
        else if(ret1[i] + 1 == ret2[i]) {
            if (ans[ret1[i]] == 2) ff = 1;
            ans[ret1[i]] = 1;
        }
        else {
            ff++;
        }
    }
    for (int i = 1; i < K - 1; ++i) {
        if (ans[i - 1] == 1 && ans[i] == 1) {
            ff = 1;
        }
    }
    if (ff) {
        for (int k = 0; k < K - 1; ++k) cout << "x";
    }
    else {
        for (int i = 0; i < K - 1; ++i) {
            cout << (ans[i] == 1 ? "-" : "*");
        }
    }
    return 0;
}