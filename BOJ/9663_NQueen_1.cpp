#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
using namespace std;
/*풀이 1*/
int visit[11];
int N, ans;
bool chk(int i) {
	for (int j = 0; j < i; j++) {//0부터 i행까지 같은 열 혹은 대각선에 위치 하는 퀸이 있는지
		if (visit[j] == visit[i] || abs(visit[i] - visit[j]) == (i - j))
			return false;
		//i행과 j행의 열 값이 똑같으면 퀸을 못 놓음
		//i행과 j행의 열 값이 대각선에 위치하는 절대값이면 안됨
	}
	return true;
}
void dfs(int i) {
	if (i == N) { //N개를 모두 센 경우
		ans += 1;
		return;
	}
	for (int j = 0; j < N; j++) { //다음위치 찾기
		visit[i] = j; //i행 j열에 퀸을 놓았음 (i,j)
		if (chk(i)) //현재 자리에 퀸을 놓을 수 있는지
			dfs(i + 1);//다음 행으로
	}
}
int main() {
	cin >> N;
	ans = 0;
	dfs(0);
	cout << ans << endl;
	return 0;
}
