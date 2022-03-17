#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
#19236 û�ҳ� ���
�� ���� �� �ִ� �ִ� ����� �� ���ϱ�~
1) ����� �̵�
   - ������ ��ȣ�� ���� ������ ���� ����
   - ���� ���� �����ų� map ����� �ݽð� �������� 45�� ���� ƴ
	 (1) �̵� �����ϸ� �� ������ �ڸ� ü����
	 (2) �̵� �ȵǸ� �� �ڸ��� ������~~~
	- �ش� �������� �̵� �����ϸ� �� �ڸ��� �ִ� ������ �ڸ� �ٲ�

2) ��� �̵�
   - �ش� �������� ����ĭ �̵� ����~~~! (���� �� ������ ��)

* ����ؾ��� ����..
  �켱���� ť !! �Ἥ ���ڰ� ���� ������� ������ .. ?
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
	//����� �̵�
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
					break; //��� ���� �� üũ�ؼ� �ȵǸ� ������

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
		return; // ������ ��� �̵��ϴ°Ŵϲ� �Ⱥ��� ��!
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