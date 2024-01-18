#include<iostream>

#include<queue>

#include<string>

#include<vector>

#include<algorithm>

#include<stack>

#include<queue>

#include<map>

#include<sstream>

using namespace std;

int N;

priority_queue<int, vector<int>, greater<int>> q;

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    cin >> N;

    int input;

    for(int i = 0; i < N; ++i)

    {

        cin >> input;

        q.push(input);

    }

    int answer = 0;

    int subSum = q.top();

    int a, b;

    q.pop();

    q.push(subSum);

    while(q.size() != 1)

    {

        a = q.top();

        q.pop();

        b = q.top();

        q.pop();

        answer += a + b;

        q.push(a + b);

    }

    cout << answer;

    return 0;

}