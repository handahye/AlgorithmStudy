#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
1. 진출 지점이 오름차순이 되도록 정렬
2. 가장 빠른 진출 지점에 카메라를 설치함
3. 다음영역을 탐색하면서 포함되지 않으면 그 지점에 카메라 다시 설치
4. 위 반복..
*/
bool cmp(vector<int>&a, vector<int>&b) {
	return a[1]<b[1];
}
int solution(vector<vector<int>> routes) {
	int answer = 0;
	int camera = 0, cur = 0, carNum = 0;
	sort(routes.begin(), routes.end(), cmp);//정렬
	while (1) {
		if (carNum == routes.size()) return answer; //모든 차를 다 체크했을 때 정답 리턴
		camera = routes[cur][1]; //카메라 설치 지점
		answer++;
		carNum++;
		for (int i = cur + 1; i < routes.size(); i++) { //다음 영역을 탐색하면서 포함되지 않는 지점 찾기
			if (routes[i][0] > routes[cur][1]) {
				cur = i;//이 지점부터 다시 카메라 설치 
				break;
			}
			carNum++;//차갯수 세기
		}
	}
}
