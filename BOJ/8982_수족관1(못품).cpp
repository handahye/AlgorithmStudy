#include <iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int maxC;
int N, K;
int main() {
	int total = 0;
	scanf("%d", &N);
	int a, b, c, d;
	scanf("%d%d", &a, &b);
	vector<pair<int, int>> v;
	for (int i = 0; i < (N/2)-1; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int x = c - a;
		for (int k = 0; k<x; k++)
			v.push_back({ b,0 });
	}
	scanf("%d%d", &maxC, &b);
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int h = v[a].first;
		int c = a, r = b;
		v[a].second = b;
		//¿ÞÂÊ
		for (int k = c - 1; k >= 0; --k) {
			if (h > v[k].first) h = v[k].first;
			if (v[k].second < h) v[k].second = h;
		}
		for (int k = c + 1; k < maxC; ++k) {
			if (h > v[k].first) h = v[k].first;
			if (v[k].second < h) v[k].second = h;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		total += (v[i].first - v[i].second);
	}
	printf("%d", total);
	return 0;
}