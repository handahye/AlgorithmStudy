#include <iostream>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;
int main() {
	int n, w, l;
	scanf("%d%d%d", &n, &w, &l);
	queue<int> q;
	int time = 0, sum = 0;
	while (n--) {
		int t;
		scanf("%d", &t);
		while (1) {
			if (q.empty()) {
				q.push(t);
				sum += t;
				time++;
				break;
			}
			else if (q.size() == w) {
				sum -= q.front();
				q.pop();
			}
			else {
				if (sum + t > l) {
					q.push(0);
					time++;
				}
				else {
					sum += t;
					q.push(t);
					time++;
					break;
				}

			}
		}
	}
	printf("%d", time + w);
	
	return 0;
}