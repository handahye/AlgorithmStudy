#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
/*16235 나무 재테크*/
using namespace std;
struct tree {
	int r, c, age;
};
int N, M, K;
int map[12][12];
int A[12][12];
int dr[] = {0,0,1,1,1,-1,-1,-1};
int dc[] = {1,-1,1,0,-1,1,0,-1};
vector<tree> v;
bool cmp(const tree &a, const tree &b) {
	if (a.r == b.r && a.c == b.c) return a.age < b.age;
	else {
		if (a.r == b.r) return a.c < b.c;
		else return a.r < b.r;
	}
}
int main() {
	int res = 0;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			map[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		v.push_back({ x,y,z});
	}
	while (K--) {
		//하나의 칸에 여러개의 나무가 있을 경우, 나이가 적은 순서로 정렬
		sort(v.begin(), v.end(), cmp);
		vector<tree> alive, dead, spread; //살아있는 나무, 죽은 나무, 퍼트릴 차례의 나무
		for (int i = 0; i < v.size(); i++) {
			int r = v[i].r, c = v[i].c;
			int age = v[i].age;

			if (map[r][c] < age) dead.push_back({ r,c,age }); //남은 양분이 나이보다 적으면 죽음
			else {
				map[r][c] -= age; //양분 나이만큼 감소시킴 
				v[i].age++;//나이 증가
				alive.push_back({ r,c,v[i].age });//alive 벡터에 삽입
				if (v[i].age % 5 == 0) spread.push_back({ r,c,v[i].age });//현재 나이가 5로 나누어 떨어지면 spread 벡터에 삽입
			}
		}
		for (int i = 0; i < dead.size(); i++) { //죽은 나무의 나이/2 만큼 양분으로 추가
			int r = dead[i].r, c = dead[i].c;
			int age = dead[i].age;
			map[r][c] += age / 2;
		}
		for (int i = 0; i < spread.size(); i++) { //퍼트러야 하는 나무 퍼트리고 alive 벡터에 삽입
			int r = spread[i].r, c = spread[i].c;
			for (int d = 0; d < 8; d++) {
				int nr = r + dr[d], nc = c + dc[d];
				if (nr >= 1 && nc >= 1 && nr <= N && nc <= N)
					alive.push_back({ nr,nc,1 });
			}
		}
		for (int i = 1; i <= N; i++) //땅에 양분 추가
			for (int j = 1; j <= N; j++)
				map[i][j] += A[i][j];

		v.clear(); //v벡터 비우고
		for (int i = 0; i < alive.size(); i++) {
			int r = alive[i].r, c = alive[i].c;
			int age = alive[i].age;
			v.push_back({ r,c,age }); //alive 벡터에 들어있는 나무를 v벡터에 담음
		}
		alive.clear();
		dead.clear();
		spread.clear();
		//초기화해줌
		res = v.size(); //v 벡터의 크기만큼이 현재 살아있는 나무
	}
	printf("%d", res);
	return 0;
}
