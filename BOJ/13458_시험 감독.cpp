#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int N, B, C;
int A[1000001];
int main() {
	long long cnt = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	scanf("%d%d", &B, &C);
	for (int i = 0; i < N; i++) {
		A[i] -= B; //총 감독이 감독할 응시자 수 뺌
		cnt++;
		if (A[i] > 0) { //아직 감시해야 할 응시자 수가 남은 경우
			if (A[i] % C == 0) cnt += (A[i] / C);
			else cnt += (A[i] / C) + 1;
		} //필요한 부 감독수 만큼 더해줌
	}
	printf("%lld", cnt);
	return 0;
}