#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> &weight) {
	int num = 1;
	sort(weight.begin(), weight.end());
	for (int i = 0; i<weight.size(); i++) {
		if (num<weight[i]) break;//추가하려는 추의 무게가 현재까지 만들 수 있는 무게보다 커지는 경우
		num += weight[i]; //weight[i]를 하나씩 추가하는 경우 1~num까지의 무게를 만들 수 있음
	}
	return num;
}
