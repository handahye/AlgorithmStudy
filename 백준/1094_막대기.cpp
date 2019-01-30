#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
using namespace std;
/*
#1094_막대기
1. 64cm의 막대기 -> 잘라서 풀로 붙여 길이가 Xcm 막대기 만듦
2. 지민이가 가지고 있는 막대의 길이를 모두 더함 합이 X보다 크면
2-1) 가지고 있는 막대 중 가장 짧은 걸 절반으로 자름
2-2) 위에서 자른 막대의 절반 중 하나를 버리고 남아있는 막대의 길이의 합이 X보다 크거나 같으면
위에서 자른 막대의 절반 중 하나를 또 버림
3. 남아있는 모든 막대를 풀로 붙여 Xcm로 만듦
4. 몇개의 막대를 풀로 붙이는지?
*/
int main() {
	int N = 64;
	int n;
	cin >> n;
	int sum = 0, res = 0;
	while (1) {
		if (N == n) break;
		if (N > n) {
			N = N / 2;
			continue;
		}
		sum += N;
		if (sum > n) {
			sum -= N;
			N = N / 2;
			continue;
		}
		res++;
	}
	cout << res;
	return 0;
}