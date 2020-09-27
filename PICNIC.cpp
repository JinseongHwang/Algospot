// 책 소스코드

#include <cstdio>
#include <memory.h>
using namespace std;

const int MAX = 10;
int N, M;
bool areFriends[MAX][MAX];
// taken[i]: i번째 학생이 짝을 찾았다면 true, 아니면 false
int countPairings(bool taken[MAX]) {
	int firstFree = -1; // 짝을 찾지 못한 친구 중 가장 작은 번호를 저장
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
		// 짝 지을 친구도 짝이 없고 && 둘이 친구라면 => 짝으로 묶어준다.
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
		bool taken[MAX] = { 0, };
		printf("%d\n", countPairings(taken));
		memset(areFriends, 0, sizeof(areFriends));
	}

	return 0;
}


// 다시 풀어봄

#include <cstdio>
#include <memory.h>
using namespace std;

int N, M; // 학생 수, 쌍의 수
bool areFriends[11][11], isused[11]; // isused[i]: i번 학생이 짝을 찾았다면 true, 없으면 false

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
	// 0부터가 아닌, 최초 솔로 + 1번부터 시작하면 연산 횟수를 더 줄일 수 있겠지?
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
			areFriends[a][b] = areFriends[b][a] = true; // 친구 등록
		}
		printf("%d\n", countingPairs());
		memset(areFriends, false, sizeof(areFriends));
		memset(isused, false, sizeof(isused));
	}

	return 0;
}