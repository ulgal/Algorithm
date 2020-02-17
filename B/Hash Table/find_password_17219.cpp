#include<iostream>
#define MAX 100001
#define R 11
#define MAX_HASH 10000
using namespace std;
char site[MAX][21];
char password[MAX][21];

bool str_cmp(char* src, char* dst) {
	int src_idx = 0, dst_idx = 0;
	while (src[src_idx] != '\0' && dst[dst_idx] != '\0') {
		if (src[src_idx++] != dst[dst_idx++]) {
			return false;
		}
	}
	return true;
}

struct linked_list {
	int item[MAX];
	int next[MAX];
	int num = 0;

	bool has_next(int idx) {
		return next[idx] != -1;
	}

	int get_next(int idx) {
		return next[idx];
	}

	int get_item(int idx) {
		return item[idx];
	}

	int add_item(int add, int next_idx) {
		next[num] = next_idx;
		item[num] = add;
		num++;
		return num - 1;
	}

};
linked_list ll;

struct hash_table {
	int table[MAX_HASH];
	bool filled[MAX_HASH];

	bool is_filled(int idx) {
		return filled[idx];
	}
	int hashing_key(char* str) {
		int i = 0, k;
		int cur_x = 1;
		int key = 0;
		while (str[i] != '\0') {
			k = str[i++] - 'a' + 1;
			key += cur_x * k;
			key %= MAX_HASH;
			cur_x *= R;
			cur_x %= MAX_HASH;
		}
		return key;
	}

	void hashing(char* str, int name_idx) {
		int key;
		key = hashing_key(str);
		if (filled[key]) {
			table[key] = ll.add_item(name_idx, table[key]);
		}
		else {
			table[key] = ll.add_item(name_idx, -1);
			filled[key] = true;
		}
	}

	int search_hash(char* str) {
		int head;
		head = table[hashing_key(str)];
		while (1) {
			if (str_cmp(str, site[ll.get_item(head)])) {
				return ll.get_item(head);
			}
			if (!ll.has_next(head)) {
				break;
			}
			head = ll.get_next(head);
		}
	}
};

int char2int(char* str) {
	int i = 0;
	int ans = 0;
	while (str[i] != '\0') {
		ans *= 10;
		ans += str[i] - '0';
		i++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, i;
	hash_table ht;
	char search[21];
	cin >> N >> M;
	for (i = 1; i <= N; ++i) {
		cin >> site[i] >> password[i];
		ht.hashing(site[i], i);
	}
	for (i = 0; i < M; ++i) {
		cin >> search;
		cout << password[ht.search_hash(search)] << '\n';
	}
	return 0;
}
