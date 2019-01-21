#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const vector<int> &a, const vector<int> &b){
	return a[0] < b[0];
}
int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int curTime = 0;
	int Jobsize = jobs.size();
	sort(jobs.begin(), jobs.end(), cmp);
	while (!jobs.empty()){
		int curIdx = 0;
		int minN = 987654321;
		for (int i = 0; i < jobs.size(); i++){
			if (curTime >= jobs[i][0]) { //현재 시간에서 시작할 수 있는 작업들
				if (minN >= curTime + jobs[i][1]){//그 중 가장 빨리 끝나는 작업 찾기
					minN = curTime + jobs[i][1];
					curIdx = i;
				}
			}
		}
		if (jobs.empty()) break;
		if (minN == 987654321) {//현재 시간에서 시작할 수 없는 작업이 없으면 시간 증가
			curTime++;
		}
		else {
			int startTime = jobs[curIdx][0];
			curTime = minN;
			answer += (curTime - startTime);//총 소요시간
			jobs.erase(jobs.begin() + curIdx);//vector에서 삭제해줌
		}
	}
	return answer / Jobsize;
}