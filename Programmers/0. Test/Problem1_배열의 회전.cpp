#include <string>
#include <vector>
#include <list>
/*
프로그래머스 모의고사 
문제 1: 배열의 회전
*/
using namespace std;
bool solution(vector<int> arrA, vector<int> arrB) {
	list<int> l;
	int cnt = arrA.size();
	for (int i = 0; i<arrA.size(); i++) l.push_back(arrA[i]);
	while (cnt--) {
		int back = l.back();
		l.pop_back();
		l.push_front(back);
		bool chk = true;
		int i = 0;
		for (auto iter : l) {
			if (iter == arrB[i])i++;
			else {
				chk = false;
				break;
			}
		}
		if (chk) return true;
	}
	return false;
}