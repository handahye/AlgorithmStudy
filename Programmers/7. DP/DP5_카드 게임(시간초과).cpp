#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int score[2002][2002], maxScore, n;
void dfs(int i, int j, int curScore, vector<int> left, vector<int> right) {
	if ((curScore <= score[i][j]) || (i == n + 1 || j == n + 1)) return;
	if (curScore>score[i][j]) {//i번째 왼쪽 카드, j번째 오른쪽 카드 위치일 때, 가장 큰 값이 되는 score
		score[i][j] = curScore;
		maxScore = max(curScore, maxScore);
	}
	if (left[i]>right[j]) { //오른쪽 카드가 더 작으면
		dfs(i, j + 1, score[i][j] + right[j], left, right);//오른쪽 카드 버림
	}
	else {
		dfs(i + 1, j, curScore, left, right);//왼쪽 카드 버리기
		dfs(i + 1, j + 1, curScore, left, right);//왼쪽 오른쪽 카드 버리기
	}
}
int solution(vector<int> left, vector<int> right) {
	maxScore = 0;
	n = left.size();
	memset(score, -1, sizeof(score));
	dfs(0, 0, 0, left, right);
	return maxScore;
}