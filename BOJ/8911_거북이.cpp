#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		string comm;
		cin >> comm;
		int d = 0;
		int r = 0, c = 0;
		int minR = 0, maxR = 0, minC = 0, maxC = 0;
		for (int j = 0; j < comm.size(); j++) {
			if (comm[j] == 'L') d = (d + 1) % 4;
			else if (comm[j] == 'R') d = (d + 3) % 4;
			else if (comm[j] == 'F') r+= dr[d],c+= dc[d];
			else if (comm[j] == 'B') r-=dr[d], c-=dc[d];
			minR = min(r, minR);
			minC = min(c, minC);
			maxR = max(r, maxR);
			maxC = max(c, maxC);
		}
		printf("%d\n", (maxR - minR)*(maxC - minC));
	}
	return 0;
}