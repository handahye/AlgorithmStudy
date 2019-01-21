#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int c = 0; c<commands.size(); c++) {
		int i = commands[c][0];
		int j = commands[c][1];
		int k = commands[c][2];
		vector<int> v;
		for (int idx = i; idx <= j; idx++)
			v.push_back(array[idx - 1]);
		sort(v.begin(), v.end());
		if (v.size()>k) answer.push_back(v[k - 1]);
		else answer.push_back(v[v.size() - 1]);
		v.clear();
	}
	return answer;
}