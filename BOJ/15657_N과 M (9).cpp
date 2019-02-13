#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
using namespace std;
/*
BOJ_15657_N과 M (9)
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
N개의 자연수는 모두 다른 수이다.
- N개의 자연수 중에서 M개를 고른 수열
*/
int N, M;
vector<int> ans;
int arr[9];
bool chk[9];
set<vector<int>> s;
void dfs(int cnt) {
	if (cnt == M) {
		s.insert(ans);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!chk[i]) {
			chk[i] = true;
			ans.push_back(arr[i]);
			dfs(cnt + 1);
			ans.pop_back();
			chk[i] = false;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	dfs(0);
	for (auto iter : s) {
		for (auto k : iter) {
			printf("%d ", k);
		}
		printf("\n");
	}
	return 0;
}