#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
int N, M;
float answer[201][201];   //플로이드 위셜 정답 배열    
float m[201];    //key로부터 다른 N 개의 정점을 갈 때, 가장 멀리 가능 경우의 거리
struct d {
    int a;
    int b;
    int c;
};
vector<d> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    // 정답 배열 초기화
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (i == j) {
                answer[i][j] = 0;
                continue;
            }
            answer[i][j] = 987654321;
        }
    }

    // 간선 입력 받기, 시작점과 출발점이 같은 노드가 여러개임을 고려
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({ a, b, c });
        if (answer[a][b] < c) continue;
        answer[a][b] = c;
        answer[b][a] = c;
    }

    // 플로이드-위셜
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            for (int k = 1; k <= N; ++k)
            {
                if (answer[j][i] + answer[i][k] >= answer[j][k]) continue;
                answer[j][k] = answer[j][i] + answer[i][k];
            }
        }
    }

    // 각 정점에 대해 모든 경우를 계산
    float minTime = 987654321;
    for (int start = 1; start <= N; ++start)
    {
        // 해당 경우에 대해 걸리는 모든 그래프를 태우는 시간(가장 긴 시간 = 총 걸리는 시간)
        float maxTime = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            //하나의 간선에 대해 양 끝점에 각각 도달하는 시간a , b
            float a = answer[start][v[i].a];
            float b = answer[start][v[i].b];
            float result;

            // 각 경우에 따라 소요 시간 계산
            if (a > b)
            {
                if (v[i].c > a - b)
                {
                    // 다른 한 끝점에 도달 시간 보다 간선이 짧은 경우
                    result = a + float(v[i].c - (a - b)) / 2.0;
                }
                else
                {
                    result = b + v[i].c;
                }
            }
            else if (a < b)
            {
                if (v[i].c > b - a)
                {
                    // 다른 한 끝점에 도달 시간 보다 간선이 짧은 경우
                    result = b + float(v[i].c - (b - a)) / 2.0;
                }
                else
                {
                    result = a + v[i].c;
                }
            }
            else
            {
                // 같은 경우 a == b
                result = a + v[i].c / 2.0;
            }

            if (result > maxTime)
            {
                maxTime = result;
            }
        }
        if (minTime > maxTime)
            minTime = maxTime;
    }
    cout << fixed;
    cout.precision(1);
    cout << minTime;
    return 0;
}