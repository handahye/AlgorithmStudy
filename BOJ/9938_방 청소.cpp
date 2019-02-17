#include <iostream>
using namespace std;
/*
BOJ_9938_방 청소
1. 서랍 Ai가 비어있다면, i번 술을 그 서랍에 보관한다.
2. 서랍 Bi가 비어있다면, i번 술을 그 서랍에 보관한다.
3. Ai에 들어있는 술을 다른 서랍으로 이동시킨다.(다른 서랍은 Ai에 들어있는 술이 들어갈 수 있는 서랍 중 하나이다) 만약, 그 서랍에도 이미 술이 들어있다면, 그 술을 다른 서랍으로 이동시킨다. 이런 과정을 거쳐서 빈 서랍을 하나 찾아 술을 모두 이동할 수 있는 경우에는, 술을 이동시키고 i번 술을 Ai에 보관한다. 불가능한 경우에는 다음 규칙으로 넘어간다.
4. Bi에 들어있는 술을 다른 서랍으로 이동시킨다. 만약, 그 서랍에도 이미 술이 들어있다면, 그 술을 다른 서랍으로 이동시킨다. 이런 과정을 거쳐서 빈 서랍을 하나 찾아 술을 모두 이동할 수 있는 경우에는, 술을 이동시키고 i번 술을 Bi에 보관한다. 불가능한 경우에는 다음 규칙으로 넘어간다.
5. 위의 과정이 모두 불가능한 경우에는 i번 술을 그 자리에서 마셔버린다. (은기는 전혀 취하지 않는다)

1번 술부터 N번 술까지 순서대로 보관할 수 있는지, 그 자리에서 먹어야 하는지를 출력한다.
보관할 수 있는 경우에는 "LADICA"를, 먹어버려야 하는 경우에는 "SMECE"를 출력한다.

*/
int N, L;
int p[300001];
int full[300001];
int find(int x) { //x가 속한 트리의 루트노드 찾기
	if (x == p[x]) return x; //루트 노드는 부모 노드 번호로 자기 자신을 가짐
	else return p[x] = find(p[x]); //각 부모의 노드를 찾아 올라가기
}
void merge(int x, int y) { //x가 속한 트리와 y가 속한 트리를 합침
	x = find(x);
	y = find(y);//각각 루트노드 찾기
	p[x] = y;
	puts("LADICA");
}
int main() {
	scanf("%d %d", &N, &L);
	for (int i = 1; i <= L; i++) p[i] = i;
	for (int i = 1; i <= N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (!full[a]) {
			full[a] = true;
			merge(a, b);
		}
		else if (!full[b]) {
			full[b] = true;
			merge(b, a);
		}
		else if (!full[find(a)]) {
			full[find(a)] = true;
			merge(a, b);
		}
		else if (!full[find(b)]) {
			full[find(b)] = true;
			merge(b, a);
		}
		else puts("SMECE");
	}
	return 0;
}