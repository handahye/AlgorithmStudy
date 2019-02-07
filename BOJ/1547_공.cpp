#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<list>
using namespace std;
/*
#1547_공
1. 1번컵에 공 하나 넣기
2. 두 컵을 고르고, 그 위치를 바꿈
3. M번 컵의 위치 바꾼 뒤 이후 공이 들어있는 컵 번호 찾기
*/
int main() {
	int res = 1;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a == res) res = b;
		else if (b == res) res = a;
	}
	cout << res;
	return 0;
}