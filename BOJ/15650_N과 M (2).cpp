#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;
/*
BOJ_15650_N과 M (2)
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
- 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
- 고른 수열은 오름차순이어야 한다.
*/
bool visit[10];
int N, M;
vector<int> ans;
void dfs(int idx, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = idx+1 ; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			ans.push_back(i);
			dfs(i, cnt + 1);
			ans.pop_back();
			visit[i] = false;
		}

	}
}
int main() {
	cin >> N >> M;
	dfs(0, 0);
	return 0;
}