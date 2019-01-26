#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solution(int l, vector<int> v) {//도로의 전체 길이, 가로등이 세워져 있는 위치
	int maxN = -1;
	sort(v.begin(), v.end());
	for (int i = 0; i<v.size() - 1; i++)
		maxN = max(maxN, v[i + 1] - v[i]);

	int ans = ceil(float(maxN) / 2.0);
	int start = v[0] - 0, end = l - v[v.size() - 1];
	ans = max(ans, max(start, end));
	return ans;
}