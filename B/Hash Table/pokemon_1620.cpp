#include<iostream>
#define MAX 100001
#define R 11
#define MAX_HASH 10000
using namespace std;
char name[MAX][21];
int hash_table[MAX_HASH];
bool hash_filled[MAX_HASH];
int item[MAX];
int next_value[MAX];
int idx = 0;

bool str_cmp(char* src, char* dst) {
	int src_idx = 0, dst_idx = 0;
	while (src[src_idx] != '\0' && dst[dst_idx] != '\0') {
		if (src[src_idx++] != dst[dst_idx++]) {
			return false;
		}
	}
	return true;
}

int hashing_key(char *str) {
	int i = 0, k;
	int cur_x = 1;
	int key = 0;
	while(str[i]!='\0') {
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
	if (hash_filled[key]) {
		next_value[idx] = hash_table[key];
		item[idx] = name_idx;
		hash_table[key] = idx;
		idx++;
	}
	else {
		item[idx] = name_idx;
		next_value[idx] = idx;
		hash_table[key] = idx;
		hash_filled[key] = true;
		idx++;
	}
}


int search_hash(char* str) {
	int head;
	head = hash_table[hashing_key(str)];
	while (1) {
		if (str_cmp(str, name[item[head]])) {
			return item[head];
		}
		if (head == next_value[head]) {
			break;
		}
		head = next_value[head];
	}
}

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
	char search[21];
	cin >> N >> M;
	for (i = 1; i <= N; ++i) {
		cin >> name[i];
		hashing(name[i], i);
	}
	for (i = 0; i < M; ++i) {
		cin >> search;
		if (search[0] > '0' && search[0] <= '9') {
			cout << name[char2int(search)] << '\n';
		}
		else {
			cout << search_hash(search) << '\n';
		}
	}
	return 0;
}