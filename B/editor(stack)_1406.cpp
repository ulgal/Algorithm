#include<iostream>
#define MAX_LIST 600001

using namespace std;

char str_left[MAX_LIST];
char str_right[MAX_LIST];

void show_string(int l, int r) {
	int i;
	for (i = 0; i <= l; ++i) {
		cout << str_left[i];
	}
	cout << "\t";
	for (i = r; i >= 0; --i) {
		cout << str_right[i];
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int register str_left_index = 0;
	int register str_right_index= -1;
	int register i;
	char cmd;
	int N;
	cin >> str_left;
	while (str_left[str_left_index] != '\0') {
		++str_left_index;
	}
	--str_left_index;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> cmd;
		switch (cmd) {
		case 'L':
			if (str_left_index != -1) {
				str_right[++str_right_index] = str_left[str_left_index--];
			}
			break;
		case 'D':
			if (str_right_index != -1) {
				str_left[++str_left_index] = str_right[str_right_index--];
			}
			break;
		case 'B':
			if (str_left_index != -1) {
				--str_left_index;
			}
			break;
		case 'P':
			cin >> str_left[++str_left_index];
			break;
		default:
			break;
		}
		//show_string(str_left_index, str_right_index);
	}
	while (str_right_index >= 0) {
		str_left[++str_left_index] = str_right[str_right_index--];
	}
	str_left[++str_left_index] = '\0';
	cout << str_left;
	return 0;
}