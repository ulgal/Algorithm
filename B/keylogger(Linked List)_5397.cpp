#include<iostream>
#define MAX_LIST 1000001

using namespace std;

char str[MAX_LIST];
char password[MAX_LIST];
char result[MAX_LIST];
int bef_addr[MAX_LIST];
int next_addr[MAX_LIST];
int dummy_head_fill, dummy_head_empty;

void show_table(int n) {
	cout << "current table" << endl;
	for (int j = 0; j < n; ++j) {
		cout << password[j] << " " << bef_addr[j] << " " << next_addr[j] << endl;
	}
	cout << endl;
}
void show_string() {
	cout << "current string" << endl;
	int cur = dummy_head_fill;
	while (password[cur] != '\0') {
		cout << password[cur];
		cur = next_addr[cur];
	}
	cout << endl;

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char cmd;
	int N, i, insert_address;
	int register finger;
	int register cursor;
	
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> str;
		finger = 0;
		cursor = 0;
		bef_addr[0] = 0;
		next_addr[0] = 0;
		password[0] = '\0';
		next_addr[1] = -2;
		dummy_head_empty = 1;
		while ((cmd = str[finger++]) != '\0') {
			switch (cmd) {
			case '<':
				cursor = bef_addr[cursor];
				break;
			case '>':
				cursor = next_addr[cursor];
				break;
			case '-':
				if (cursor != bef_addr[cursor]) {
					next_addr[bef_addr[cursor]] = dummy_head_empty;
					dummy_head_empty = bef_addr[cursor];
					if (bef_addr[cursor] != bef_addr[bef_addr[cursor]]) {
						bef_addr[cursor] = bef_addr[bef_addr[cursor]];
						next_addr[bef_addr[cursor]] = cursor;
					}
					else {
						bef_addr[cursor] = cursor;
						dummy_head_fill = cursor;
					}
				}
				break;
			default:
				insert_address = dummy_head_empty;
				if (next_addr[dummy_head_empty] == -2) {
					next_addr[++dummy_head_empty] = -2;
				}
				else {
					dummy_head_empty = next_addr[dummy_head_empty];
				}
				next_addr[insert_address] = cursor;
				if (cursor == bef_addr[cursor]) {
					bef_addr[insert_address] = insert_address;
					dummy_head_fill = insert_address;

				}
				else {
					bef_addr[insert_address] = bef_addr[cursor];
					next_addr[bef_addr[cursor]] = insert_address;
				}
				bef_addr[cursor] = insert_address;
				password[insert_address] = cmd;
				break;
			}
		}
		cursor = dummy_head_fill;
		finger = 0;
		while (password[cursor] != '\0') {
			result[finger++] = password[cursor];
			cursor = next_addr[cursor];
		}
		result[finger] = '\0';
		cout << result << "\n";
	}
	
	return 0;
}