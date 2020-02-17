#include<iostream>
using namespace std;
char tree[31];
int tree_num;


struct Trie {
	Trie* ascii[128];
	int cnt;
	Trie() : cnt(0) {
		for (int i = 0; i < 128; i++) {
			ascii[i] = 0;
		}
	}
	void add(char* str) {
		if (*str == '\0') {
			tree_num++;
			cnt++;
		}
		else {
			int next = *str;
			if (!ascii[next]) {
				ascii[next] = new Trie;
			}
			ascii[next]->add(str + 1);
		}
	}
	void print(int idx = 0) {
		if (cnt > 0) {
			tree[idx] = '\0';
			cout << tree << " " << 100.0 * cnt / tree_num << '\n';
		}
		for (int i = 0; i < 128; i++) {
			if (ascii[i]) {
				tree[idx] = i;
				ascii[i]->print(idx + 1);
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	cout.precision(4);
	Trie* root = new Trie;
	while (cin.getline(tree, 31)) {
		root->add(tree);
	}
	root->print();

	return 0;
}