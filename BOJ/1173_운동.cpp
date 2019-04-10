#include <iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int main() {
	scanf("%d%d%d%d%d", &N, &m, &M, &T, &R);
	int x = m, time = 0;
	for (int i = 0; i < N;) {
		time++;
		if (x + T <= M) {
			i++;
			x += T;
		}
		else {
			x -= R;
			if (x < m) x = m;
		}
		if (x + T > M && x == m) {
			printf("-1");
			return 0;
		}
	}
	printf("%d", time);
	return 0;
}