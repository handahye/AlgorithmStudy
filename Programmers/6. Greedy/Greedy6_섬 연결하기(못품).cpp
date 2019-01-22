#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include<iostream>
using namespace std;
int minN = 987654321;
int visit[100], dist[100][100];
vector<int> island[100];
void dfs(int n, int start, int idx, int sum, int cnt) {
	if (cnt == n) {
		if (dist[start][idx] != 0)
			minN = min(minN, sum);
		return;
	}

	for (int i = 0; i<island[idx].size(); i++) {
		int next = island[idx][i];
		if (!visit[next] && sum + dist[idx][next]<minN) {
			visit[next] = 1;
			dfs(n, start, next, sum + dist[idx][next], cnt + 1);
			visit[next] = 0;
		}
	}

}
void init() {
	minN = 987654321;
	memset(visit, 0, sizeof(visit));
	memset(dist, 0, sizeof(dist));
	island->clear();
}
int solution(int n, vector<vector<int>> costs) {
	init();
	for (int i = 0; i<costs.size(); i++) {
		int u = costs[i][0];
		int v = costs[i][1];
		island[u].push_back(v);
		island[v].push_back(u);
		dist[v][u] = dist[u][v] = costs[i][2];
	}
	for (int i = 0; i<n; i++) {
		visit[i] = 1;
		dfs(n, i, i, 0, 1);
		visit[i] = 0;
	}
	return minN;
}
