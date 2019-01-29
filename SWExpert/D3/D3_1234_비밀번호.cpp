#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int main() {
	for (int t = 1; t <= 10; t++) {
		int N;
		cin >> N;
		stack<int> st;
		int n;
		scanf("%1d", &n);
		st.push(n);
		for (int i = 1; i < N; i++) {
			scanf("%1d", &n);
			if (!st.empty()) {
				int before = st.top();
				if (before == n) st.pop();
				else st.push(n);
			}
			else st.push(n);
		}
		vector<int> res;
		printf("#%d ", t);
		while (!st.empty()) {
			int cur = st.top();
			res.push_back(cur);
			st.pop();
		}
		reverse(res.begin(), res.end());
		for (int i = 0; i < res.size(); i++)
			printf("%d", res[i]);
		printf("\n");
	}
}