#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
[Selection Sort: 불안정 정렬] 
	: n번째 자리에 어떤 원소를 넣을지 선택해 교체하는 알고리즘
	주어진 배열 중 최솟값을 찾아 n번째에 위치한 값과 교체 
	==> 위 과정을 하나의 원소가 남을 때 까지 반복

	-> Best: O(n^2)
	-> Avg: O(n^2)
	-> Worst: O(n^2)
*/
int main(){
	int n = 10;
	int arr[10] = { 41,32,6,16,38,28,19,45,43,49 };
	int index = 0;
	for (int i = 0; i < n; i++) {
		index = i; //index에 가장 작은 값을 찾아서 넣음 
		for (int j = i+1; j < n; j++) {
			if (arr[j] < arr[index]) {
				index = j;
			}
		}
		int tmp = arr[index];
		arr[index] = arr[i];
		arr[i] = tmp;
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}