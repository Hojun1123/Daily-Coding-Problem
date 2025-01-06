#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//토기는 직접 제작
//커피를 토기에 넣으면 일정시간안에 서빙해야댐
//토기는 재사용x
//정수시간에만 손님 옴
//손님오면 바로 서빙해야댐
int arr[2000001];
int main()
{
	int N, M, a;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) { scanf("%d", &a); arr[a] = 1; };
	int t = 0;
	//만들고 담고 서빙 -> 3
	//누가오면 무조건 서빙
	int togi = 0; 
	int coffee = 0;
	int endFlag = 0;
	int needCoffee = 0;
	if (arr[0] || arr[1]) {
		printf("fail");
		return 0;
	}
	for (int i = 2; i < M; ++i) {
		if (arr[i])needCoffee++;
	}
	for (int i = 0; i <= a; ++i) {
		if (arr[i + M] == 1) {
			needCoffee++;
		}
		if (arr[i]) {
			//무조건 커피 서빙
			if (coffee > 0) {
				coffee--;
				continue;
			}
			else {
				endFlag = 1;
				break;
			}
		}
		else {
			if (needCoffee > 0) {
				//커피가 더 필요하면
				if (togi > 0) {
					togi--;
					needCoffee--;
					coffee++;
				}
				else {
					togi++;
				}
			}
			else {
				togi++;
			}
		}
		
	}
	printf(endFlag ? "fail" : "success");
	return 0;
}