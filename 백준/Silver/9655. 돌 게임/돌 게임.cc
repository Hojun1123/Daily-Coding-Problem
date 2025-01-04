#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ans[1001];
int main()
{
	int N;
	scanf("%d", &N);
	printf(N % 2 ? "SK" : "CY");
	return 0;
}