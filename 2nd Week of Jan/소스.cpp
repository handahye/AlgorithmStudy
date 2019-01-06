#include<iostream>
#include<string>
using namespace std;
/*4530. 극한의 청소 작업*/
int T;
long long A, B;
long long cal(long long n) {
	int cnt = 0;
	for (long long i = 1; i <= n; i++) {
		bool chk = true;
		int tmp = i;
		while (tmp > 0) {
			if (tmp % 10 == 4) {
				chk = false;
				break;
			}
			tmp /= 10;
		}
		if (chk) cnt++;
	}
	return cnt;
}
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> A >> B;
		printf("#%d %lld\n", t, cal(-A)+cal(B)-1);
	}
	return 0;
}