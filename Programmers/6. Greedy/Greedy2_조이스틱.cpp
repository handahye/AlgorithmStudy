#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
int solution(string name) {
	int answer = 0;
	int upDown[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };
	for (int i = 0; i < name.size(); i++) {
		answer += upDown[name.at(i) - 'A'];
	} //위 아래로 움직였을 때 최소 움직임 
	int leftRight = name.size() - 1;
	int len = name.size();
	for (int i = 0; i < name.size(); i++) {
		int next = i + 1;
		while (1) {//현재 위치부터 A가 나오는 지점까지 길이 구함
			if (next == name.size() || name.at(next) != 'A') break;
			next++;
		}
		int tmp = min(i, len - next); //원점부터 앞으로 쭉 가는것과 뒤로 둘아 가는 것 중 짧은 거 
		leftRight = min(leftRight, i + (len - next) + tmp);
	}
	answer += leftRight;
	return answer;
}