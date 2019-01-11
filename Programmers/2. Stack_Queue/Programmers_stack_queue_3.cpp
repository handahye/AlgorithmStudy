#include <string>
#include <vector>
#include <queue>
#include <list>
using namespace std;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int time = 1;
	/*
	- list: 
		1) 현재 다리를 지나고 있는 트럭들의 무게를 재야하니까 iterator를 사용하기 위해
		2) push할땐 현재 다리위를 지나고 있는 트럭들의 맨 뒤에 push하고
		다리를 다 지나간 경우 맨 앞의 트럭을 pop하기 위해서 

	- queue: 다리를 지나가기 위해 기다리는 트럭들 queue에 삽입(waiting)
	*/
	list<int> passing;
	queue<int> waiting;

	//1. 첫번째로 지나가야 하는 트럭 passing list에 삽입
	passing.push_back(truck_weights[0]);
	//2. 대기중인 트럭들 queue에 삽입
	for (int i = 1; i<truck_weights.size(); i++) waiting.push(truck_weights[i]);

	//3. 대기중인 트럭들이 없을때까지 while문 돌기
	while (!waiting.empty()) {
		//4. passing list의 크기가 다리 길이와 같아지면 맨 앞의 트럭이 다리를 다 건넌거니까 pop해줌
		if (passing.size() == bridge_length) passing.pop_front();

		//5. 현재 다리위의 트럭들 무게 계산
		for (auto iter : passing) totalW += iter;

		int curW = waiting.front(); 
		int totalW = 0;
		//6-1) 대기중인 트럭이 지나갈 수 있는 경우 (대기하는 트럭의 무게+다리위 트럭무게<=다리가 견대낼 수 있는 무게)
		if (totalW + curW <= weight) {
			passing.push_back(curW);//passing list에 삽입
			waiting.pop();//waiting queue에서 삭제
		}
		//6-2) 지나갈 수 없는 경우
		else
			passing.push_back(0);//맨 앞의 트럭이 다리 다 건넜는지 체크하려고
		/*
		<1초> | 7 |
		<2초> | 7 | -> | 7 | 0 | [무게 4의 트럭이 못 지나가니까 0 push]
		<3초> [pssing size = 2, 무게 7의 트럭이 다리 다 건넌거니까 pop] | 7 | 0 | -> | 0 | -> | 0 | 4 | 
		<4초> | 0 | 4 | -> | 4 | -> | 4 | 5 | 
		<5초> | 4 | 5 | -> | 5 | -> | 5 | 0 |
		<6초> | 5 | 0 | -> | 0 | -> | 0 | 6 | 
		
		정답: 6초 + 다리길이(2) = 8초
		*/

		//7. 시간 증가
		time++;
	}
	return time + bridge_length;//waiting queue에서 마지막으로 나온 트럭은 다리위에서 움직이지 않은거니까 다리길이만큼 더 가야함! 
}
int main() {
	return 0;
}