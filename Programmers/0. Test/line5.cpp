#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;
struct que {
	int c, b, cnt;
	int diff;
};
bool operator<(que a, que b) {
	return a.diff > b.diff; //차이가 작은 순으로
}
int C, B;
int minN = 987654321;
void bfs() {
	priority_queue<que> q;
	q.push({ C,B,0,C - B });
	while (!q.empty()) {
		int c = q.top().c;
		int b = q.top().b;
		int cnt = q.top().cnt;
		int diff = q.top().diff;
		q.pop();
		if (c > 200000 || c < 0 || diff<0) continue;
		if (cnt>minN || b>c) continue;
		if (b == c) {
			minN = min(minN, cnt);
			continue;
		}
		int nc = c + cnt + 1;
		q.push({ nc, b * 2, cnt + 1, nc - (b * 2) });
		q.push({ nc, b + 1, cnt + 1, nc - (b + 1) });
		q.push({ nc, b - 1, cnt + 1, nc - (b - 2) });
	}

	
	
	
}
int main() {
	cin >> C >> B;
	bfs();
	if(minN == 987654321) printf("-1\n");
	else printf("%d\n", minN);
	return 0;
}
