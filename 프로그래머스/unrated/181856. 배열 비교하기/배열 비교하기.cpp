#include <string>
#include <vector>
#include <numeric>
using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int s1 = arr1.size();
    int s2 = arr2.size();
    if(s1 == s2)
    {
        s1 = accumulate(arr1.begin(), arr1.end(), 0);
        s2 = accumulate(arr2.begin(), arr2.end(), 0);
        return s1 > s2 ? 1 : (s1 < s2 ? -1 : 0);
    }
    return s1 > s2 ? 1 : -1;
}