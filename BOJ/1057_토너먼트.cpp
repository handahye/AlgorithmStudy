#include <math.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
using namespace std;
/*
#1057_토너먼트
1. 1~N번까지 번호를 배정 받고 서로 인접한 번호끼리 스타
2. 이긴 사람이 진출, 진 사람 떨어짐
3. 홀수명이면 마지막 번호는 자동 진출
4. 다음 라운드에서 다시 번호 매김
5. 한 명만 남을 때까지 계속 진행
6. 김지민과 임한수가 몇 라운드에서 대결하는지 출력하기
*/
int main() {
	int res = 1;
	int N, a, b;
	cin >> N >> a >> b;
	while (1) {
		if (a < b && a % 2 == 1 && a + 1 == b) break;
		else if (a > b && b % 2 == 1 && a - 1 == b) break;
		a = ceil(float(a) / 2.0);
		b = ceil(float(b) / 2.0);
		res++;
	}
	cout << res;
	return 0;
}