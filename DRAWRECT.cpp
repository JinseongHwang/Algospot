//#include <iostream>
//#include <utility>
//using namespace std;
//
//void init() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//}
//void ret_solo(pair<int, int>* arr) {
//	if (arr[0].first == arr[1].first) arr[3].first = arr[2].first;
//	else if(arr[0].first == arr[2].first) arr[3].first = arr[1].first;
//	else arr[3].first = arr[0].first;
//	
//	if (arr[0].second == arr[1].second) arr[3].second = arr[2].second;
//	else if (arr[0].second == arr[2].second) arr[3].second = arr[1].second;
//	else arr[3].second = arr[0].second;
//}
//int main() {
//	init();
//	int testcase; cin >> testcase;
//	for (int i = 0; i < testcase; i++) {
//		pair<int, int> coordinate[4];
//		for (int j = 0; j < 3; j++) {
//			cin >> coordinate[j].first >> coordinate[j].second;
//		}
//		ret_solo(coordinate);
//		cout << coordinate[3].first << " " << coordinate[3].second << "\n";
//		fill(&coordinate[0].first, &coordinate[3].second, 0);
//	}
//	return 0;
//}

#include <iostream>
using namespace std;
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int main() {
	init();
	int testcase; cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int x[1001]; fill(x, x + 1001, 0);
		int y[1001]; fill(y, y + 1001, 0);
		int re1, re2;
		for (int j = 0; j < 3; j++) {
			int a, b; cin >> a >> b;
			x[a]++; y[b]++;
		}
		for (int j = 0; j < 1001; j++) {
			if (x[j] == 1) re1 = j;
			if (y[j] == 1) re2 = j;
		}
		cout << re1 << " " << re2 << "\n";
	}

	return 0;
}