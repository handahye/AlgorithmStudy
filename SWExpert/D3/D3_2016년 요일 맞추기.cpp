#include<iostream>
using namespace std;
int day[7] = { 4,5,6,0,1,2,3 };
int month[13] = { 0, 31,29,31,30,31,30,31,31,30,31,30,31 };
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int res = 4;
		int m, d;
		scanf("%d%d", &m, &d);
		int tmp = 0;
		for (int i = 1; i < m; i++) tmp += month[i];
		tmp += d;
		printf("#%d %d\n", t, day[(tmp - 1) % 7]);

	}
	return 0;
}