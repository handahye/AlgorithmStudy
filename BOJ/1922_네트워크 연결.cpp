 #include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
#include<set>
using namespace std;
/*크루스칼 알고리즘*/
int N, M, res;
int parent[100001];
vector <pair<int, pair<int, int>>> e;
int find(int x) { //부모노드 찾기
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}
void Union(int x, int y) {//부모노드가 다르면 합쳐줌
	x = find(x);
	y = find(y);
	if (x != y) parent[y] = x;//x의 부모노드로 y의 부모노드를 바꿔줌
}
bool sameParent(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return true;
	else return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		e.push_back({ c,{a,b} });
	}
	sort(e.begin(), e.end());
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 0; i < M; i++) {
		int u = e[i].second.first, v = e[i].second.second;
		if (!sameParent(u, v)) {//부모노드가 다르면
			Union(u, v);//이어준다
			res += e[i].first;
		}
	}
	printf("%d", res);
	return 0;
}