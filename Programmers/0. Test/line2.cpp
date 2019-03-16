#include <iostream>
#include <string>
using namespace std;
int main(void) {
	string element;
	cin >> element;
	string a, b;
	for (int i = 0; i<element.size(); i++) {
		if (element[i] >= 'A' & element[i] <= 'Z') a.push_back(element[i]);
		else if (element[i] >= '1' & element[i] <= '10') b.push_back(element[i]);
	}
	if (a.size() != b.size()) cout << "error" << endl;
	else {
		for (int i = 0; i < a.size(); i++) {
			cout << a[i];
			if (b[i] == '1') continue;
			else cout << b[i];
		}
	}
	return 0;
}