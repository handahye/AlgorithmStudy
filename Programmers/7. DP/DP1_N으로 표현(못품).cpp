#include <set>
using namespace std;
int solution(int N, int number) {
	set<int> s[9];
	int num = N;
	for (int i = 1; i < 9; i++) {
		s[i].insert(num);
		num = num * 10 + N;
	}
	for (int i = 2; i < 9; i++) {
		int k = i - 1;
		for (int j = 1; j <= k; j++, k--) {
			for (auto num1 : s[j]) {
				for (auto num2 : s[k]) {
					s[i].insert(num1 + num2);
					s[i].insert(num1 - num2);
					s[i].insert(num2 - num1);
					s[i].insert(num1 * num2);
					if (num2>0) s[i].insert(num1 / num2);
					if (num1>0) s[i].insert(num2 / num1);
				}
			}
		}
	}
	for (int i = 1; i < 9; i++) {
		if (s[i].find(number) != s[i].end())  return i;
	}
	return -1;
}