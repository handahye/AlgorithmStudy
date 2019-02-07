#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<list>
using namespace std;
/*
#2161_카드2
1. 1번 카드가 제일 위, N번 카드가 제일 밑은 상태
2. 제일 위에 있는 카드를 바닥에 버림. 그리고 제일 위의 카드를 제일 아래로
3. 위의 동작을 카드가 한장 남을때까지 반복
4. 마지막 남은 카드 출력
*/
int main() {
	int res = 0;
	int n;
	cin >> n;
	list<int> card;
	for (int i = 1; i <= n; i++) card.push_back(i);
	while(card.size() > 1) {
		int f = card.front();
		card.pop_front();
		int f2 = card.front();
		card.pop_front();
		card.push_back(f2);
	}
	cout << card.back();
	return 0;
}