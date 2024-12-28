#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int N, T, W, M;
typedef struct ct {
    int id;
    int t;
} ct;
//id(px)와 업무처리필요시간(tx)
//m명이 들어옴, px, tx, 영업시작(cx)에 들옴
// 대기 큐 맨 앞의 고객이 x번 손님, tx가 T보다 크다면?
typedef struct Queue {
    int front;
    int back;
    int size;
    ct data[400000];
} Queue;
void push(Queue* ptr, ct* dt)
{
    ptr->back = (ptr->back + 1) % 400000;
    ptr->data[ptr->back] = *dt;
    ptr->size++;
}
ct pop(Queue* ptr)
{
    if (ptr->size == 0) {
        printf("empty\n");
    }
    ct ret = ptr->data[ptr->front];
    ptr->front = (ptr->front + 1) % 400000;
    ptr->size--;
    return ret;
}
Queue q;
typedef struct input {
    int px, tx, cx;
} input;
input in[200000];
int compare(const void* a, const void* b)
{
    return ((input*)a)->cx > ((input*)b)->cx;
}
int ans[200000][2];
int main(int argc, char** argv)
{
    //q init
    q.back = -1;
    q.front = 0;
    q.size = 0;

    scanf("%d %d %d", &N, &T, &W);
    for (int i = 0; i < N; ++i) {
        ct tmp;
        scanf("%d %d", &tmp.id, &tmp.t);
        push(&q, &tmp);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        //px, tx, cx
        scanf("%d %d %d", &in[i].px, &in[i].tx, &in[i].cx);
    }
    qsort(in, M, sizeof(input), compare);

    int curr = 0;
    int index = 0;
    int ansidx = 0;
    while (curr < W)
    {
        ct now = pop(&q);
        //printf("%d: %d %d\n",curr ,now.id, now.t);
        ans[ansidx][0] = curr;
        ans[ansidx][1] = now.id;
        ansidx++;
        int push_flag = 0;
        if (now.t > T) {
            now.t -= T;
            curr += T;
            push_flag = 1;
        }
        else {
            curr += now.t;
        }

        // index...
        while (1) {
            if (index == M) break;
            if (in[index].cx > curr) break;
            ct nxt;
            nxt.id = in[index].px;
            nxt.t = in[index].tx;
            //printf("push: %d %d\n", curr, nxt.id);
            push(&q, &nxt);
            index++;
        }

        // push
        if (push_flag) {
            //printf("push: %d %d\n", curr, now.id);
            push(&q, &now);
        }
    }

    int cc = 0;
    for (int i = 0; i < ansidx - 1; ++i) {
        while (cc < ans[i + 1][0]) {
            printf("%d\n", ans[i][1]);
            cc++;
        }
    }
    while (cc < W) {
        printf("%d\n", ans[ansidx - 1][1]);
        cc++;
    }
    return 0;
}