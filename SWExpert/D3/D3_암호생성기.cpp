#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include<list>
using namespace std;

int main() {
	for (int t = 1; t <= 10; t++) {
		int T;
		scanf("%d", &T);
		list<int> num;
		for (int i = 0; i < 8; i++) {
			int tmp;
			scanf("%d", &tmp);
			num.push_back(tmp);
		}
		int cnt = 0;
		while (1) {
			if (cnt == 5) cnt = 0;
			int f = num.front();
			num.pop_front();
			f -= (cnt + 1);
			if (f <= 0) {
				num.push_back(0);
				break;
			}
			else num.push_back(f);
			cnt++;
		}
		printf("#%d ", t);
		for (auto iter : num) {
			printf("%d ", iter);
		}
		printf("\n");
	}
	
	return 0;
}
