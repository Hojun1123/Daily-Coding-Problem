#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int N;
	scanf("%d", &N);
	int arr[100];
	for (int i = 0; i < N; ++i) scanf("%d", &arr[i]);
	for (int i = 1; i < N; ++i) {
		int a = arr[0];
		int b = arr[i];
		int minValue = (a < b) ? a : b;
		for (int k = minValue; k >= 2; --k) {
			if (a % k == 0 && b % k == 0) {
				a /= k;
				b /= k;
			}
		}
		printf("%d/%d\n", a, b);
	}
	return 0;
}