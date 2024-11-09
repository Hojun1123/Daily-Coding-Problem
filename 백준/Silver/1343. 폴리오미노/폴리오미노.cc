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
string a;
string b;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a;
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (cnt == 4) {
            b += "AAAA";
            cnt = 0;
        }
        if (a[i] == '.') {
            if (cnt == 2) {
                b += "BB";
                cnt = 0;
            }
            else if (cnt != 0) {
                cout << -1;
                return 0;
            }
            b += ".";
        }
        else if (a[i] == 'X') { 
            cnt++;
        }
    }
    if (cnt == 4) {
        cout << (b + "AAAA");
    }
    else if (cnt == 2) {
        cout << (b + "BB");
    }
    else if (cnt == 0) {
        cout << b;
    }
    else {
        cout << -1;
    }
    return 0;
}