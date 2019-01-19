#include <string>
#include <vector>
using namespace std;
vector<int> solution(int brown, int red) {
	vector<int> answer;
	for (int r = 3; r<brown / 2; r++) {
		int c = (brown - (r * 2)) / 2 + 2;
		int total = r * c;
		if (total - brown == red && r >= c) {
			answer.push_back(r);
			answer.push_back(c);
			return answer;
		}
	}
}