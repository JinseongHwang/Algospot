#include <cstdio>
#include <memory.h>
using namespace std;

const int MAX = 10;
int N, M;
bool areFriends[MAX][MAX];
// taken[i]: i번째 학생이 짝을 찾았다면 true, 아니면 false
int countPairings(bool taken[MAX]) {
	int firstFree = -1;
	for (int i = 0; i < N; ++i) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	// 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다
	if (firstFree == -1) return 1;
	int ret = 0;
	// 이 학생과 짝지을 학생을 결정한다.
	for (int pairWith = firstFree + 1; pairWith < N; ++pairWith) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);

	int testcase; scanf("%d", &testcase);
	while (testcase--) {
		scanf("%d %d", &N, &M); // 학생 수, 친구 쌍의 수
		for (int a, b, i = 0; i < M; ++i) {
			scanf("%d %d", &a, &b);
			areFriends[a][b] = areFriends[b][a] = true;
		}
		bool taken[11] = { 0, };
		printf("%d\n", countPairings(taken));
		memset(areFriends, 0, sizeof(areFriends));
	}

	return 0;
}