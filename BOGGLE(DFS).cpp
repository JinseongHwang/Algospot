// dfs�� ����Ž������ �ذ�,
// ���� �ҽ��ڵ�� �ƴ�.

#include <iostream>
#include <string.h>
using namespace std;

const int SIZE = 5; // �������� ũ��
char board[SIZE][SIZE]; // �������� �����Ͱ� �����
bool already_printed; // ����� �Ǿ����� �ȵǾ����� �Ǻ�

/*  å���� ������ �ҽ��ڵ�
const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };
bool hasWord(int y, int x, const string& word) {
	if (!inRange(y, x)) return false;
	if (board[y][x] != word[0]) return false;
	if (word.size() == 1) return true;
	for (int direction = 0; direction < 8; ++direction) {
		int nextY = y + dy[direction], nextX = x + dx[direction];
		if (hasWord(nextY, nextX, word.substr(1))) return true;
	}
	return false;
} */

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

void dfs(char input[], int x, int y, int curr_idx) {
	// ������ ������ ��� ���
	if (x < 0 || x > SIZE - 1 || y < 0 || y > SIZE - 1) return;
	// ��͸� �ѹ��� ���� ���� ��� ==> ù ���ں��� ��ġ���� �ʴ� ���
	if (!already_printed && x == SIZE - 1 && y == SIZE - 1 && board[y][x] != input[curr_idx]) {
		cout << "NO";
		already_printed = true;
		return;
	}
	// ���� ��ġ�� ���ڵ��� ��ġ���� �ʰų�, �̹� ���� ��µ� ���
	if (board[y][x] != input[curr_idx] || already_printed) return; 
	// ��� ��ġ�� ���
	if (strlen(input) - 1 == curr_idx && !already_printed) { 
		cout << "YES";
		already_printed = true;
		return;
	}

	dfs(input, x - 1, y - 1, curr_idx + 1); // �»�
	dfs(input, x, y - 1, curr_idx + 1); // ��
	dfs(input, x + 1, y - 1, curr_idx + 1); // ���

	dfs(input, x - 1, y, curr_idx + 1); // ��
	dfs(input, x + 1, y, curr_idx + 1); // ��

	dfs(input, x - 1, y + 1, curr_idx + 1); // ����
	dfs(input, x, y + 1, curr_idx + 1); // ��
	dfs(input, x + 1, y + 1, curr_idx + 1); // ����
	
	// ���������� ��ġ���� �������
	if (!already_printed && x == SIZE - 1 && y == SIZE - 1) {
		cout << "NO";
		already_printed = true;
		return;
	}
}

int main() {
	init();
	int testcase; cin >> testcase;
	while (testcase--) { // ������ ������ �Է�
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				cin >> board[i][j];
			}
		}
		int num_query; cin >> num_query; // ���ǹ��� ����

		while (num_query--) {
			char input[11]; cin >> input; // ���� ������ ����
			cout << input << " ";
			for (int i = 0; i < SIZE; ++i) { // ��� ĭ�� �������� ���� Ž��
				for (int j = 0; j < SIZE; ++j) {
					dfs(input, j, i, 0);
					if (already_printed) break; // �̹� ��µ��� ���
				} if (already_printed) break;
			}
			cout << "\n";
			already_printed = false; // �ʱ�ȭ
		}
	}

	return 0;
}
