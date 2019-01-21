#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> que;
	for (int i = 0; i<progresses.size(); i++) {
		int day = floor((100 - progresses[i]) / speeds[i]);//작업일수
		que.push(day);
	}
	int first = que.front(), num = 1;
	que.pop();
	while (!que.empty()) {
		int n = que.front();
		que.pop();
		if (n <= first) num++; //작업일수가 더 작은 경우
		else {//더 큰경우
			answer.push_back(num);
			first = n;//작업일 수 바꿔줌
			num = 1;
		}
	}
	answer.push_back(num);
	return answer;
}
int main() {
	return 0;
}