#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<iostream>
using namespace std;
/*
#11077_동전0
1. 동전은 총 N종류, 각각의 동전을 매우 많이 가짐
2. 동전을 사용해서 가치의 합 K로 만들기
3. 필요한 동전 개수 최솟값 구하기
*/
bool cmp(int &a, int &b) {
	return a > b;
}
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	int j=0;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > K) break;
		A[i] = tmp;
		j++;
	}
	sort(A.begin(), A.end(), cmp);
	int sum = K, cnt = 0;
	int idx = 0;
	while (1) {
		if (sum == 0) break;
		sum -= A[idx];
		if (sum < 0) {
			sum += A[idx];
			idx++;
			continue;
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}