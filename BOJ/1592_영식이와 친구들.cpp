#include <iostream>
#include <algorithm>
#include<vector>
#include <string>
using namespace std;
/*
#1592_영식이와 친구들
1. 공을 주고 받으면서 공을 받은 횟수가 M이면 끝나는 게임
2. 공을 던질 때 받은 횟수가
1) 홀수면 반시계 방향으로 L번째 사람한테 던짐
2) 짝수면 시계 방향으로 L번째 사람한테 던짐
*/
int main() {
	int res = 0;
	int N, M, L;
	cin >> N >> M >> L;
	int chk[1002] = { 0, };
	int p = 1;
	while (1) {
		if (chk[p] == M) break;
		if (chk[p] % 2 == 0) {
			p = (p + L) % N;
			if (p == 0) p = N;
			chk[p] += 1;
		}
		else {
			if (p - L <= 0) p = p - L + N;
			else p = p - L;
			chk[p] += 1;
		}
		res++;
	}
	cout << res -1<< endl;
	return 0;
}