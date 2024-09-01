#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;
int N, M;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string input;
    string arr[3];
    while (true) {
        cin >> input;
        if (input == "end") break;
        for (int i = 0; i < 3; i ++) {
            arr[i] = input.substr(i * 3, 3);
        }
        //1
        int ot = 0;
        int xt = 0;
        int _ = 0;
        for (int i = 0; i < 9; i++) {
            if (input[i] == 'O')ot++;
            else if (input[i] == 'X')xt++;
            else _++;
        }
        if (ot > xt) {
            cout << "invalid\n";
            continue;
        }
        if (ot + 1 < xt) {
            cout << "invalid\n";
            continue;
        }

        int o = 0;
        int x = 0;
        for (int i = 0; i < 3; ++i) {
            if (arr[i][0] != '.')
            {
                if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) {
                    if (arr[i][0] == 'O') o++;
                    else if (arr[i][0] == 'X') x++;
                }

            }
        }
        
        for (int i = 0; i < 3; ++i) {
            if (arr[0][i] != '.')
            {
                if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i]) {
                    if (arr[0][i] == 'O') o++;
                    else if (arr[0][i] == 'X') x++;
                }

            }
        }

        if (arr[0][0] != '.') {
            if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) {
                if (arr[0][0] == 'O') o++;
                else if (arr[0][0] == 'X') x++;
            }
        }

        if (arr[0][2] != '.') {
            if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]) {
                if (arr[0][2] == 'O') o++;
                else if (arr[0][2] == 'X') x++;
            }
        }
        //cout << "o: " << o << ", " << "x: " << x << " ";
        if (o > 0 && x > 0) {
            cout << "invalid\n";
        }
        else if (o > 0) {
            if (ot < xt) cout << "invalid\n";
            else cout << "valid\n";
        }
        else if (x > 0) {
            if (ot == xt) cout << "invalid\n";
            else cout << "valid\n";
        }
        else if (_ > 0 ){
            cout << "invalid\n";
        }
        else {
            cout << "valid\n";
        }

    }
}