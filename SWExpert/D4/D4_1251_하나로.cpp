#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std;
/*
D4_1251_하나로
- 환경 부담 세율(E)과 각 해저터널 길이(L)의 제곱의 곱(E * L2)만큼 지불
총 환경 부담금을 최소로 지불하며, N개의 모든 섬을 연결할 수 있는 교통 시스템을 설계하시오.
모든 섬들을 잇는 최소 환경 부담금을 소수 첫째 자리에서 반올림하여 정수 형태로 출력하라.
priorty queue? 
*/
struct que {
	long long dist;
	long long r;
	long long c;
	int idx;
};
struct cmp {
	bool operator()(que a, que b) {
		return a.dist > b.dist;
	}
};

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		long long res = 0;
		vector<long long> x, y;
		int visit[1002] = { 0, };
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			long long tmp;
			cin >> tmp;
			x.push_back(tmp);
		}
		for (int i = 0; i < N; i++) {
			long long tmp;
			cin >> tmp;
			y.push_back(tmp);
		}
		double E;
		cin >> E;
		priority_queue<que, vector<que>,cmp> q;
		q.push({ 0, x[0],y[0],0 });
		while (!q.empty()) {
			int idx = q.top().idx;
			long long r = q.top().r;
			long long c = q.top().c;
			long long dist = q.top().dist;
			q.pop();

			if (visit[idx]) continue;
			visit[idx] = 1;
			res += dist;

			for (int i = 0; i < N; i++) {
				if (visit[i]) continue;
				long long nr = x[i], nc = y[i];
				long long d = abs(nr - r)*abs(nr - r) + abs(nc - c)*abs(nc - c);
				q.push({ d, nr, nc, i });
			}
		}
		cout << "#" << t << " " << (long long)round(res*E)<< endl;
	}
	return 0;
}