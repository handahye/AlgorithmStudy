#include<iostream>
#include <string>
#include <vector>
#include<map>
using namespace std;
/*
처음: dfs로 접근 
다음 방법: (type1의개수+1)*(type2의개수+1)*... -1
+1은 안 입는 경우를 고려, 마지막에 -1은 모든 옷을 입지 않는 경우까지
셌기 때문에 빼줌
*/
int solution(vector<vector<string>> clothes) {
	int res = 1;
	map<string, vector<string>> m;
	for (int i = 0; i < clothes.size(); i++)
		m[clothes[i][1]].push_back(clothes[i][0]);
	for (auto iter : m)
		res *= iter.second.size() + 1;
	return res - 1;
}
int main() {
	return 0;
}