#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    double a = sqrt(n);
    long long b = a;
    if(a == (double)b)
        return (b + 1) * (b + 1);
    return -1;
}