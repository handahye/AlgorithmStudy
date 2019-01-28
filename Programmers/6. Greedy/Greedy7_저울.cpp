#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> weight) {
	int sum = 1;//가장 작은 추의 무게가 1이니까 맨 처음 만들 수 있는 무게는 1
	sort(weight.begin(), weight.end());
	for (int i = 0; i<weight.size(); i++) {
		if (sum < weight[i]) break;//현재 1~sum까지의 무게를 만들 수 있는데 최대 무게인 sum보다 추의 무게가 커지면 안됨
		num += weight[i]; //현재 sum에 추의 무게를 추가함 
	}
	return num;
}