#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
#19236 청소년 상어
상어가 먹을 수 있는 최대 물고기 수 구하기~
1) 물고기 이동
   - 물고기는 번호가 작은 순서로 움직 움직
   - 만약 상어랑 만나거나 map 벗어나면 반시계 방향으로 45도 각도 틈
	 (1) 이동 가넝하면 그 물고기랑 자리 체인지
	 (2) 이동 안되면 그 자리에 가마니~~~
	- 해당 방향으로 이동 가능하면 그 자리에 있는 물고기랑 자리 바꿩

2) 상어 이동
   - 해당 방향으로 여러칸 이동 가능~~~! (전부 다 따져야 함)

* 고려해야할 사항..
  우선순위 큐 !! 써서 숫자가 작은 순서대로 나오게 .. ?
*/

struct node
{
	int r, c, dir;
};
int res = 1;
int sharkR = 0, sharkC = 0, sharkDir;
vector<node> fish(17);
priority_queue<int> que;
int dr[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int map[4][4] = {
	0,
};
bool canMove(int r, int c)
{
	if (r == sharkR && c == sharkC)
		return false;
	if (r < 0 || c < 0 || r > 3 || c > 3)
		return false;
	return true;
}
void change(int r1, int c1, int num1, int r2, int c2, int num2)
{
	map[r1][c1] = num2;
	map[r2][c2] = num1;

	fish[num1].r = r2;
	fish[num1].c = c2;
	fish[num2].r = r1;
	fish[num2].c = c1;
}
void moveFish()
{
	int fsize = que.size();
	//물고기 이동
	for (int i = 0; i < fsize; i++)
	{
		int num = que.top();

		int r = fish[num].r;
		int c = fish[num].c;
		int dir = fish[num].dir;

		int nr = r + dr[dir];
		int nc = c + dc[dir];
		if (canMove(nr, nc))
		{
			change(r, c, num, nr, nc, map[nr][nc]);
		}
		else
		{
			int cnt = 0;
			while (1)
			{
				if (cnt == 7)
					break; //모든 방향 다 체크해서 안되면 가만히

				dir++;
				if (dir == 9)
					dir = 1;
				int rr = r + dr[dir];
				int cc = c + dc[dir];
				if (canMove(rr, cc))
				{
					change(r, c, num, rr, cc, map[rr][cc]);
					fish[num].dir = dir;
					break;
				}
				cnt++;
			}
		}
	}
}

void moveShark(int r, int c, int dir, int cnt)
{
	if (cnt > res)
		res = cnt;

	int nr = sharkDir + dr[sharkDir];
	int nc = sharkDir + dc[sharkDir];
	if (nr < 0 || nc < 0 || nr > 3 || nc > 3)
		return; // 앞으로 계속 이동하는거니께 안봐도 됨!
	if (map[nr][nc] > 0)
	{
		priority_queue<int> tque = que;
		vector<node> tfish = fish;
		int tmp[4][4];
		memcpy(tmp, map, sizeof(tmp));

		map[nr][nc] = -1;
		res++;
		moveFish();
		moveShark(nr, nc, map[nr][nc], cnt + 1);

		que = tque;
		fish = tfish;
		memcpy(map, tmp, sizeof(tmp));
	}
}

int main()
{
	queue<node> shark;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int num, dir;
			cin >> num >> dir;
			if (i == 0 && j == 0)
			{
				sharkDir = dir;
				continue;
			}
			map[i][j] = num;
			que.push(-num);
			fish[num].r = i;
			fish[num].c = j;
			fish[num].dir = dir;
		}
	}
	// shark.push({sharkR, sharkC, sharkDir});
	map[sharkR][sharkC] = -1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	moveFish();
	for (int i = 0; i < 3; i++)
	{
		moveShark(sharkR, sharkC, sharkDir, 1);
		sharkR += dr[sharkDir];
		sharkC += dc[sharkDir];
	}
	cout << res;
	return 0;
}