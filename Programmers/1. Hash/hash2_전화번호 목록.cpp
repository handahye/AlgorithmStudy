#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool solution(vector<string> phone_book) {
	sort(phone_book.begin(), phone_book.end());//sort함
	for (int i = 0; i < phone_book.size() - 1; i++) {
		string s1 = phone_book[i], s2 = phone_book[i + 1];
		int len = 0;
		for (int idx = 0; idx < s1.size(); idx++) {
			if (s1[idx] != s2[idx]) break;//접두어가 다르면 멈춤
			len++;//접두어의 길이를 셈
		}
		if (len == s1.size()) return false; //센 길이와 접두어의 길이가 똑같으면 return 
	}
	return true;//접두어가 다른 경우
}
int main() {
	return 0;
}