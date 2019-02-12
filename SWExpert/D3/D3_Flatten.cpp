#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std;
/*
D3_Flatten
*/
int main() {
	//int T;
	//cin >> T;
	for (int t = 1; t <= 10; t++) {
		int dump;
		cin >> dump;
		vector<int> box;
		for (int i = 0; i < 100; i++) {
			int h;
			cin >> h;
			box.push_back(h);
		}
		sort(box.begin(), box.end());
		while (dump--) {
			//if (dump == 0 || (box[99] - box[0]) <= 1) break;
			if ((box[99] - box[0]) <= 1) break;
			box[99]--;
			box[0]++;
			sort(box.begin(), box.end());
		}
		cout << "#" << t << " " <<box[99]-box[0]<< endl;
	}
	return 0;
}