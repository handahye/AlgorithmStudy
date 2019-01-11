#include <string>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> &prices) {
	vector<int> answer;
	queue<pair<int, int>> que;//가격, 시간
	que.push({ prices[0],1 });
	while (1) {
		int curPrice = que.front().first;
		int curTime = que.front().second;
		if (curTime == prices.size() - 1) {
			answer.push_back(que.size());
			answer.push_back(0); //마지막 주식
			break;
		}
		for (int i = curTime + 1; i <= prices.size(); i++) {
			if (prices[i - 1]>curPrice) que.push({ prices[i - 1],i });
			else {
				for (int i = 0; i<que.size(); i++) {
					answer.push_back(que.size());
					que.pop();
				}
				que.push({ prices[i - 1],i });
				break;
			}
		}
	}
	return answer;
}
int main() {
	vector<int> b;
	b.push_back(489);
	b.push_back(501);
	b.push_back(470);
	b.push_back(489);
	solution(b);
	return 0;
}