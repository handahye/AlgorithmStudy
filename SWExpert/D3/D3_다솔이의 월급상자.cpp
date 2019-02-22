#include<iostream>
/*SWEA D3_다솔이의 월급상자*/
using namespace std;
int T, N;
int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		long double res=0;
		for (int i = 0; i < N;i++) {
			long double p1, x1;
			scanf("%Lf %Lf", &p1, &x1);
			res += (p1*x1);
		}
		printf("#%d %.6Lf\n", t, res);
	}
	return 0;
}
