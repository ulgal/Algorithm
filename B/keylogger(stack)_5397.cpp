#include<iostream>
#define MAX_LIST 1000001

using namespace std;

char ans[MAX_LIST];
char str_left[MAX_LIST];
char str_right[MAX_LIST];

void show_stack(int l, int r) {
	int j;
	for (j = 0; j <= l; ++j) {
		cout << str_left[j];
	}
	cout << "\t";
	for (j = r; j >= 0; --j) {
		cout << str_right[j];
	}
	cout << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char cmd;
	int N, i, k;
	int register finger;
	int register str_left_index;
	int register str_right_index;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> ans;
		finger = 0;
		str_left_index = -1;
		str_right_index = -1;
		while ((cmd = ans[finger++]) != '\0') {
			switch (cmd) {
			case '<':
				if (str_left_index != -1) {
					str_right[++str_right_index] = str_left[str_left_index--];
				}
				break;
			case '>':
				if (str_right_index != -1) {
					str_left[++str_left_index] = str_right[str_right_index--];
				}
				break;
			case '-':
				if (str_left_index != -1) {
					str_left_index--;
				}
				break;
			default:
				str_left[++str_left_index] = cmd;
				break;
			}
		}
		k = 0;
		finger = 0;
		for (finger = 0; finger <= str_left_index; ++finger) {
			ans[k++] = str_left[finger];
		}
		for (finger = str_right_index; finger >= 0; --finger) {
			ans[k++] = str_right[finger];
		}
		ans[k] = '\0';
		cout << ans << "\n";
	}
	
	return 0;
}