#include <string>
#include <vector>
#include <algorithm>
using namespace std;
long long solution(long long n) {
    long long answer = 0;
    vector<long long> a;
    while(n)
    {
        a.push_back(n % 10);
        n /= 10;
    }
    sort(a.begin(), a.end());
    int t = 1;
    for(int i = 0; i < a.size(); ++i)
    {
        answer += a[i] * t;   
        t *= 10;
    }
    return answer;
}