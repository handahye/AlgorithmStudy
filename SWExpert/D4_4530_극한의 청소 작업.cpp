#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
/*4530. 극한의 청소 작업*/
int T;
long long A, B;
long long cal(long long n) {//재귀
	long long tmp = n % 10;
	if (tmp > 4) tmp--; //4이상이면 4를 포함해서 세는 숫자니까 -1함
	if (n < 10) return tmp; //기저조건
	else return 9 * cal(n / 10) + tmp;
	//일의 자리 수부터 4를 포함해 세고 있는 수인지 계산
}
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> A >> B;
		long long a = (A < 0 ? -A : A);
		long long b = (B < 0 ? -B : B);
		long long res = 0;
		if (A < 0 && B>0) res = cal(a) + cal(b) - 1;
		else res = abs(cal(a) - cal(b));
		printf("#%d %lld\n", t, res);
	}
	return 0;
}