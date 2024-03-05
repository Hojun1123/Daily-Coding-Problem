#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
int N, M;
int arr[100000];
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; ++i){
        cin >> arr[i];
    }
    int s = arr[0];
    int mLen = 111111;
    int l = 0;
    int r = 1;
    while(r <= N){
        if(s >= M){
            int len = r - l ;
            if(mLen > len)
            {
                mLen = len;
            }
            s -= arr[l];
            l++;
        }
        else
        {
            s += arr[r];
            r++;
        }
        if(r == l) {
            s += arr[r];
            r++;
        }
    }
    cout << (mLen == 111111 ? 0 : mLen);
    return 0;
}