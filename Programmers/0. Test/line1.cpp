#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<long long> d;
	long long N;
	long long res = 987987654321;
	scanf("%lld", &N);
	for (long long i = 1; i * i <= N; i++) {
		long long a, b;
		if (N % i == 0) {
			a = i;
			b = N / i;
		}
		res = min(res, abs(a - b));
	}
	cout << res << endl;
	return 0;
}
