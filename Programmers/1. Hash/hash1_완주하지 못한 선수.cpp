#include <string>
#include <vector>
#include<set>
using namespace std;
string solution(vector<string> participant, vector<string> completion) {
	multiset<string> p, c;//key
	for (int i = 0; i<participant.size(); i++)
		p.insert(participant[i]);
	for (int i = 0; i<completion.size(); i++)
		c.insert(completion[i]);
	for (int i = 0; i<participant.size(); i++) {
		int pName = p.count(participant[i]);//참가자 set에 동명이인이 몇명인지(1이면 동명이인 없음)
		int cName = c.count(participant[i]);//현재 참가자 이름이 완주자 set에 몇명 있는지 
		if (pName != cName) return participant[i];//현재 참가자 이름의 갯수와 완주자에 있는 이름의 갯수가 다르면 
	}
}
int main() {
	return 0;
}

