#include <string.h>
#include <iostream>
#include <algorithm>
#include<vector>
#include<list>
using namespace std;
/*
#1021_회전하는 큐
1. 첫 번째 원소를 뽑아낸다. 이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
2. 왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
3. 오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.
4. 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값 출력
*/
int main() {
	int res = 0;
	int left, right;
	int n, m;
	vector<int> v;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	list<int> num;
	for (int i = 1; i <= n; i++) num.push_back(i);
	for (int i = 0; i < v.size(); i++) {
		int cur = num.front();
		if (cur == v[i]) {
			num.pop_front();
			continue;
		}
		else {
			auto iter = find(num.begin(), num.end(), v[i]);
			int left = distance(num.begin(), iter);
			int right = distance(iter, num.end());
			if (left <= right) {
				res += left;
				while (left--) {
					int f = num.front();
					num.pop_front();
					num.push_back(f);
				}
				num.pop_front();
			}
			else {
				res += right;
				while (right--) {
					int b = num.back();
					num.pop_back();
					num.push_front(b);
				}
				num.pop_front();
			}
		}
	}
	cout << res;
	return 0;
}