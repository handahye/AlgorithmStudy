#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
[Merge Sort]
	: 분할 정복 알고리즘의 하나
	레코드 배열의 길이가 1이 될 때까지 쪼갠 후 합병하는 과정에서 정렬 수행
	i) 2개의 리스트의 값들을 처음부터 하나씩 비교하여 작은 값을 새로운 리스트(Sorted)로 옮김
	ii) 두 리스트 중 하나가 끝날 때 까지 반복
	iii) 남은 리스트의 값들을 새로운 리스트(Sorted)의 뒤로 복사

	추가적인 공간이 소요될 수 있음
	==> 레코드가 많을 경우 연결리스트를 사용하면 인덱스만 변경하면 되기 때문에 가장 효율적인 정렬 방식

	-> Best: O(nlogn)
	-> Avg: O(nlogn)
	-> Worst: O(nlogn)
*/
int sorted[10]; //추가적인 공간
void merge(int arr[], int left, int mid, int right) {
	int i, j, k;
	i = left, j = mid + 1, k = left;

	//분할 정렬된 list의 합병
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) sorted[k++] = arr[i++];
		else sorted[k++] = arr[j++];
	}
	//남아 있는 값들 복사
	if (i > mid) {
		for (int l = j; l <= right; l++)
			sorted[k++] = arr[l];
	}
	else {
		for (int l = i; l <= mid; l++)
			sorted[k++] = arr[l];
	}

	//임시 배열을 arr로 다시 재복사함
	for (int l = left; l <= right; l++)
		arr[l] = sorted[l];
}
void divide(int arr[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		divide(arr, left, mid);
		divide(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}
int main(){
	int n = 10;
	int arr[10] = { 41,32,6,16,38,28,19,45,43,49 };
	divide(arr, 0, n - 1);
	return 0;
}