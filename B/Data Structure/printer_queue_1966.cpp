#include<iostream>
#define MAX_QUEUE 101
#define MAX_HASH 10
using namespace std;

int importance_queue[MAX_QUEUE];
int importance_hash[MAX_HASH];

bool can_print(int imp) {
	if (imp == 9) {
		return true;
	}
	int i;
	for (i = imp+1; i < MAX_HASH; ++i) {
		if (importance_hash[i] > 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case, i, j;
	int front, back;
	int N, M, ans;
	cin >> test_case;
	for (i = 0; i < test_case; ++i) {
		cin >> N >> M;
		for (j = 1; j < MAX_HASH; ++j) {
			importance_hash[j] = 0;
		}
		for (j = 0; j < N; ++j) {
			cin >> importance_queue[j];
			importance_hash[importance_queue[j]]++;
		}
		ans = 0;
		front = 0;
		back = N;
		while (N >= 0) {
			if (can_print(importance_queue[front])) {
				importance_hash[importance_queue[front]]--;
				N--;
				ans++;
				if (front == M) {
					break;
				}
				front++;
			}
			else {
				if (front == M) {
					M = back;
				}
				importance_queue[back++] = importance_queue[front++];
				if (back >= MAX_QUEUE) {
					back = 0;
				}
			}
			if (front >= MAX_QUEUE) {
				front = 0;
			}
		}
		cout << ans << "\n";
	}


	return 0;
}