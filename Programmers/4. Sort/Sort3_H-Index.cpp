#i#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
1. 내림 차순으로 정렬
2. h-index를 하나씩 증가시키다가 
현재 h-index가 citations보다 커지는 순간 멈춤
citations에 들어있는 숫자 이상 인용된거니까
*/
bool compare(int &a, int &b) {
	return a > b;
}
int solution(vector<int> citations) {
	sort(citations.begin(), citations.end(), compare);
	int h_idx = 0;
	while (1) {
		if (citations[h_idx] < h_idx+1) break;
		if (h_idx == citations.size()) break;
		h_idx++;
	}
	return h_idx;
}
int main() {
	
	return 0;
}