#include <vector>
#include <string.h>
using namespace std;
bool visit[501 * 501];
int solution(vector<vector<int>> board, vector<int> nums) { //빙고판, 순서대로 지운숫자
	int answer = 0;
	memset(visit, false, sizeof(visit));
	for (int i = 0; i<nums.size(); i++) visit[nums[i]] = true;
	//오른쪽
	for (int i = 0; i<board.size(); i++) {
		bool chk = true;
		for (int j = 0; j<board.size(); j++) {
			if (!visit[board[i][j]]) {
				chk = false;
				break;
			}
		}
		if (chk) answer++;
		chk = true;
		for (int j = 0; j<board.size(); j++) {
			if (!visit[board[j][i]]) {
				chk = false;
				break;
			}
		}
		if (chk) answer++;
	}

	//오른쪽 아래 대각선
	bool chk = true;
	for (int i = 0; i<board.size(); i++) {
		if (!visit[board[i][i]]) {
			chk = false;
			break;
		}
	}
	if (chk) answer++;
	//왼쪽 아래 대각선
	chk = true;
	for (int i = 0; i<board.size(); i++) {
		if (!visit[board[board.size() - i - 1][i]]) {
			chk = false;
			break;
		}
	}
	if (chk) answer++;
	return answer;
}