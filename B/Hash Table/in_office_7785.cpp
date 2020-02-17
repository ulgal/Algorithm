#include<iostream>
#define MAX 1000001
#define MAX_TABLE 10000
using namespace std;
int result[MAX];
int result_idx = 0;

int str_cmp(const char* s1, const char* s2) {
	int ret = 0;

	while (!(ret = *(unsigned char*)s1 - *(unsigned char*)s2) && *s2) {
		++s1, ++s2;
	}
	if (ret < 0) {
		ret = -1;
	}
	else if (ret > 0) {
		ret = 1;
	}
	return ret;
}

void str_cpy(char* src, char* dst, int size) {
	char* d = dst;
	const char* s = src;
	while (size--)
		*d++ = *s++;
}


typedef struct {
	char data[MAX][6];
	bool enter[MAX];
	int next_idx[MAX];
	int top = 1;

	void init() {
		for (int i = 0; i < MAX; ++i) {
			next_idx[i] = 0;
		}
	}
	int get_next(int idx) {
		return next_idx[idx];
	}
	int add_data(char* add, int idx, bool state) {
		if (idx != -1) {
			while (1) {
				if (str_cmp(add, data[idx]) == 0) {
					enter[idx] = state;
					return -1;
				}
				if (next_idx[idx] == 0) {
					str_cpy(add, data[top],6);
					enter[top] = state;
					next_idx[idx] = top;
					top++;
					return -1;
				}
				idx = next_idx[idx];
			}
		}
		else {
			str_cpy(add, data[top], 6);
			enter[top] = state;
			top++;
			return top - 1;
		}
	}
	void find_all() {
		int i;
		for (i = 0; i < top; ++i) {
			if (enter[i]) {
				result[result_idx++] = i;
			}
		}
	}
}LinkedList;
LinkedList ll;

typedef struct {
	int addr[MAX_TABLE];
	void init() {
		int i;
		for (i = 0; i < MAX_TABLE; ++i) {
			addr[i] = -1;
		}
	}
	unsigned long hash(char* str) {
		unsigned long hash = 5381;
		int c = 0;
		while (str[c] != '\0') {
			hash = (((hash << 5) + hash) + (unsigned long)(str[c])) % MAX_TABLE;
			c++;
		}
		return hash;
	}
	void add(char* str, bool state) {
		unsigned long idx = hash(str);
		int address = ll.add_data(str, addr[idx], state);
		if (address != -1) {
			addr[idx] = address;
		}
	}
}HashSet;
HashSet enter;


void percolateDown(int i, int n) {
	int lChild = 2 * i;
	int rChild = 2 * i + 1;

	if (lChild <= n) {
		if ((rChild <= n) && (str_cmp(ll.data[result[lChild - 1]], ll.data[result[rChild - 1]]) > 0)) {
			lChild = rChild;
		}
		if (str_cmp(ll.data[result[i - 1]], ll.data[result[lChild - 1]]) > 0) {
			int tmp = result[i - 1];
			result[i - 1] = result[lChild - 1];
			result[lChild - 1] = tmp;
			percolateDown(lChild, n);
		}
	}
}
void heap_sort(int N) {
	if (N == 0) {
		return;
	}
	int i;

	for (i = (N / 2); i > 0; --i) {
		percolateDown(i, N);
	}
	for (i = N; i > 1; --i) {
		int tmp = result[0];
		result[0] = result[i - 1];
		result[i - 1] = tmp;
		percolateDown(1, i - 1);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, i;
	char name[6];
	char cmd[6];
	char enter_cmd[6] = "enter";
	enter.init();
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> name >> cmd;
		if (str_cmp(cmd, enter_cmd) == 0) {
			enter.add(name, true);
		}
		else {
			enter.add(name, false);
		}
	}
	ll.find_all();
	heap_sort(result_idx);
	for (i = 0; i < result_idx; i++) {
		cout << ll.data[result[i]] << '\n';
	}
	return 0;
}