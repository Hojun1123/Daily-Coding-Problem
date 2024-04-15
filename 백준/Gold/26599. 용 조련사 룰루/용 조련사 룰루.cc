#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <cstring>
#include <sstream>
using namespace std;
int N, M;
struct Dragon {
    int n;
    int power;
    bool operator<(Dragon o) const {
        return power > o.power;
    }
};
vector<Dragon> dragon;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        dragon.push_back({ i, a });
    }
    //붙어있는 값들은 최소 차이.
    //가장 큰용과 두번 째 큰 용의 차이는 M 이하임이 보장됨
    //각 장소에 가장 큰용과 두번 째 큰 용 차이가 M 이하이면 어떻게되든 가능
    //세번째 용을 먼저 이동.
    //작은용을 먼저 옮기면...?
    //큰용 두마리를 두자. 1, 2를 먼저 옮기고? 
    //0 10 20 30 40 , 각 간격차이가 M 이하면

    // 1 2 3, 2 1 3, 3 1 2

    sort(dragon.begin(), dragon.end());
    if (N <= 2) {
        cout << "YES\n";
        for (int i = 1; i <= N; ++i) cout << i << " ";
    }
    else if (N == 3) {
        if (dragon[1].power - dragon[2].power <= M) {
            cout << "YES\n";
            for (int i = 0; i < N; ++i) cout << dragon[i].n << " ";
        }
        else {
            cout << "NO";
        }
    }
    else {
        int prev = dragon[0].power;
        bool result = true;
        for (int i = 1; i < 4; ++i) {
            int diff = prev - dragon[i].power;
            prev = dragon[i].power;
            if (diff > M) result = false;
        }
        if (result) {
            cout << "YES\n";
            cout << dragon[2].n << " " << dragon[3].n << " ";
            for (int i = 4; i < N; ++i) cout << dragon[i].n << " ";
            cout << dragon[1].n << " " << dragon[0].n << " ";
        }
        else {
            cout << "NO";
        }
    }
    return 0;
}