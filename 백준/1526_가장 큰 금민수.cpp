#include <string>
#include <iostream>
#include <algorithm>
#include<vector>
#include<list>
using namespace std;
/*
#1526_가장 큰 금민수
1. 은민이는 4와 7을 좋아하고, 나머지 숫자는 싫어함
2. 금민수 = 4와 7로만 이루어진 수
3. N보다 작거나 같은 금민수 중 가장 큰거 출력하기
*/
int res = 0;
void dfs(int num, int n) {
	if (num > n) return;
	res = max(res, num);
	dfs(num * 10 + 4, n);
	dfs(num * 10 + 7, n);
}
int main() {
	int n;
	cin >> n;
	dfs(0, n);
	cout << res;
	return 0;
}