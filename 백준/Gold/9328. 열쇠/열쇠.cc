#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#include <unordered_map>
#include <cstring>
using namespace std;
int T, N, M;
string arr[100];
unordered_map<char, bool> keys;
int dy[4] = { 1, -1, 0 ,0 };
int dx[4] = { 0, 0, 1, -1 };
struct yx { int y, x; };
queue<yx> q;
int check[100][100];
int toUpper = 'a' - 'A';
vector<yx> closedDoors[100];
int score = 0;
void bfs(yx curr) {
    for (int i = 0; i < 4; ++i)
    {
        int y = dy[i] + curr.y;
        int x = dx[i] + curr.x;
        if (x < 0 || y < 0 || x >= M || y >= N) continue;
        if (check[y][x]) continue;
        char c = arr[y][x];
        check[y][x] = 1;
        if (c == '.') {
            q.push({ y, x });
        }
        else if (c <= 'Z' && c >= 'A') {
            if (keys[c]) {
                q.push({ y, x });
            }
            else {
                closedDoors[c].push_back({ y, x });
            }
        }
        else if (c <= 'z' && c >= 'a') {
            q.push({ y, x });
            char lc = c - toUpper;
            keys[lc] = 1;
            if (closedDoors[lc].size() > 0)
            {
                for (yx j : closedDoors[lc]) {
                    check[j.y][j.x] = 1;
                    q.push(j);
                }
            }
        }
        else if (c == '$') {
            score++;
            q.push({ y, x });
        }
    }
}
void findEnter()
{
    for (int i = 0; i < N; ++i)
    {
        check[i][0] = 1;
        check[i][M - 1] = 1;
        char curr1 = arr[i][0];
        char curr2 = arr[i][M - 1];
        if (curr1 == '.') {
            q.push({ i, 0 });
        }
        else if (curr1 <= 'Z' && curr1 >= 'A'){
            if (keys[curr1]) {
                q.push({ i, 0 });
            }
            else {
                closedDoors[curr1].push_back({i, 0});
            }
        }
        else if (curr1 <= 'z' && curr1 >= 'a') {
            q.push({ i, 0 });
            char lc = curr1 - toUpper;
            keys[lc] = 1;
            if (closedDoors[lc].size() > 0)
            {
                for (yx j : closedDoors[lc]) {
                    check[j.y][j.x] = 1;
                    q.push(j);
                }
            }
        }
        else if(curr1 == '$'){
            score++;
            q.push({ i, 0 });
        }

        if (curr2 == '.') {
            q.push({ i, M - 1 });
        }
        else if (curr2 <= 'Z' && curr2 >= 'A') {
            if (keys[curr2]) {
                q.push({ i, M - 1 });
            }
            else {
                closedDoors[curr2].push_back({ i, M - 1 });
            }
        }
        else if (curr2 <= 'z' && curr2 >= 'a') {
            q.push({ i, M - 1 });
            char lc = curr2 - toUpper;
            keys[lc] = 1;
            if (closedDoors[lc].size() > 0)
            {
                for (yx j : closedDoors[lc]) {
                    check[j.y][j.x] = 1;
                    q.push(j);
                }
            }
        }
        else if (curr2 == '$') {
            score++;
            q.push({ i, M - 1 });
        }
    }

    for (int j = 1; j < M - 1; ++j)
    {
        check[0][j] = 1;
        check[N - 1][j] = 1;
        char curr1 = arr[0][j];
        char curr2 = arr[N - 1][j];
        if (curr1 == '.') {
            q.push({ 0, j });
        }
        else if (curr1 <= 'Z' && curr1 >= 'A') {
            if (keys[curr1]) {
                q.push({ 0, j });
            }
            else {
                closedDoors[curr1].push_back({ 0, j });
            }
        }
        else if (curr1 <= 'z' && curr1 >= 'a') {
            q.push({ 0, j });
            char lc = curr1 - toUpper;
            keys[lc] = 1;
            if (closedDoors[lc].size() > 0)
            {
                for (yx i : closedDoors[lc]) {
                    check[i.y][i.x] = 1;
                    q.push(i);
                }
            }
        }
        else if (curr1 == '$') {
            score++;
            q.push({ 0, j });
        }

        if (curr2 == '.') {
            q.push({ N - 1, j });
        }
        else if (curr2 <= 'Z' && curr2 >= 'A') {
            if (keys[curr2]) {
                q.push({ N - 1, j });
            }
            else {
                closedDoors[curr2].push_back({ N - 1, j });
            }
        }
        else if (curr2 <= 'z' && curr2 >= 'a') {
            q.push({ N - 1, j });
            char lc = curr2 - toUpper;
            keys[lc] = 1;
            if (closedDoors[lc].size() > 0)
            {
                for (yx i : closedDoors[lc]) {
                    check[i.y][i.x] = 1;
                    q.push(i);
                }
            }
        }
        else if (curr2 == '$') {
            score++;
            q.push({ N - 1, j });
        }
    }
}
void solve()
{
    keys.clear();
    score = 0;
    q = queue<yx>();
    memset(check, 0, sizeof(check));
    for (int i = 'A'; i <= 'Z'; ++i) closedDoors[i].clear();
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    string input;
    cin >> input;
    for (int i = 0; i < input.size() && input[0] != '0'; ++i) {
        keys[input[i] - toUpper] = true;
    }
    findEnter();

    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            bfs(q.front());
            q.pop();
        }
    }
    cout << score << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for(int i = 0; i < T; ++i)
        solve();
    return 0;
}