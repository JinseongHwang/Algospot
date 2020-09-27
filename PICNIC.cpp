// å �ҽ��ڵ�

#include <cstdio>
#include <memory.h>
using namespace std;

const int MAX = 10;
int N, M;
bool areFriends[MAX][MAX];
// taken[i]: i��° �л��� ¦�� ã�Ҵٸ� true, �ƴϸ� false
int countPairings(bool taken[MAX]) {
	int firstFree = -1; // ¦�� ã�� ���� ģ�� �� ���� ���� ��ȣ�� ����
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
		// ¦ ���� ģ���� ¦�� ���� && ���� ģ����� => ¦���� �����ش�.
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
		bool taken[MAX] = { 0, };
		printf("%d\n", countPairings(taken));
		memset(areFriends, 0, sizeof(areFriends));
	}

	return 0;
}


// �ٽ� Ǯ�

#include <cstdio>
#include <memory.h>
using namespace std;

int N, M; // �л� ��, ���� ��
bool areFriends[11][11], isused[11]; // isused[i]: i�� �л��� ¦�� ã�Ҵٸ� true, ������ false

int countingPairs() {
	int solo = -1;
	for (int i = 0; i < N; ++i) {
		if (!isused[i]) {
			solo = i;
			break;
		}
	}
	if (solo == -1) return 1;

	int res = 0;
	// 0���Ͱ� �ƴ�, ���� �ַ� + 1������ �����ϸ� ���� Ƚ���� �� ���� �� �ְ���?
	for (int another = 0; another < N; ++another) {
		if (!isused[another] && areFriends[solo][another]) {
			isused[solo] = isused[another] = true;
			res += countingPairs();
			isused[solo] = isused[another] = false;
		}
	}
	return res;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		for (int a, b, i = 0; i < M; ++i) {
			scanf("%d %d", &a, &b);
			areFriends[a][b] = areFriends[b][a] = true; // ģ�� ���
		}
		printf("%d\n", countingPairs());
		memset(areFriends, false, sizeof(areFriends));
		memset(isused, false, sizeof(isused));
	}

	return 0;
}