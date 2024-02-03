#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
using namespace std;
int N, K;
vector<int> input;
struct d {
    int n;  // 숫자 (1 억 이하 양의 정수) 
    int seq;    // 입력된 순서(Index)

    //우선순위 큐를 위한 연산자 오버로딩
    bool operator<(d other) const {
        if (n < other.n) return false;
        else if (n > other.n) return true;
        return false;
    }
};
struct dd {
    int n;  // 숫자 (1 억 이하 양의 정수) 
    string s;   // 해당 숫자 이하면 출력할 칭호
};
priority_queue<d> pq;
queue<dd> q;
string answer[100000];  //출력할 정답
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> K;
    string a;
    int b;
    //입력 값을 큐에 (칭호, 기준전투력) 로 입력
    for (int i = 0; i < N; ++i)
    {
        cin >> a >> b;
        q.push({ b, a});
    }

    //입력 값을 힙큐에 (전투력, index) 로 입력
    for (int i = 0; i < K; ++i)
    {
        cin >> b;
        pq.push({ b, i});
    }

    
    while (!pq.empty())
    {
        int nowNum = pq.top().n;
        if (nowNum <= q.front().n)
        {
            //현재 뽑은 전투력이 현재 칭호의 전투력 이하이면
            answer[pq.top().seq] = q.front().s;
        }
        else
        {
            //현재 뽑은 전투력이 현재 칭호의 전투력보다 크면, 만족하는 범위까지 큐를 pop
            while (true)
            {
                q.pop();
                if (nowNum <= q.front().n)
                    break;
            }
            answer[pq.top().seq] = q.front().s;
        }
        pq.pop();
    }

    //출력 순서에 맞게 정답 출력
    for(int i = 0; i < K; ++i)
        cout << answer[i] << "\n";
    return 0;
}