#include <stdio.h>
int arr[246913]; //���������� �ʱ�ȭ ���� ������ 0���� �ڵ��ʱ�ȭ��
void func(int n)  //�Ҽ� ���ϱ�
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
    func(123456); //�������� ������ (N <= 123456)
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