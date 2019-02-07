#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
[Insertion Sort]
	: "두 번째" 원소부터 시작해 앞쪽의 자료들과 비교해 삽입될 위치를 찾고, 나머지 자료들을 뒤로 이동
	자료가 적고 대부분이 정렬되어 있을 경우에 효율적일 수 있음 
	-> Best: O(n)
	-> Avg: O(n^2)
	-> Worst: O(n^2)
*/
int main(){
	int n = 10;
	int arr[10] = { 41,32,6,16,38,28,19,45,43,49 };
	int i, j;
	for (i = 1; i < n; i++) { //두번째 원소부터 시작! 
		int key = arr[i];
		for (j = i-1; j>=0; j--) {
			if (arr[j] > key) {
				arr[j + 1] = arr[j]; //한칸씩 밀어야 함
			}
			else break; //앞쪽은 이미 정렬되어 있으므로 더 작은 값이 없음
		}
		arr[j + 1] = key;
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}