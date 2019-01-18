#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> &operations) {
	vector<int> answer;
	multiset<int> s;
	for (int i = 0; i<operations.size(); i++) {
		string tmp = operations[i].substr(2, operations[i].size() - 1);
		int num = atoi(tmp.c_str());
		if (operations[i].at(0) == 'I') s.insert(num);
		else if (operations[i].at(0) == 'D') {
			if (s.size() == 0) continue;
			if (num == 1) s.erase(--s.end());
			else s.erase(s.begin());
		}
	}
	if (s.size() >= 2) {
		auto iter = --s.end();
		answer.push_back(*iter);
		iter = s.begin();
		answer.push_back(*iter);
	}
	else {
		answer.push_back(0);
		answer.push_back(0);
	}
	return answer;
}

int main() {
}