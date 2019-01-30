#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
using namespace std;
/*
#1931_회의실배정
1. 한개의 회의실 -> N개의 회의에 대해서 사용표
2. 회의에 대해서 시작, 끝 시간 주어짐
3. 회의가 겹치지 않게 사용가능한 최대 회의 찾기
4. 한 회의가 끝나는 동시에 다음 회의 시작 가능
5. 시작 시간 = 끝나는 시간 가능(시작하자 마자 끝나는 경우)

1) 가장 빨리 끝나는 회의 먼저 고려 
2) 종료 시간이 같을 땐 시작 시간이 빠른 순서대로 
*/
struct que{
	int start;
	int end;
};
bool operator<(que q1, que q2) {
	if (q1.end != q2.end) 
		return q1.end > q2.end;
	return q1.start > q2.start;
}
int main() {
	int n;
	priority_queue<que> pq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		pq.push({ s,e });
	}
	int endPoint = -1;
	int res = 0;
	
	while (!pq.empty()) {
		int start = pq.top().start;
		int end = pq.top().end;
		pq.pop();

		if (start >= endPoint) {
			res++;
			endPoint = end;
		}
	}
	cout << res << endl;;
	return 0;
}