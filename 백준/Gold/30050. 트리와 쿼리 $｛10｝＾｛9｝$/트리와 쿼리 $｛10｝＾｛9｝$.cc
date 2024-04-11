#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
using namespace std;
unordered_map<int, int> parentNode;
map<int, int> um;
int N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // 루트의 번호가 1, 정점의 개수가 무한. 포화 이진 트리
    // 50,000 이면, NlongN?
    // 1 a b , b번 정점과 그 부모를 잇는 간선을 제거.
    // 2 c d , c번 정점에서 d번 정점으로 가는 
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            //원래 부보는 부모 * 2 , 부모 * 2 + 1
            parentNode[c] = b;
        }
        else
        {
            int curr = b;
            long long result = 0;
            um.clear();
            //cout << um.size() << "\n";
            while (true)
            {
                um[curr]++;
                if (parentNode.find(curr) != parentNode.end())
                {
                    curr = parentNode[curr];
                }
                else
                {
                    curr /= 2;
                }
                if (curr == 0) break;
            }

            curr = c;
            while (true)
            {
                um[curr]++;
                if (parentNode.find(curr) != parentNode.end())
                {
                    curr = parentNode[curr];
                }
                else
                {
                    curr /= 2;
                }
                if (curr == 0) break;
            }
            int maxv = -1;
            for (map<int, int>::iterator k = um.begin(); k != um.end(); ++k)
            {
                if (k->second == 1)
                {
                    result = result + k->first;
                }
                else if (k->second == 2) {
                    maxv = k->first;
                }
            }
            cout << result + maxv << "\n";
        }
    }
    return 0;
}
