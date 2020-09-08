#include <cstdio>
#include <memory.h>
using namespace std;

const int MAX = 10;
int N, M;
bool areFriends[MAX][MAX];
// taken[i]: i��° �л��� ¦�� ã�Ҵٸ� true, �ƴϸ� false
int countPairings(bool taken[MAX]) {
	// ��� �л��� ¦�� ã������ �Ѱ��� ��츦 ã������ �����Ѵ�
	bool finished = true;
	for (int i = 0; i < N; ++i)
		if (!taken[i]) finished = false;
	if (finished) return 1;
	
	int ret = 0;
	// ���� ģ���� �� �л��� ã�� ¦���´�
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			//
			if (!taken[i] && !taken[j] && areFriends[i][j]) {
				taken[i] = taken[j] = true;
				ret += countPairings(taken);
				taken[i] = taken[j] = false;
			}
		}
	}
	return ret;
}

int main() {
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