#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(int x) {
    int a = x;
    int s = 0;
    while(a)
    {
        s += a % 10;
        a /= 10;
    }
    if(x % s == 0)
        return true;
    return false;
}