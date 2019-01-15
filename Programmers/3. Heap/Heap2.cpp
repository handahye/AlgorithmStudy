#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	//1. 우선순위 큐 사용 -> 공급량이 큰 순서로 꺼내기 위해서
	priority_queue<int> que; 
	int idx = 0;
	while (1) {
		//2. 현재 누적된 stock으로 k일까지 버틸 수 있으면 return
		if (stock >= k) return answer; 
		//3. 현재 가지고 있는 밀가루 양으로 버틸 수 있는 날까지 받을 수 있는 공급을 우선순위 큐에 삽입
		for (int i = idx; i<dates.size(); i++) {
			if (dates[i] <= stock) que.push(supplies[i]);
			else {//버틸 수 없는 날짜 idx 저장
				idx = i;
				break;
			}
		}
		//4. 우선순위 큐에서 가장 큰 공급량을 꺼내옴 
		answer++;
		stock += que.top();//stock의 양 누적해서 더함
		que.pop();
	}
	return answer;
}