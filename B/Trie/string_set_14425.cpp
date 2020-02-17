#include<iostream>
using namespace std;
#define ALPHABETS 26
#define MAX 10000000
#define char2idx(c) ((char)c-'a')
int Trie[MAX][ALPHABETS];
bool is_terminal[MAX];
int idx = 1;

void insert(const char* key, int tg) {
	if (*key == 0) {
		is_terminal[tg] = true;
	}
	else {
		int index = char2idx(*key);

		if (Trie[tg][index] == 0) {
			Trie[tg][index] = idx++;
		}
		insert(key + 1, Trie[tg][index]);
	}
}

bool exist(const char* key, int tg) {
	if (*key == 0 && is_terminal[tg]) {
		return true;
	}

	int index = char2idx(*key);
	if (Trie[tg][index] == 0) {
		return false;
	}
	return exist(key + 1, Trie[tg][index]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, cnt = 0;
	char words[501];
	cin >> N >> M;
	while (N-- > 0) {
		cin >> words;
		insert(words, 0);
	}
	while (M-- > 0) {
		cin >> words;
		if (exist(words, 0)) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}