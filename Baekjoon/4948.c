#include <stdio.h>
int arr[246913]; //전역변수는 초기화 하지 않으면 0으로 자동초기화됨
void func(int n)  //소수 구하기
{
    int i, j;
    for (i = 2; i <= 2 * n; i++) {
        if (arr[i] == 1) {
            continue;
        }
        for (j = 2 * i; j <= 2 * n; j += i) {
            arr[j] = 1;
        }
    }
}
int main()
{
    int n;
    int i, sum = 0;
    func(123456); //문제에서 범위가 (N <= 123456)
    while (1) {
        scanf("%d", &n);
        if (n == 0)
            return 0;
        sum = n;
        for (i = n + 1; i <= 2 * n; i++)
            sum -= arr[i];
        printf("%d\n", sum);
    }
}