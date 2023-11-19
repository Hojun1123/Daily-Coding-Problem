#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    int temp;
    for(int i = 1; i <= int(sqrt(n)); i++)
    {
        if(n % i == 0)
        {
            temp = n/i;
            if(n/i == i)
                answer -= i;
            answer += i + n/i;
        }
    }
    return answer;
}