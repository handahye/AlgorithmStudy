#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		vector<string> card, res;
		int N;
		scanf("%d", &N);
		int n;
		if (N % 2 == 0) n = N / 2;
		else n = N / 2 + 1;
		for (int i = 0; i < N; i++) {
			string tmp;
			cin >> tmp;
			card.push_back(tmp);
		}
		for (int i = 0; i <= N / 2; i++,n++) {
			res.push_back(card[i]);
			if(n<N) res.push_back(card[n]);
		}
		printf("#%d ", t);
		for (int i = 0; i < N; i++)
			cout << res[i]<<" ";
		printf("\n");

	}
	return 0;
}