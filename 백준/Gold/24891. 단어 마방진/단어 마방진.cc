#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int L, N;
string arr[20];
int check[20];
vector<string> result;
int rr = 0;
bool cc()
{
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < L; ++j) {
            if (result[i][j] != result[j][i]) return false;
        }
    }
    return true;
}
void bt(int index)
{
    if (rr) return;
    if (index == L) {
        /*
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << "\n";
        }
        cout << "\n";
        */
        if (cc()) {
            for (int i = 0; i < L; ++i) {
                cout << result[i] << "\n";
            }
            rr = 1;
        }
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (check[i]) continue;
        result.push_back(arr[i]);
        check[i] = 1;
        bt(index + 1);
        check[i] = 0;
        result.pop_back();
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> L >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    bt(0);
    if (!rr) cout << "NONE";
    return 0;
}