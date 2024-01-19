#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
int N, K;
int arr[100][100];
int temp[100][100];
int dx[4] = { 1, -1, 0 ,0 };
int dy[4] = { 0, 0, 1, -1 };
int answer = 0;
void print();
void p1();
void p2();
void p3();
void p4();
void p5();
int p6();
void print()
{
    for (int i = N; i >=0; --i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << arr[i][j] << "  ";
        }
        cout << "\n";
    }
}
void p1()
{
    vector<int> minValueIndex;
    int minValue = 10000000;
    for (int i = 0; i < N; ++i)
    {
        if (minValue > arr[0][i])
        {
            minValueIndex = vector<int>();
            minValue = arr[0][i];
            minValueIndex.push_back(i);
        }
        else if (minValue == arr[0][i])
        {
            minValueIndex.push_back(i);
        }
    }
    for (int i = 0; i < minValueIndex.size(); ++i)
    {
        arr[0][minValueIndex[i]] += 1;
    }
}
void p2()
{
    int w = 1;
    int h = 1;
    int step = 1;
    int index = 0;
    while (index + w + h <= N)
    {
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                //cout << "(" << w - j << "," << index + w + i << ")" << " ";
                arr[w - j][index + w + i] = arr[i][index + j];
                arr[i][index + j] = 0;
            }
        }
        index += w;
        if (step % 2)
        {
            h++;
        }
        else {
            w++;
        }
        step++;
    }

    for (int i = 0; i < N - index; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            arr[j][i] = arr[j][i + index];
            arr[j][i + index] = 0;
        }
    }
}
void p3()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            temp[i][j] = 0;
        }
    }

    int y, x;
    int sub;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (arr[i][j] > 0)
            {
                for (int k = 0; k < 4; ++k)
                {
                    y = dy[k] + i;
                    x = dx[k] + j;
                    if (x >= 0 && x < N && y >= 0 && y < N && arr[y][x] > 0)
                    {
                        sub = arr[i][j] - arr[y][x];
                        if (sub > 0)
                        {
                            sub /= 5;
                            temp[i][j] -= sub;
                            temp[y][x] += sub;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            arr[i][j] += temp[i][j];
        }
    }
}
void p4()
{
    queue<int> arr1D;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (arr[j][i] > 0)
            {
                arr1D.push(arr[j][i]);
                arr[j][i] = 0;
            }
        }
    }

    int i = 0;
    while (!arr1D.empty())
    {
        arr[0][i++] = arr1D.front();
        arr1D.pop();
    }
}
void p5()
{
    queue<int> arr1D;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (arr[j][i] > 0)
            {
                arr1D.push(arr[j][i]);
                arr[j][i] = 0;
            }
        }
    }
    int div4 = N / 4;
    while (!arr1D.empty())
    {
        for (int i = 0; i < div4; ++i)
        {
            arr[1][div4 - 1 - i] = arr1D.front();
            arr1D.pop();
        }
        for (int i = 0; i < div4; ++i)
        {
            arr[2][i] = arr1D.front();
            arr1D.pop();
        }
        for (int i = 0; i < div4; ++i)
        {
            arr[3][div4 - 1 - i] = arr1D.front();
            arr1D.pop();
        }
        for (int i = 0; i < div4; ++i)
        {
            arr[0][i] = arr1D.front();
            arr1D.pop();
        }
    }
}
int p6()
{
    int minValue = 10000000;
    int maxValue = 0;
    for (int i = 0; i < N; ++i)
    {
        if (arr[0][i] < minValue)
            minValue = arr[0][i];
        if (arr[0][i] > maxValue)
            maxValue = arr[0][i];
    }
    if (maxValue - minValue <= K)
        return 1;
    return 0;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[0][i];
    }
    while (true)
    {
        if(p6())
        {
            break;
        }
        answer++;
        p1();   // 가장 작은 어항에 물고기 + 1
        p2();   // 공중부양작업
        p3();   // 물고기 수 조절
        p4();   // 어항을 다시 일렬로 배치
        p5();   // 공중부양작업2
        p3();   // 물고기 수 조절
        p4();   // 어항을 다시 일렬로 배치
    }
    cout << answer;
    return 0;
}