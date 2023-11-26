#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int arr[200];
int solution(vector<vector<int>> lines) {
    int answer = 0;
    int left = 200;
    int right = 0;
    
    for(int i = 0; i < 3; ++i)
    {
        int start = lines[i][0] + 100;
        int end = lines[i][1] + 100;
        if(left > start)
            left = start;
        if(right < end)
            right = end;
        
        for(int j = start; j < end; ++j)
        {
            arr[j] += 1;   
        }
    }
    
    for(int i = left; i < right; ++i)
    {
        if(arr[i] > 1)
            answer += 1;
    }       
    return answer;
}