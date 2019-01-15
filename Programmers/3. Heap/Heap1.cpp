#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int> que;
	for (int i = 0; i<scoville.size(); i++)
		que.push(-scoville[i]);
	while (!que.empty()) {
		if (que.size() == 1 && -que.top()<K) {
			return -1;
		}
		int first = -que.top();
		que.pop();
		int second = -que.top();
		que.pop();

		if (first >= K && second >= K) return answer;
		int newS = first + (second * 2);
		answer++;
		que.push(-newS);
	}
}