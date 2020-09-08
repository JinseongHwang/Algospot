#include <iostream>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int main() {
	init();
	int testcase; cin >> testcase;
	while (testcase--) {
		int goal; cin >> goal;
		for (int i = 0; i < 9; i++) {
			int used; cin >> used;
			goal -= used;
		}
		if (goal >= 0) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}