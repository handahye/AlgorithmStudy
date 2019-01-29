#include<iostream>
using namespace std;
int arr[21], minN;
int T, N, B;
void dfs(int idx, int sum) {
	if (minN < sum || idx > N) return;
	if (minN > sum && sum >= B)
		minN = sum;

	dfs(idx+1, sum + arr[idx]);//포함
	dfs(idx+1, sum);//포함x
	
}
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> B;
		minN = 987654321;
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		dfs(0, 0);
		printf("#%d %d\n", t, minN - B);
	}
}