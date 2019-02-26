#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
using namespace std;
int card[3][10];
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int cnt = 0;
		string num, color;
		cin >> num >> color;
		memset(card, 0, sizeof(card));
		for (int i = 0; i < 9; i++) {
			if (color[i] == 'R')card[0][num[i] - '0']++;
			else if(color[i]=='G')card[1][num[i] - '0']++;
			else card[2][num[i] - '0']++;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 1; j <= 9; j++) {
				if (card[i][j] >= 3) {
					card[i][j] -= 3;
					cnt++;
					j -= 1;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 1; j <= 7; j++) {
				if (card[i][j] > 0 && card[i][j + 1] > 0 && card[i][j + 2] > 0) {
					card[i][j]--;
					card[i][j + 1]--;
					card[i][j + 2]--;
					cnt++;
					j -= 1;
				}
			}
		}
		if (cnt==3) printf("#%d Win\n", t);
		else printf("#%d Continue\n", t);
	}
	
	return 0;
}