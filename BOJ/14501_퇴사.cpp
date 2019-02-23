#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int N, T[17], P[17];
int res;
void dfs(int day, int sum) {
	if (day == N + 1) { 
		res = max(res, sum);
		return;
	}
	//현재 날짜에 상담하는 경우
	if (day + T[day] <= N + 1) {
		dfs(day + T[day], sum + P[day]);
	}
	//현재 날짜에 상담 안하고 다음으로 날로 넘어감
	dfs(day + 1, sum);
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &T[i], &P[i]);
	dfs(1, 0);
	printf("%d", res);
	return 0;
}
