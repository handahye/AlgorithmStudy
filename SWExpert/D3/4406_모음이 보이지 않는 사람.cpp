#include <iostream>
#include<string>
using namespace std;
char aeiou[5] = { 'a','e','i','o','u' };
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("#%d ", t);
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			bool chk = false;
			for (int j = 0; j < 5; j++) {
				if (s[i] == aeiou[j]) chk = true;
			}
			if (!chk) printf("%c", s[i]);
		}
		printf("\n");
	}
	return 0;
}
