#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<stack>
#include<math.h>
using namespace std;
/*
D4_괄호 짝짓기
*/
bool chkBar(char a, char b) {
	if (a == '('&&b == ')') return true;
	else if (a == '{'&&b == '}') return true;
	else if (a == '['&&b == ']') return true;
	else if (a == '<'&&b == '>') return true;
	else return false;
}
int main() {
	//int T;
	//cin >> T;
	for (int t = 1; t <= 10; t++) {
		bool chk = true;
		int N;
		cin >> N;
		vector<char> v;
		for (int i = 0; i < N; i++) {
			char c;
			cin >> c;
			v.push_back(c);
		}
		stack<char> s;
		if (v[0] == '(' || v[0] == '{' || v[0] == '[' || v[0] == '<') s.push(v[0]); //처음이 여는 괄호면 stack에 넣기
		else chk = false; //처음이 닫는 괄호면 안되는 경우
		int idx = 0;
		while (!s.empty()) {
			idx++;
			if (v[idx] == '(' || v[idx] == '{' || v[idx] == '[' || v[idx] == '<') {
				s.push(v[idx]);
				continue; //여는 괄호가 나오면 계속 stack에 넣음
			}
			else {
				char t = s.top(); //닫는 괄호가 나오면 바로 전의 여는 괄호와 쌍인지 확인
				if (chkBar(t, v[idx])) {
					s.pop();
					continue;
				}
				else { //쌍이 아니면 안되는 경우
					chk = false;
					break;
				}
			}
		}
		if(!chk)
			cout << "#" << t << " " <<"0"<< endl;
		else
			cout << "#" << t << " " << "1" << endl;
	}
	return 0;
}