#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int student1[5] = { 1,2,3,4,5 };
int student2[8] = { 2,1,2,3,2,4,2,5 };
int student3[10] = { 3,3,1,1,2,2,4,4,5,5 };
int res1, res2, res3;
bool compare(pair<int, int>&a, pair<int, int>&b) {
	if (a.first == b.first)
		return a.second<b.second;
	return a.first>b.first;
}
void dfs(vector<int> &answers, int num, int end) {
	if (num == end) {
		return;
	}
	if (student1[num % 5] == answers[num]) res1++;
	if (student2[num % 8] == answers[num]) res2++;
	if (student3[num % 10] == answers[num]) res3++;
	dfs(answers, num + 1, end);
}
vector<int> solution(vector<int> answers) {
	vector<int> answer;
	sort(answer.begin(), answer.end());
	dfs(answers, 0, answers.size());

	vector<pair<int, int>> tmp;
	tmp.push_back({ res1,1 });
	tmp.push_back({ res2,2 });
	tmp.push_back({ res3,3 });

	sort(tmp.begin(), tmp.end(), compare);
	int max = tmp[0].first;
	answer.push_back(tmp[0].second);
	for (int i = 1; i<tmp.size(); i++) {
		if (max == tmp[i].first) answer.push_back(tmp[i].second);
	}
	return answer;
}