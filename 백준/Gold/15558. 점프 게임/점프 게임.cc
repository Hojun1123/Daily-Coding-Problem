#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N, K;
int check[2][200002];
string arr[2];
struct Node {
    int y, x;
};
queue<Node> q;
int main(int argc, char** argv)
{
    cin >> N >> K;
    cin >> arr[0] >> arr[1];
    check[0][0] = 0;
    q.push({ 0, 0 });
    int cnt = 0;
    while (!q.empty()) {
        arr[0][cnt] = arr[1][cnt] = '0';
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            Node now = q.front();
            q.pop();
            int y = now.y;
            int x = now.x - 1;
            if (x > 0 && check[y][x] == 0 && arr[y][x] != '0') {
                check[y][x] = 1;
                q.push({ y, x });
            }
            x = now.x + 1;
            if (x >= N) {
                cout << 1;
                return 0;
            }
            if (check[y][x] == 0 && arr[y][x] != '0') {
                check[y][x] = 1;
                q.push({ y, x });
            }
            x = now.x + K;
            y ^= 1;
            if (x >= N) {
                cout << 1;
                return 0;
            }
            if (check[y][x] == 0 && arr[y][x] != '0') {
                check[y][x] = 1;
                q.push({ y, x });
            }
        }
        cnt++;
    }
    cout << 0;
    return 0;
}