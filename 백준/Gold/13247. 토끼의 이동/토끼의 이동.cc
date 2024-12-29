#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int N;
//휜검빨 중 1
//토끼의 이동
//r마리의 토끼가 모이고 칸은 무작위
//0번칸에 있는 토끼는 0 -> 1
//size -1, -2 는 왼쪽으로
//
//N 2 ~ 17
char str[17];
int state[17];
int str_size;
double divnum = 0;
double snum = 0;
void sim()
{
    int curr[17][17];
    memset(curr, 0, sizeof(curr));
    memcpy(curr[0], state, sizeof(state));
    int curr_size = str_size;
    int idx = 0;
    //for (int i = 0; i < curr_size; ++i) printf("%d", curr[0][i]);
    while (curr_size > 2)
    {
        curr[idx + 1][1] |= curr[idx][0];
        curr[idx + 1][curr_size - 2] |= curr[idx][curr_size - 1];
        curr[idx + 1][curr_size - 3] |= curr[idx][curr_size - 2];
        
        for (int i = 1; i < curr_size - 2; ++i) {
            if (str[i] == 'W') {
                curr[idx + 1][i - 1] |= curr[idx][i];
            }
            else if (str[i] == 'B') {
                curr[idx + 1][i + 1] |= curr[idx][i];
            }
            else {
                if (idx == 0) {
                    curr[idx + 1][i - 1] |= curr[idx][i];
                }
                else {
                    if (curr[idx - 1][i - 1] & curr[idx][i]) {
                        curr[idx + 1][i - 1] |= curr[idx][i];
                    }
                    else if (curr[idx - 1][i + 1] & curr[idx][i]) {
                        curr[idx + 1][i + 1] |= curr[idx][i];
                    }
                }
            }
        }

        for (int i = 0; i < curr_size; ++i) {
            int cnt = 0;
            //printf("%d, ", curr[idx + 1][i]);
            for (int j = 1; j < (1 << N); j <<= 1) {
                if (curr[idx + 1][i] & j) {
                    cnt++;
                }
            }
            if (cnt > 1) {
                curr[idx + 1][i] = 0;
            }
        }
        curr_size--;
        idx++;
    }
    int cnt = 0;
    for (int i = 0; i < curr_size; ++i) {
        if (curr[idx][i]) cnt++;
    }
    snum += cnt;
}
void bt(int index, int pick)
{
    if (pick == N) {
        sim();
        divnum++;
        return;
    }
    if (index == str_size) return;
    bt(index + 1, pick);
    state[index] |= (1 << pick);
    bt(index + 1, pick + 1);
    state[index] ^= (1 << pick);
}
int main(int argc, char** argv)
{
    scanf("%s", str);
    str_size = strlen(str);
    scanf("%d", &N);
    bt(0, 0);
    printf("%.12lf", snum / divnum);
    return 0;
}