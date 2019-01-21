#include <string>
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
**처음 접근한 방법**
1. vector<string>에 numbers의 숫자를 넣은 뒤, 내림차순으로 정렬
  <3, 30, 34, 5, 9 ---> 9, 5, 34, 30, 3>

2. 두자리 수 이상인 경우, 맨 앞의 숫자를 기준으로
	1) 맨 왼쪽 숫자보다 그 다음 숫자가 크면 앞에 둠
	2) 맨 왼쪽 숫자보다 그 다음 숫자가 작으면 뒤에 둠 (첫 idx를 저장해둠)

3. 한자리 수 인 경우,
	만약 2-2)에서 숫자가 들어갔으면 저장한 idx에 숫자를 넣음
	안들어 갔으면 그냥 숫자 삽입
ex) [6, 671, 619] -> 671 6 619

==> 하지만 이렇게 풀면 [12, 121] 인 경우 12 121이 정답이지만, 
내 풀이는 121 12가 나오게 된다.
*/
string solution(vector<int> numbers) {
	string answer = "";
	vector<string> s;
	for (int i = 0; i < numbers.size(); i++) s.push_back(to_string(numbers[i]));
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());

	int chk[10] = { 0, };
	int idx = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i].size() > 1 && s[i].at(1) >= s[i].at(0)) answer += s[i];
		else if (s[i].size() > 1 && s[i].at(1) < s[i].at(0)) {
			if (!chk[s[i].at(0) - '0']) idx = answer.size(); //인덱스 저장
			answer += s[i];
			chk[s[i].at(0) - '0'] = true;
		}
		else if (s[i].size() == 1) {
			if (chk[s[i].at(0) - '0']) {
				answer.insert(idx, s[i]);
			}
			else answer += s[i].at(0);
		}
	}
	if (answer.at(0) == '0') return "0";
	else return answer;
}

/*
**다른 사람 코드 참고**
string을 정렬 시킬때 앞 뒤 두수를 바꿔 더해서 
뭐가 더 큰지 비교하면서 정렬시킴,,

[121, 12]
num1: 121+12 = 12112
num2: 12+121 = 12121 

12121>12112 

+) answer의 첫번째 idx가 0인 경우는 무조건 0 
answer에 [0, 0, 0, 0] 이런식으로 0이 중복되어 들어간 경우가 있어서 
*/
bool compare(const string &a, const string &b) {
	string num1 = a + b;
	string num2 = b + a;
	if (num1 > num2) return true;
	else return false;
}
string solution(vector<int> numbers) {
	string answer = "";
	vector<string> s;
	for (int i = 0; i <numbers.size(); i++) s.push_back(to_string(numbers[i]));//string으로 바꿔줌
	sort(s.begin(), s.end(), compare);//정렬
	for (int i = 0; i<s.size(); i++) answer += s[i];
	if (answer.at(0) == '0') return "0";
	else return answer;
}