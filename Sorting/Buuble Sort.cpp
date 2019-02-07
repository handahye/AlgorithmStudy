#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
[Bubble Sort]
	: 서로 인접한 두 원소를 검사하여 스왑함으로써 정렬하는 알고리즘
	가장 큰 숫자가 맨 뒤로 감. 맨 뒤는 정렬 안해도 됨
	-> Best: O(n^2)
	-> Avg: O(n^2)
	-> Worst: O(n^2)
*/
int main(){
	int n = 10;
	int arr[10] = { 41,32,6,16,38,28,19,45,43,49 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	return 0;
}