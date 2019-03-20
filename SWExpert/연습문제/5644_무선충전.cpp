#include <iostream>
#include<string.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
struct AP {
	int r, c, C, P;
};
int dr[5] = { 0,0,1,0,-1 };
int dc[5] = { 0,-1,0,1,0 };
int M, A;
int cal(vector<AP> &ap, int ar, int ac, int br, int bc) {
	int chkA[8] = { 0, };
	int chkB[8] = { 0, };

	for (int i = 0; i < A; i++) {
		int distA = abs(ap[i].r - ar) + abs(ap[i].c - ac);
		int distB = abs(ap[i].r - br) + abs(ap[i].c - bc);
		if (distA <= ap[i].C) chkA[i] = ap[i].P;
		if (distB <= ap[i].C) chkB[i] = ap[i].P;
	}
	int sum = 0;
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < A; j++) {
			if (i == j) {
				sum = max(sum, chkA[i]);
				sum = max(sum, chkB[i]);
			}
			else sum = max(sum, chkA[i] + chkB[j]);
		}
	}
	return sum;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		vector<int> a, b;
		scanf("%d%d", &M, &A);
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < M; i++) {
				int d;
				scanf("%d", &d);
				if (j == 0) a.push_back(d);
				else b.push_back(d);
			}
		}
		vector<AP> ap;
		for (int i = 0; i < A; i++) {
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			ap.push_back({ a,b,c,d });
		}
		int ar = 1, ac = 1, br = 10, bc = 10;
		int res = cal(ap, ar, ac, br, bc);
		for (int i = 0; i < M; i++) {
			ar += dr[a[i]];
			ac += dc[a[i]];
			br += dr[b[i]];
			bc += dc[b[i]];
			res += cal(ap, ar, ac, br, bc);
		}
		printf("#%d %d\n", t, res);
	}
	return 0;
}
