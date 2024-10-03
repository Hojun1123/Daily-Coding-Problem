#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std; 
int N;
//10N개 층이 있음 0~
//N은 9보다 작거나 같음
//
long long numbers[10] = {
    0b111101101101111,
    0b001001001001001,
    0b111001111100111,
    0b111001111001111,
    0b101101111001001,
    0b111100111001111,
    0b111100111101111,
    0b111001001001001,
    0b111101111101111,
    0b111101111001111,
};
string arr[5];
vector<int> result[10];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < 5; ++i) {
        cin >> arr[i];
    }
    int jb = 0;
    for (int k = 0; k < N; ++k) {
        long long curr = 0;
        long long p = (1 << 14);
        for (int i = 0; i < 5; ++i) {
            for (int j = jb; j < jb + 3; ++j) {
                if (arr[i][j] == '#') {
                    curr |= p;
                }
                p = p >> 1;
            }
        }

        for (int n = 0; n < 10; ++n) {
            if ((numbers[n] | curr) == numbers[n]) {
                result[k].push_back(n);
            }
        }
        jb += 4;
    }

    double sum = 0;
    double pp = 1;
    long long cnt = 1;

    for (int i = N - 1; i >= 0; --i) {
        cnt *= result[i].size();
    }
    if (cnt == 0) {
        cout << -1;
        return 0;
    }
    for (int i = N - 1; i >= 0; --i) {
        for (int j : result[i]) {
            //cout << j << " ";
            sum = sum + (pp / result[i].size() * j);
        }
        pp *= 10;
    }
    //cout.precision(5);
    cout << fixed;
    cout << sum;
    return 0;
}