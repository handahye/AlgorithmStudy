#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
[Quick Sort] (불안정 정렬)
	: pivot을 선정해 pivot을 기준으로 작은 값 왼쪽, 큰 값 오른쪽으로 재배치 후 pivot을 가운데로 옮김
	pivot을 제외한 부분리스트의 길이가 1 혹은 0일 때까지 반복

	nlogn 의 시간 복잡도를 가지는 다른 알고리즘들보다 평균적으로 빠르고 추가 메모리 필요 X
	(pivot이 다음 정렬 단계에서 제외되므로)

	-> Best: O(nlogn)
	-> Avg: O(nlogn)
	-> Worst: O(n^2)
*/
void swap(int arr[], int low, int high) {
	int tmp = arr[low];
	arr[low] = arr[high];
	arr[high] = tmp;
}
void quickSort(int arr[], int left, int right) {
	if (left >= right) return;

	int mid = (left + right) / 2;
	int pivot = arr[mid];
	swap(arr, left, mid);

	int low = left + 1, high = right;

	while (1) {
		while (arr[low] <= pivot) low++; //pivot보다 작은동안
		while (arr[high] > pivot) high--;// pivot보다 큰동안

		if (low > high) break; 
		swap(arr, low, high);
	}
	swap(arr, left, high);

	quickSort(arr, left, high - 1);
	quickSort(arr, high +1, right);

}
int main(){
	int n = 10;
	int arr[10] = { 41,32,6,16,38,28,19,45,43,49 };
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}