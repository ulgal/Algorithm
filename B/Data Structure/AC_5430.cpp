#include<iostream>
#define MAX_DEQUE 100000
#define MAX 700000
using namespace std;


char cmd[MAX_DEQUE];
char sequence[MAX];
int deque[MAX_DEQUE];
int front, back;
bool reverse_flag;

void parse_sequence(int n) {
	int register k = 0;
	int finger = 0, i = 0;
	int num = 0;
	while (sequence[k] != '\0') {
		if ((sequence[k] == ',') || (sequence[k] == ']')) {
			deque[finger++] = num;
			num = 0;
		}
		else if (!(sequence[k] == '[')) {
			num *= 10;
			num += (int)(sequence[k] - '0');
		}
		++k;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case, i;
	int register j;
	int register front;
	int register back;
	bool error_flag;
	int N, M, ans;
	cin >> test_case;
	for (i = 0; i < test_case; ++i) {
		cin >> cmd;
		cin >> N;
		cin >> sequence;
		parse_sequence(N);
		front = 0;
		back = N-1;
		reverse_flag = false;
		error_flag = false;
		j = 0;
		while (cmd[j] != '\0') {
			if (cmd[j] == 'R') {
				reverse_flag = !reverse_flag;
			}
			else {
				if (N > 0) {
					if (reverse_flag) {
						--back;
					}
					else {
						++front;
					}
					--N;
				}
				else {
					error_flag = true;
					break;
				}
			}
			++j;
		}
		if (error_flag) {
			cout << "error\n";
		}
		else {
			if (reverse_flag) {
				cout << "[";
				for (j = back; j >= front; --j) {
					cout << deque[j] << (j != front ? "," : "");
				}
				cout << "]\n";
			}
			else {
				cout << "[";
				for (j = front; j <= back; ++j) {
					cout << deque[j] << (j != back ? "," : "");
				}
				cout << "]\n";
			}
		}
	}

	return 0;
}
