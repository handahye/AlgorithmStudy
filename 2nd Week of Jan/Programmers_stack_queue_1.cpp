#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string arrangement) {
	stack<char> s;
	int answer = 0;
	bool chk = false;
	for (int i = 0; i<arrangement.size(); i++) {
		if (arrangement[i] == '(') {
			s.push(arrangement[i]);
			chk = true;
		}
		else {
			s.pop();
			if (chk) answer += s.size(); //전이 여는 괄호 -> 레이저
			else answer += 1; //전이 닫는 괄호 -> 파이프의 끝   
			chk = false;
		}
	}
	return answer;
}
int main() {
	
	return 0;
}