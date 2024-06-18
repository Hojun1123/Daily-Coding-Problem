#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;
int isYet[200001];
int isVisited[200001];
vector<int> graph[200001];
queue<int> q;
unordered_map<int, int> m;
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    memset(isYet, -1, sizeof(isYet));
    for(int i = 0; i < order.size(); ++i)
    {
        int a = order[i][0];
        int b = order[i][1];
        isYet[b] = a;
    }
    for(int i = 0; i < path.size(); ++i)
    {
        int a = path[i][0];
        int b = path[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    q.push(0);
    isVisited[0] = 1;
    if(isYet[0] != -1) return false;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int k = 0; k < graph[now].size(); ++k)
        {
            int nxt = graph[now][k];
            if(isVisited[nxt]) continue;
            if(isYet[nxt] == -1){
                q.push(nxt);
                isVisited[nxt] = 1;
            }
            else{
                if(isVisited[isYet[nxt]]){
                    q.push(nxt);
                    isVisited[nxt] = 1;
                    isYet[nxt] = -1;
                }
                else{
                    m[isYet[nxt]] = nxt;
                    isVisited[nxt] = 1;
                }
            }
        }
        if(m.find(now) != m.end())
        {
            q.push(m[now]);
        }
    }
    
    for(int i = 0; i < n; ++i)
    {
        if(isVisited[i]) continue;
        return false;
    }
    return true;
}