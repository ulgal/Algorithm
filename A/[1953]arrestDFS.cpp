#include<iostream>
using namespace std;
//bfs로 구현하는게 좋다
int N, M, K, R, C, ans;
int map[50][50] = {0};
bool checked[50][50] = {false};
int check_cnt[50][50] = {0};

void checking(int row, int column, int n, int dir){
    int ansPlus = 1;
    if(n>K){
        return;
    }
    if(row>=N || row<0 || column>=M || column<0){
        return;
    }
	if(checked[row][column]){
        if(n>=check_cnt[row][column]){
            return;
        }
        else{
            ansPlus = 0;
        }
    }
	switch(map[row][column]){
    	case 1://cout << row << " " << column << " " << n << " " << 1 << endl;
            checked[row][column] = true;
            check_cnt[row][column] = n;
        	ans += ansPlus;
        	checking(row-1, column, n+1, 1);
            checking(row+1, column, n+1, 2);
            checking(row, column-1, n+1, 3);
            checking(row, column+1, n+1, 4);
            break;
		case 2:
            if(dir!=3 && dir != 4){//cout << row << " " << column << " " << n << " " << 2 << endl;
                checked[row][column] = true;
                check_cnt[row][column] = n;
        		ans += ansPlus;
                checking(row-1, column, n+1, 1);
            	checking(row+1, column, n+1, 2);
            }
            break;
		case 3:
            if(dir!=1 && dir != 2){//cout << row << " " << column << " " << n << " " << 3 << endl;
                checked[row][column] = true;
                check_cnt[row][column] = n;
                ans += ansPlus;
                checking(row, column-1, n+1, 3);
                checking(row, column+1, n+1, 4);
            }
            break;
		case 4:
            if(dir!=1 && dir != 4){//cout << row << " " << column << " " << n << " " << 4 << endl;
                checked[row][column] = true;
                check_cnt[row][column] = n;
                ans += ansPlus;
                checking(row-1, column, n+1, 1);
                checking(row, column+1, n+1, 4);
            }
            break;
		case 5:
            if(dir!=2 && dir != 4){//cout << row << " " << column << " " << n << " " << 5 << endl;
            	checked[row][column] = true;
                check_cnt[row][column] = n;
        		ans += ansPlus;
        		checking(row+1, column, n+1, 2);
				checking(row, column+1, n+1, 4);
            }
            break;
		case 6:
            if(dir!=2 && dir != 3){//cout << row << " " << column << " " << n << " " << 6 << endl;
            	checked[row][column] = true;
                check_cnt[row][column] = n;
        		ans += ansPlus;
        		checking(row+1, column, n+1, 2);
				checking(row, column-1, n+1, 3);
            }
            break;
		case 7:
            if(dir!=1 && dir != 3){//cout << row << " " << column << " " << n << " " << 7 << endl;
            	checked[row][column] = true;
                check_cnt[row][column] = n;
        		ans += ansPlus;
				checking(row-1, column, n+1, 1);
            	checking(row, column-1, n+1, 3);
            }
            break;
    }
}
/*
if(row==9 && column == 17){
                cout << row << " " << column << " " << n << " " << dir << endl;
            }
*/
int showALL(){
    int i, j;
    for(i=0;i<N;++i){
        for(j=0;j<M;++j){
            if(checked[i][j]){
                cout << i << " " << j << endl;
                }
            }
        }

}

int main(){
    int test_case, T, i, j;
    cin >> T;
    N = M = 0;
    for(test_case = 1; test_case<=T; ++test_case){
        cin >> N >> M >> R >> C >> K;
		for(i = 0; i < N; ++i){
        	for(j = 0; j < M; ++j){
            	cin >> map[i][j];
                checked[i][j] = false;
                check_cnt[i][j] = 0;
			}
		}
        ans = 0;
        checking(R, C, 1, 0);
        cout << "#" << test_case << " " << ans << endl;
    }
}





