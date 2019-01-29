#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0, N = budgets.size();
	sort(budgets.begin(), budgets.end());//오름차순 정렬
	int left = 0, right = budgets[N - 1];
	while (left <= right) {
		int mid = (left + right) / 2;//(left+right)/2한 값을 상한액으로 정함
		int sum = 0;
		for (int i = 0; i<N; i++)
			sum += min(budgets[i], mid);//상한액보다 작으면 그값, 크면 상한액
		if (sum <= M) {//더한값이 M보다 작으면
			answer = mid;
			left = mid + 1;//left를 상한액+1로 잡음
		}
		else right = mid - 1;//right를 상한액-1로 잡음

	}
	return answer;
}