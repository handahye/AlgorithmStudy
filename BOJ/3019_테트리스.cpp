#include <iostream>
#include<string>
#include<queue>
#include<string.h>
using namespace std;
/*
BOJ_3019_테트리스
*/
int C, P, ans = 0;
int map[101];
void solve(string s) {
	int len = s.length();
	for (int i = 0; i <= C - len; i++) {
		bool chk = true;
		for (int j = i; j < i + len - 1; j++) {
			int cur = s[j - i] - '0';
			int next = s[j - i + 1] - '0';
			if (cur - next != map[j] - map[j + 1]) {
				chk = false;
				break;
			}
		}
		if (chk) ans++;
	}
}
int main() {
	ans = 0;
	cin >> C;
	cin >> P;
	for (int i = 0; i < C; i++) cin >> map[i];
	switch (P) {
	case 1: 
		solve("0");
		solve("0000");
		break;
	case 2:
		solve("00");
		break;
	case 3:
		solve("001");
		solve("10");
		break;
	case 4:
		solve("100");
		solve("01");
		break;
	case 5:
		solve("000");
		solve("101");
		solve("10");
		solve("01");
		break;
	case 6:
		solve("000");
		solve("011");
		solve("00");
		solve("20");
		break;
	case 7:
		solve("000");
		solve("110");
		solve("00");
		solve("02");
		break;
	}
	cout << ans;
	return 0;
}