#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int histo[4] = { 2,2,2,3 };
	int size = 4;
	int maxN = 0;
	for (int i = 0; i < size - 2; i++) { //(히스토그램의 크기 -2 )의 인덱스 일때만 물을 담을 수 있으니까
		for (int j = i + 2; j < size; j++) { // i+2부터 물을 담을 수 있음 
			int width = j - i - 1; //가로넓이
			int hight = min(histo[i], histo[j]); //세로길이가 더 짧은게 높이가 됨
			maxN = max(maxN, width*hight); //현재까지 중 가장 넓이가 넓은걸 maxN으로 설정
		}
	}
	printf("%d", maxN);
	return 0;
}