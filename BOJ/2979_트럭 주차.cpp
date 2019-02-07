#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<list>
using namespace std;
/*
#2979_트럭 주차
1. 트럭 총 세대 가지고 있음
2. 트럭을 주차하는데 비용 계산
3. 트럭의 수에 따라 주차 요금 할인
	3-1) 한대 추자 -> 1분에 한 대당 A원
	3-2) 두대 주차 -> 1분에 한 대당 B원
	3-3) 세대 주차 -> 1분에 한 대당 C원
4. A, B, C가 주어졌을 때, 주차요금을 얼마를 내야하는지 
*/
int main() {
	int a, b, c;
	int res = 0;
	vector<pair<int,int>> v;
	cin >> a >> b >> c;
	int cnt[101] = { 0, };
	for (int i = 0; i < 3; i++) {
		int s, e;
		cin >> s >> e;
		for (int j = s; j < e; j++)
			cnt[j] += 1;
	}
	for (int i = 0; i < 101; i++) {
		if (cnt[i] == 1) res += a;
		else if (cnt[i] == 2) res += b * 2;
		else if (cnt[i] == 3) res += c * 3;
	}
	
	cout << res;
	return 0;
}