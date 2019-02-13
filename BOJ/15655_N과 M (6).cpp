#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;
/*
BOJ_15655_N과 M (6)
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
N개의 자연수는 모두 다른 수이다.
- N개의 자연수 중에서 M개를 고른 수열
- 고른 수열은 오름차순이어야 한다.
*/
int N, M;
vector<int> ans;
int arr[9];
bool visit[9];
void dfs(int idx, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = idx+1; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			ans.push_back(arr[i]);
			dfs(i, cnt + 1);
			ans.pop_back();
			visit[i] = false;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		visit[i] = true;
		ans.push_back(arr[i]);
		dfs(i, 1);
		ans.pop_back();
		visit[i] = false;
	}
	return 0;
}