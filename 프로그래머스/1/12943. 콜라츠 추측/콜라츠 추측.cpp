#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int num) {
    if(num == 1)
        return 0;
    int cnt = 0;
    long n = num;
    while(cnt < 500)
    {
        if(n % 2)
        {
            n *= 3;
            n ++;
        }
        else
        {
            n /= 2;
        }
        cnt ++;
        if(n == 1)
            return cnt;
    }
    return -1;
}