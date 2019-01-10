#include <string>
#include <vector>
#include <queue>
#include <list>
using namespace std;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int time = 1;
	list<int> passing;
	queue<int> waiting;
	passing.push_back(truck_weights[0]);
	for (int i = 1; i<truck_weights.size(); i++) waiting.push(truck_weights[i]);
	while (!waiting.empty()) {
		int curW = waiting.front(); //지금 지나가려는 트럭의 무게
		int totalW = 0;
		if (passing.size() == bridge_length) passing.pop_front();//하나의 트럭이 다리를 다 건너면
		for (auto iter : passing) totalW += iter; //현재 다리위의 트럭들 무게

		if (totalW + curW <= weight) { //현재 트럭이 다리위를 지나갈 수 있으면
			passing.push_back(curW);//passing list에 삽입
			waiting.pop();//waiting queue에서 삭제
		}
		else
			passing.push_back(0);//못지나가면
		time++;//시간 증가
	}
	return time + bridge_length;//대기에서 마지막으로 나온 트럭은 다리길이만큼 더 가야되니까
}
int main() {
	return 0;
}