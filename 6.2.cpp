#include <iostream>
#include <vector>
using namespace std;

void printPicked(vector<int>& picked) {
	for (const auto& curr : picked) cout << curr << " ";
	cout << "\n";
}

void pick(int n, vector<int>& picked, int toPick) {
	if (toPick == 0) {
		printPicked(picked); return;
	}
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}

int main() {
	vector<int> v;
	cout << "������ ���� �Է� ==> ";
	int n; cin >> n;
	cout << "�� ���� ���� ==> ";
	int m; cin >> m;
	cout << " >>> ��� ����� ���� �����ϸ� ������ �����ϴ�.\n";
	pick(n, v, m);
	return 0;
}