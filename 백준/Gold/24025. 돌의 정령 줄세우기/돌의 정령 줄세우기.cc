#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
// 1 ~ N 까지의 서로 다른 키를 가진 정령이 있음.!
// 민약 키가 큰 돌의 정령 너머를 못봄
// i번째 돌의 정령이 j번째 돌의 정령 무리까지 볼 수 있다면 시야 점수는 j-i
// 앞에 없으면 시야점수는 10의 9승
int N;
int arr[70077];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    if (arr[N - 1] < 0) {
        cout << -1;
        return 0;
    }
    int num = 0;
    int num2 = -1;
    for (int i = N - 1; i >= 0; --i) {
        //뒤에서부터하나?
        if (arr[i] >= 0) {
            arr[i] = num++;
        }
        else {
            arr[i] = num2--;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << arr[i] - num2 << " ";
    }
    return 0;
}