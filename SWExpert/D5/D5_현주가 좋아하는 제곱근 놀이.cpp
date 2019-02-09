#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;
/*
D5_현주가 좋아하는 제곱근 놀이
*/
long long res;
bool chk;
void dfs(long long cnt, long long num) {
	if (chk) return;
	if (res < cnt) return;
	if (num == 1) {
		res = min(res, cnt + 1);
		chk = true;
		return;
	}
	if (num == 2) {
		res = min(res, cnt);
		chk = true;
		return;
	}
	long long number = pow((long long)sqrt(num), 2) - num;
	if (number == 0) dfs(cnt + 1, (long long)sqrt(num)); //현재 수가 제곱수인지 체크
	else {
		int count = pow((long long)sqrt(num) + 1, 2) - num; //제곱수가 아니면 가장 가까운 제곱수를 찾음
		dfs(cnt + count + 1, (long long)sqrt(num) + 1);//위에서 제곱수로 만드려고 덧셈한 만큼 + 루트씌운 거
	}

}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		res = 999999999999;
		chk = false;
		long long N;
		cin >> N;
		dfs(0, N);
		cout << "#" << t << " " << res << endl;
	}
	return 0;
}