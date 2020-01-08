#include<iostream>
#define MAX_LIST 600001

using namespace std;

char str[MAX_LIST];
char result[MAX_LIST];
int next_addr[MAX_LIST];
int bef_addr[MAX_LIST];
int dummy_head_fill, dummy_head_empty;

void show_table(int n) {
	for (int j = 0; j < n; ++j) {
		cout << str[j] << " " << bef_addr[j] << " " << next_addr[j] << endl;
	}
}
void show_string() {
	int cur = dummy_head_fill;
	while (str[cur] != '\0') {
		cout << str[cur];
		cur = next_addr[cur];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char cmd, new_char;
	int N, i, insert_address;
	int register cursor = 0;
	cin >> str;
	while (str[cursor] != '\0') {
		bef_addr[cursor] = cursor - 1;
		next_addr[cursor] = cursor + 1;
		++cursor;
	}
	bef_addr[0] = 0;
	bef_addr[cursor] = cursor - 1;
	next_addr[cursor] = cursor;
	dummy_head_empty = cursor + 1;
	next_addr[dummy_head_empty] = -2;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> cmd;
		switch (cmd) {
		case 'L':
			cursor = bef_addr[cursor];
			break;
		case 'D':
			cursor = next_addr[cursor];
			break;
		case 'B':
			if (cursor != bef_addr[cursor]) {
				next_addr[bef_addr[cursor]] = dummy_head_empty;
				dummy_head_empty = bef_addr[cursor];
				if (bef_addr[bef_addr[cursor]] == bef_addr[cursor]) {
					bef_addr[cursor] = cursor;
					dummy_head_fill = cursor;
				}
				else {
					bef_addr[cursor] = bef_addr[bef_addr[cursor]];
					next_addr[bef_addr[cursor]] = cursor;
				}
			}
			break;
		case 'P':
			insert_address = dummy_head_empty;
			if (next_addr[dummy_head_empty] == -2) {
				dummy_head_empty++;
				next_addr[dummy_head_empty] = -2;
			}
			else {
				dummy_head_empty = next_addr[dummy_head_empty];
			}
			cin >> str[insert_address];
			if (bef_addr[cursor] != cursor) {
				next_addr[bef_addr[cursor]] = insert_address;
				bef_addr[insert_address] = bef_addr[cursor];
			}
			else {
				bef_addr[insert_address] = insert_address;
				dummy_head_fill = insert_address;
			}
			bef_addr[cursor] = insert_address;
			next_addr[insert_address] = cursor;
			break;
		default:
			break;
		}
	}
	cursor = dummy_head_fill;
	i = 0;
	while (str[cursor] != '\0') {
		result[i++] = str[cursor];
		cursor = next_addr[cursor];
	}
	result[i] = '\0';
	cout << result;
	return 0;
}