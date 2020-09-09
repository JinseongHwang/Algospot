#include <cstdio>
#include <memory.h>
using namespace std;

const int MAX = 10;
int N, M;
bool areFriends[MAX][MAX];
// taken[i]: i��° �л��� ¦�� ã�Ҵٸ� true, �ƴϸ� false
int countPairings(bool taken[MAX]) {
	int firstFree = -1;
	for (int i = 0; i < N; ++i) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	// ��� �л��� ¦�� ã������ �� ���� ����� ã������ �����Ѵ�
	if (firstFree == -1) return 1;
	int ret = 0;
	// �� �л��� ¦���� �л��� �����Ѵ�.
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
		scanf("%d %d", &N, &M); // �л� ��, ģ�� ���� ��
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