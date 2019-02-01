#include <iostream>
#include <algorithm>
#include<vector>
#include <string>
using namespace std;
/*
#1120_문자열
[문제]
1. 길이가 N으로 같은 문자열 X와 Y가 있음
2. 두 문자열의 X와 Y의 차이는 X[i]!=Y[i]인 i의 개수 
3. 두 문자열 A와 B가 주어지고, A의 길이는 B보다 작거나 같음
4. 같아질때 까지 A의 앞이나 뒤에 아무 알파벳 추가 가능
5. A와 B의 길이가 같으면서 A와 B의 차이를 최소로 하기

[접근방법]
1. 처음에 dfs로 접근했다가 시간초과 났음
*/
int main() {
	string a, b;
	int cnt = 0, ans = 987654321;
	cin >> a >> b;
	for (int i = 0; i <= b.size() - a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			if (a[j] != b[j + i]) ++cnt;
		}
		ans = min(cnt, ans);
		cnt = 0;
	}
	cout << ans << endl;
	return 0;
}