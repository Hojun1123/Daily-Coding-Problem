#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int N;
typedef struct Node {
    int color;
    int childSize;
    int* child;
} Node;
Node arr[200000];
typedef struct Queue {
    int front;
    int back;
    int size;
    int data[200000];
}Queue;
int check[200000];
Queue q;
void push(int n)
{
    q.back = (q.back + 1) % 200000;
    q.data[q.back] = n;
    q.size++;
}
int pop()
{
    int ret = q.data[q.front];
    q.front = (q.front + 1) % 200000;
    q.size--;
    return ret;
}
int main(int argc, char** argv)
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i].color);
        arr[i].childSize = 0;
    }
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        arr[a].childSize++;
        arr[b].childSize++;
        arr[a].child = realloc(arr[a].child, sizeof(int) * arr[a].childSize);
        arr[b].child = realloc(arr[b].child, sizeof(int) * arr[b].childSize);
        *(arr[a].child + arr[a].childSize - 1) = b;
        *(arr[b].child + arr[b].childSize - 1) = a;
    }
    //init
    q.front = 0;
    q.back = -1;
    q.size = 0;

    //push
    push(0);
    check[0] = 1;

    int ans = (arr[0].color == 0) ? 0 : 1;
    while (q.size) {
        for (int i = 0; i < q.size; ++i) {
            int now = pop();
            //printf("%d ", now);
            for (int k = 0; k < arr[now].childSize; ++k) {
                int nxt = (arr[now].child[k]);
                if (check[nxt]) continue;
                if (arr[now].color != arr[nxt].color) {
                    ans++;
                }
                check[nxt] = 1;
                push(nxt);
            }
        }
    }
    printf("%d", ans);
    return 0;
}