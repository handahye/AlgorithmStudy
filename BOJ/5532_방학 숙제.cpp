#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
#5532_방학 숙제
[문제]
1. 방학은 총 L일, 수학 B페이지, 국어 A페이지 풀어야됨
2. 상근이는 하루에 국어 최대 C페이지, 수학 최대 D페이지 풀기 가능
3. 방학 때 숙제 안하고 놀 수 있는 최대 날의 수 구하기
*/
int main() {
	int res = 0;
	int L, A, B, C, D;
	cin >> L >> A >> B>>C>>D;
	res = L;
	int a = ceil(float(A) / float(C));
	int b = ceil(float(B) / float(D));
	printf("%d", res-(max(a,b)));
	return 0;
}