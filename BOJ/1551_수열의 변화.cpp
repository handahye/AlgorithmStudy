#include <string>
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
#1551_수열의 변화
1. 크기가 N인 수열 A가 주어져졌을 때, 인접한 두 원소의 차이를 이용해
크기가 N-1 수열 B를 만듦
2. B[i] = A[i+1]-A[i]
3. A가 주어졌을 때, 세준이가 위의 방법을 K방법 했을 떄 나오는 수열 구하기
*/
int main() {
	int A[21] = { 0, };
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		char tmp;
		if (i == n - 1) cin >> A[i];
		else cin >> A[i] >> tmp;
	}
	int cnt = k;
	while (cnt--) {
		for (int i = 0; i < n - 1; i++)
			A[i] = A[i + 1] - A[i];
	}
	for (int i = 0; i < n - k - 1; i++) cout << A[i]<<",";
	cout << A[n - k - 1];
	return 0;
}