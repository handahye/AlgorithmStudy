
/*Programmers_Greedy3_큰 수 만들기*/

#include <string>
#include <vector>
using namespace std;
string solution(string number, int k) {
	string answer = "";
	vector<int> v;
	for (int i = 0; i<number.size(); i++) { //int로 바꿔서 vector 삽입
		int val = number.at(i) - '0';
		v.push_back(val);
	}
	int cur = number.length() - k; //선택해야 하는 숫자 갯수
	int selectIdx = -1;//선택된 인덱스
	while (1) {
		int max = -1, maxIdx = -1;
		if (answer.length() == number.length() - k) return answer;//모두 다 선택된 경우 리턴
		for (int i = selectIdx + 1; i <= number.length() - cur; i++) {//선택된 다음 인덱스부터 선택 가능한 구간까지 for문 돌면서 가장 큰 값 찾기
			if (v[i]>max) {
				max = v[i];
				maxIdx = i;
			}
		}
		selectIdx = maxIdx;
		answer += (to_string(v[selectIdx]));
		cur--;
	}

	return answer;
}