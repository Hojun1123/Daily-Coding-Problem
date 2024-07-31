#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
int N;
struct Node {
    int day, score;
    bool operator<(Node o) const {
        if (score > o.score) return true;
        else if (score < o.score) return false;
        return day < o.day;
    }
};
vector<Node> v;
int check[1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    //d는 마감일까지 남을 일 수 , w는 과제의 점수
    for (int i = 0; i < N; ++i)
    {
        int d, s;
        cin >> d >> s;
        v.push_back({ d, s });
    }
    sort(v.begin(), v.end());
    int score = 0;
    for (int i = 0; i < N; ++i)
    {
        //3 -> 1, 2, 3
        Node curr = v[i];
        for (int k = curr.day; k > 0; k--)
        {
            if (check[k] == 0)
            {
                check[k] = 1;
                score += curr.score;
                break;
            }
        }
    }
    cout << score;
    return 0;
}