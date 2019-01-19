#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> v(n, 1);

	for (int i = 0; i < reserve.size(); i++) v[reserve[i] - 1] += 1;
	for (int i = 0; i < lost.size(); i++) v[lost[i] - 1] -= 1;

	for (int i = 0; i < n; i++) {
		if (i > 0 && v[i] == 0 && v[i - 1] == 2) {
			v[i]++;
			v[i - 1]--;
			continue;
		}
		if (i < n && v[i] == 0 && v[i + 1] == 2) {
			v[i]++;
			v[i + 1]--;
			continue;
		}
	}

	for (int i = 0; i < n; i++)
		if (v[i] > 0) answer++;

	return answer;
}