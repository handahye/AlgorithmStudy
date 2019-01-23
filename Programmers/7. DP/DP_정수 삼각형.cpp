#include <string>
#include <vector>
using namespace std;
int solution(vector<vector<int>> triangle) {
	for (int i = triangle.size() - 2; i >= 0; i--) {
		for (int j = 0; j<triangle[i].size(); j++) {
			int left = triangle[i + 1][j];
			int right = triangle[i + 1][j + 1];
			triangle[i][j] = max(triangle[i][j] + left, triangle[i][j] + right);
		}
	}
	return triangle[0][0];
}