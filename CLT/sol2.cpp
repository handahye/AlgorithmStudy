#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool cmp1(pair<int, int> &a, pair<int, int>&b) {
	return a.second > b.second;
}
bool cmp2(pair<int, int>&a, pair<int, int> &b) {
	return a.first < b.first;
}
int main() {
	int grade[4] = { 3,2,1,2 };
	vector<pair<int, int>> v; //번호, 점수
	vector<pair<int, int>> ans;//번호, 등수
	for (int i = 1; i <= 4; i++) v.push_back({ i,grade[i - 1] });
	sort(v.begin(), v.end(), cmp1);//점수 순으로 정렬

	int num = 1; //등수
	ans.push_back({ v[0].first, num });

	for (int i = 1; i<v.size(); i++) {
		if (v[i].second == v[i - 1].second) { //점수가 동일하면
			ans.push_back({ v[i].first, num });
		}
		else { //점수가 다르면
			num = ans.size() + 1; //지금까지 ans에 들어있는 학생수 +1 등이 현재 등수가 됨
			ans.push_back({ v[i].first, num });
		}
	}
	sort(ans.begin(), ans.end(), cmp2); //번호 순으로 정렬
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i].second);
	return 0;
}