// dfs와 완전탐색으로 해결,
// 정답 소스코드는 아님.

#include <iostream>
#include <string.h>
using namespace std;

const int SIZE = 5; // 보드판의 크기
char board[SIZE][SIZE]; // 보드판의 데이터가 저장됨
bool already_printed; // 출력이 되었는지 안되었는지 판별

/*  책에서 제시한 소스코드
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
	// 보드판 범위를 벗어날 경우
	if (x < 0 || x > SIZE - 1 || y < 0 || y > SIZE - 1) return;
	// 재귀를 한번도 돌지 못한 경우 ==> 첫 문자부터 일치하지 않는 경우
	if (!already_printed && x == SIZE - 1 && y == SIZE - 1 && board[y][x] != input[curr_idx]) {
		cout << "NO";
		already_printed = true;
		return;
	}
	// 현재 위치의 문자들이 일치하지 않거나, 이미 답이 출력된 경우
	if (board[y][x] != input[curr_idx] || already_printed) return; 
	// 모두 일치할 경우
	if (strlen(input) - 1 == curr_idx && !already_printed) { 
		cout << "YES";
		already_printed = true;
		return;
	}

	dfs(input, x - 1, y - 1, curr_idx + 1); // 좌상
	dfs(input, x, y - 1, curr_idx + 1); // 상
	dfs(input, x + 1, y - 1, curr_idx + 1); // 우상

	dfs(input, x - 1, y, curr_idx + 1); // 좌
	dfs(input, x + 1, y, curr_idx + 1); // 우

	dfs(input, x - 1, y + 1, curr_idx + 1); // 좌하
	dfs(input, x, y + 1, curr_idx + 1); // 하
	dfs(input, x + 1, y + 1, curr_idx + 1); // 우하
	
	// 마지막까지 일치하지 않을경우
	if (!already_printed && x == SIZE - 1 && y == SIZE - 1) {
		cout << "NO";
		already_printed = true;
		return;
	}
}

int main() {
	init();
	int testcase; cin >> testcase;
	while (testcase--) { // 보드판 데이터 입력
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				cin >> board[i][j];
			}
		}
		int num_query; cin >> num_query; // 질의문의 개수

		while (num_query--) {
			char input[11]; cin >> input; // 질의 데이터 저장
			cout << input << " ";
			for (int i = 0; i < SIZE; ++i) { // 모든 칸을 기준으로 완전 탐색
				for (int j = 0; j < SIZE; ++j) {
					dfs(input, j, i, 0);
					if (already_printed) break; // 이미 출력됐을 경우
				} if (already_printed) break;
			}
			cout << "\n";
			already_printed = false; // 초기화
		}
	}

	return 0;
}
