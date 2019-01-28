#include <string>
#include <vector>

using namespace std;
int answer;
vector<int> tmp;
void dfs(int idx, int sum, int target) {
	if (idx >= tmp.size()) return;
	if (sum == target && idx == tmp.size() - 1) {
		answer++;
		return;
	}
	dfs(idx + 1, sum + tmp[idx + 1], target);
	dfs(idx + 1, sum - tmp[idx + 1], target);
}
int solution(vector<int> numbers, int target) {
	answer = 0;
	tmp = numbers;
	dfs(0, numbers[0], target);
	dfs(0, -numbers[0], target);
	return answer;
}