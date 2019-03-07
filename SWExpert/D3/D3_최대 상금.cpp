#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
string num;
int N, res;
void dfs(int cnt, int idx) {
	if (cnt == N) {
		res = max(res, stoi(num));
		return;
	}
	for (int i = idx; i < num.size() - 1; i++) {
		for (int j = i + 1; j < num.size(); j++) {
			if (num[i] <= num[j]) {
				char a = num[i], b = num[j];
				num[i] = b, num[j] = a;
				dfs(cnt + 1, i);
				num[i] = a, num[j] = b;
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> num >> N;
		res = 0;
		dfs(0, 0);
		printf("#%d %d\n", t, res);
	}
	return 0;
}