#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int map[5001] = { 0, };
		printf("#%d ", t);
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			for (int k = a; k <= b; k++)
				map[k] += 1;
		}
		int p;
		scanf("%d", &p);
		for (int i = 0; i < p; i++) {
			int c;
			scanf("%d", &c);
			printf("%d ", map[c]);
		}
		printf("\n");
	}
	return 0;
}