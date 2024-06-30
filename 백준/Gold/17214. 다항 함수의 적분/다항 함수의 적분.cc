#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a;
    int num = 1;
    int i = 0;
    string tmp;
    while (i < a.size() && a[i] != 'x') tmp += a[i++];
    if (i == a.size()) {
        if (a == "1") {
            cout << "x+W";
        }
        else if (a == "-1") {
            cout << "-x+W";
        }
        else if (a == "0") {
            cout << "W";
        }
        else {
            cout << a << "x+W";
        }
    }
    else {
        int itmp = stoi(tmp) / 2;
        if (itmp == 1) {
            b += "xx";
        }
        else if (itmp == -1) {
            b += "-xx";
        }
        else {
            b += to_string(itmp) + "xx";
        }

        if (++i != a.size())
        {
            b += a[i++];
            tmp = a.substr(i, a.size());
            if (tmp == "1") {
                b += "x";
            }
            else if (tmp == "-1") {
                b += "-x";
            }
            else {
                b += tmp + "x";
            }
        }
        b += "+W";
        cout << b;
    }
    return 0;
}