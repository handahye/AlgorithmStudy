#include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
#include<set>
using namespace std;
struct st {
	int R, G;
};
vector<st> v;
int N, L;
int map[1001];
int main() {
	scanf("%d%d", &N, &L);
	for (int i = 0; i < N; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v.push_back({b,c+b });
		map[a] = 1;
	}
	int time = 1, dist = 1;
	int idx = 0;
	while (1) {
		if (dist == L) break;
		if (map[dist]) {
			int r = v[idx].R, g = v[idx].G;
			int mod = time % g;
			if (mod < r) time = time + r - mod;
			else time++, dist++, idx++;
		}
		else time++, dist++;
	}
	printf("%d", time);
	return 0;
}