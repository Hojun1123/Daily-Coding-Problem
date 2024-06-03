#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
float M, N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << fixed;
    cout.precision(2);
    cin >> M >> N;

    float c = sqrt(N * N + M * M);
    float x = c - M;

    float h = (N * N - x * x) / (2 * N);
    float b = sqrt(M * M + h * h);
    
    float r1 = b / 2;
    float r2 = (N * M - h * M) / 2 / r1;
    
    cout << r1 << " " << r2;
    return 0;
 }