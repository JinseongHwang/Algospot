#include <cstdio>
#include <memory.h>
using namespace std;

const int MAX = 10;
int N, M;
bool areFriends[MAX][MAX];
// taken[i]: i번째 학생이 짝을 찾았다면 true, 아니면 false
int countPairings(bool taken[MAX]) {
	// 모든 학생이 짝을 찾았으면 한가지 경우를 찾았으니 종료한다
	bool finished = true;
	for (int i = 0; i < N; ++i)
		if (!taken[i]) finished = false;
	if (finished) return 1;
	
	int ret = 0;
	// 서로 친구인 두 학생을 찾아 짝짓는다
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