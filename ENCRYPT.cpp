#include <iostream>
#include <cstring>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int main() {
	init();
	int testcase; cin >> testcase;
	while (testcase--) {
		char input[101]; cin >> input;
		for (int i = 0; i < strlen(input); i += 2) {
			cout << input[i];
		}
		for (int i = 1; i < strlen(input); i += 2) {
			cout << input[i];
		}
		cout << "\n";
	}
	return 0;
}