#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
//NxN개의 정사각형 구역으로 이루어진 정사각형 ㅁ모양의 게임판이 세워져있음
//각각의 구역은 비어있거나 벽으로 이루어져 있고, 빈 구역 중 하나에는 공이 놓여있음
//벽이나 게임판의 바닥에 있음
int N, K;
string arr[1000];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    int sy, sx;
    int sd = 0;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        for (int j = 0; j < N; ++j) {
            if (arr[i][j] == 'L') {
                sy = i;
                sx = j;
                arr[i][j] = '.';
            }
        }
    }
    for (int i = 0; i < K; ++i) {
        char input;
        cin >> input;
        if (input == 'D') {
            ++sd;
            if (sd == 4) sd = 0;
        }
        else {
            --sd;
            if (sd == -1) sd = 3;

        }
        while (true) {
            int y = sy + dy[sd];
            int x = sx + dx[sd];
            if (x < 0 || y < 0 || x >= N || y >= N) break;
            if (arr[y][x] == 'X') break;
            sy = y;
            sx = x;
            //cout << sy << ", " << sx << "\n";
        }
    }

    if (sd == 3) {
        for (int i = N - 1; i >= 0; --i) {
            for (int j = 0; j < N; ++j) {
                if (i == sx && j == sy) {
                    cout << 'L';
                }
                else {
                    cout << arr[j][i];
                }
            }
            cout << "\n";
        }
    }
    else if (sd == 2) {
        for (int i = N - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (i == sy && j == sx) {
                    cout << 'L';
                }
                else {
                    cout << arr[i][j];
                }
            }
            cout << "\n";
        }
    }
    else if (sd == 1) {
        for (int i = 0; i < N; ++i) {
            for (int j = N - 1; j >= 0; --j) {
                if (i == sx && j == sy) {
                    cout << 'L';
                }
                else {
                    cout << arr[j][i];
                }
            }
            cout << "\n";
        }
    }
    else {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == sy && j == sx) {
                    cout << 'L';
                }
                else {
                    cout << arr[i][j];
                }
            }
            cout << "\n";
        }
    }
    return 0;
}