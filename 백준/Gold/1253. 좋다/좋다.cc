#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <deque>
#include <map>
#include <vector>
#include <sstream>
using namespace std;
int N;
int arr[2000];
vector<int> v;
int cnt = 0;
struct Node {
    int aIndex, bIndex;
};
Node arrIndex[2222222];
bool bs(int n)
{
    int left = 0;
    int right = v.size() - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (v[mid] == n) return true;
        else if (v[mid] > n)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return false;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    } 
    sort(arr, arr + N);
    for(int i = 0; i < N; ++i)
    {
        int num = arr[i];
        int left = 0;
        int right = N - 1;
        while (left < right)
        {
            int curr = arr[left] + arr[right];
            if (curr == num)
            {
                if (left != i && right != i)
                {
                    cnt++;
                    break;
                }
                else if (left == i)
                {
                    left++;
                }
                else if(right == i)
                {
                    right--;
                }
            }
            else if (curr > num)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }
    cout << cnt;
    return 0;
}