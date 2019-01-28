#include <string>
#include <vector>

using namespace std;
int visit[100001], n;
string res = "Z";
void dfs(int cnt, string cur, string path, vector<vector<string>> &tickets) {
	if (cnt == n) {
		if (path < res) res = path;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visit[i]) continue;
		if (cur == tickets[i][0]) {
			visit[i] = 1;
			dfs(cnt + 1, tickets[i][1], path + tickets[i][1], tickets);
			visit[i] = 0;
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	n = tickets.size();
	dfs(0, "ICN", "ICN", tickets);
	for (int i = 0; i < res.size(); i += 3) {
		answer.push_back(res.substr(i, 3));
	}
	return answer;
}