#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*구명보트 시간초과*/
int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end());
	while (!people.empty()) {
		bool flag = false;
		for (int i = people.size() - 1; i>0; i--) {
			if (people[i] + people[0] <= limit) {
				people.erase(people.begin() + i);
				people.erase(people.begin());
				answer++;
				flag = true;
				break;
			}
		}
		if (!flag) {
			people.erase(people.begin());
			answer++;
		}
	}
	return answer;
}
/*
가장 효율적으로 태울 수 있는 방법: 가장 가벼운 사람 + 가장 무거운 사람
*/
int solution(vector<int> people, int limit) {
	int answer = people.size();
	sort(people.begin(), people.end());
	int i = 0, j = people.size() - 1;
	while (i < j) {
		if (people[i] + people[j] <= limit)//가장 무거운 사람과 가장 가벼운 사람이 같이 탈 수 있는지
			i++, j--; //둘다 태움
		else if (people[i] + people[j] > limit) 
			j--;//같이 못타면 무거운 사람만 태움
	}
	return answer-i;
}