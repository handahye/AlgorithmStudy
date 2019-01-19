#include <string>
#include <vector>
#include<algorithm>
using namespace std;
int solution(string name) {
	int answer = 0;
	int left = 0, right = 0;
	answer = min(name[0] - 'A', 'Z' - name[0] + 1);
	//1. 오른쪽 A 개수 세기
	for (int i = 1;i<name.size();i++) {
		if (name[i] == 'A')right++;
		else break;
	}
	//2. 왼쪽 A 개수 세기
	for (int i = name.size() - 1;i>0;i--) {
		if (name[i] == 'A') left++;
		else break;
	}

	if (right <= left) {	//3-1) 오른쪽으로 이동하는 경우
		for (int i = 1;i<name.size() - left;i++) {
			answer++;
			answer += min(name[i] - 'A', 'Z' - name[i] + 1);
		}
	}
	else {	//3-2) 왼쪽으로 이동하는 경우
		for (int i = name.size() - 1;i>right;i--) {
			answer++;
			answer += min(name[i] - 'A', 'Z' - name[i] + 1);
		}
	}

	return answer;
}
