#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
using namespace std;
/*
#2455_지능형 기차
1. 1~4번역까지의 노선에서 운행됨
2. 타거나 내리는 사람 수 자동으로 인식
3. 출발 -> 종착역까지 가는 도중 사람이 가장 많을 때 계산
4. 기차에 탈 때, 내릴 사람이 모두 내릴 후 기차에 탐
*/
int main() {
	int res = 0, sum =0;
	for (int i = 0; i < 4; i++) {
		int minus, plus;
		cin >> minus >> plus;
		sum = sum - minus + plus;
		res = max(res, sum);
	}
	cout << res << endl;;
	return 0;
}