#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<math.h>
using namespace std;
/*
BOJ_15664_N과 M (11)
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
- N개의 자연수 중에서 M개를 고른 수열
- 같은 수를 여러 번 골라도 된다.
*/
int N, M;
vector<int> ans;
int arr[9];
set<vector<int>> s;
void dfs(int cnt) {
	if (cnt == M) {
		s.insert(ans);
		return;
	}
	for (int i = 0; i < N; i++) {
		ans.push_back(arr[i]);
		dfs(cnt + 1);
		ans.pop_back();
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