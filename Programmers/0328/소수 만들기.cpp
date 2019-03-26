#include <vector>
#include <iostream>
using namespace std;
bool visit[51];
int N, answer = 0;
void dfs(int idx, int cnt, int sum, vector<int> &nums) {
	if (cnt == 3) {
		int tmp = 0;
		for (int i = 1; i <= sum; i++) {
			if (sum%i == 0) tmp++;
			if (tmp>2) return;
		}
		if (tmp == 2) answer++;
		return;
	}
	for (int i = idx + 1; i<N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(i, cnt + 1, sum + nums[i], nums);
			visit[i] = false;
		}
	}
}
int solution(vector<int> nums) {
	N = nums.size();
	for (int i = 0; i<N; i++) {
		visit[i] = true;
		dfs(i, 1, nums[i], nums);
		visit[i] = false;
	}

	return answer;
}