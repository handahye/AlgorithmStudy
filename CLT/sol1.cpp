#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int cal(string s1, string s2) {
	int maxN = 0;
	int s1Len = s1.size()-1; //s1의 길이
	for (int i = s2.size()-1; i >=0; i--) {
		bool flag = false;
		if (s2[i] == s1[s1Len]) { //현재 s2가 가르키는 알파벳과 s1의 마지막 알파벳이 같으면
			int cnt = 1;
			for (int j = i-1, k = s1Len-1; j >= 0; j--, k--) { //그 앞도 알파벳이 겹치는지 확인
				if (s2[j] != s1[k] || k<0) { //알파벳이 다른 경우 or s1: bc s2: abc 이런 경우 s1은 앞에 더이상 확인할게 없음(k<0)
					flag = true;
					break;
				}
				else cnt++; //같으면 겹치는 부분 세기
			}
			if (!flag) maxN = max(cnt, maxN); //겹치는거 센것중 가장 큰값을 maxN로 설정
		}
	}
	return maxN;
}
int main(){
	string s1 = "ababc", s2 = "abcdab";
	//s1->s2 순서로 붙인것과 s2->s1 순서로 붙인것 중에 겹쳐지 글자가 더 많은 걸 res에 저장
	int res = max(cal(s1, s2), cal(s2, s1));
	printf("%d", s1.size() + s2.size() - res); //s1의 길이+s2의 길이 - 겹쳐지는 알파벳수
	return 0;
}