#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int T, N, M, a, b;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d %d", &N, &M);
		for (int j = 0; j < M; ++j) {
			scanf("%d %d", &a, &b);
		}
		printf("%d\n", N - 1);
	}
	return 0;
}