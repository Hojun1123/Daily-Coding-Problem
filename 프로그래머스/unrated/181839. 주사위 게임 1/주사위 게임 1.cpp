#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    if(a & 1)
    {
        if(b & 1){
            return a*a + b*b;
        }
        else{
            return 2 * (a + b);
        }
    }
    else
    {
        if(b & 1){
            return 2 * (a + b);
        }
        else{
            return (a - b) > 0 ? a - b : b - a;
        }
    }
}