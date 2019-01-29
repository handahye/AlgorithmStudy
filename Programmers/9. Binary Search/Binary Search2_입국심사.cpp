#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	sort(times.begin(), times.end());
	long long maxN = times[times.size() - 1];
	long long left = 1, right = maxN * n; //가장 적게 걸리는 시간, 오래 걸리는 시간
	answer = maxN * n;
	while (left <= right) {
		long long mid = (left + right) / 2;//중간값
		long long sum = 0;
		for (int i = 0; i<times.size(); i++)
			sum += mid / times[i];//mid초일때 i번째 심사이위원이 몇명을 통과시킬 수 있는지 
		if (sum<n) //n보다 적게 통과시키면 
			left = mid + 1;
		else {//n보다 같거나 크게 통과시키면
			answer = min(answer, mid);
			right = mid - 1;
		}
	}
	return answer;
}