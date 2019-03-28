#include <iostream>
#include<algorithm>
#include<set>
#include<string>
#include<functional>
using namespace std;
int N, K;
long long res;
long long cal(string s) {
	long long res = 0;
	long long hex = 1;
	for (int i = s.size()-1; i >=0 ; i--) {
		int num; 
		if(s[i]>='0' && s[i]<='9') num = s[i] - '0';
		else num = s[i] - '0' - 7;
		res += hex * num;
		hex *= 16;
	}
	return res;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &N, &K);
		string s;
		cin >> s;
		set<long long,greater<long long>> num;
		int n = N / 4; //한 변에 들어가야하는 숫자의 개수
		for (int i = 0; i < n; i++) { //rotate 수
			int cur = i;
			for (int j = 0; j < 4; j++) { //한 변
				string tmp = "";
				for (int k = 0; k < n; k++) {
					tmp += s[(cur + k)%N];
				}
				num.insert(cal(tmp));
				cur += n;
			}
		}
		int k = 1;
		for (auto iter : num) {
			if (k == K) {
				printf("#%d %d\n", t, iter);
				break;
			}
			k++;
		}
	}
	return 0;
}
