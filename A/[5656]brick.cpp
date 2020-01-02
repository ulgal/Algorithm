#include<iostream>
using namespace std;
int N, W, H;
int table[6][15][12] = {0};//{0: initial table}

int min(int a, int b){
    if(a<b)
        return a;
    return b;
}
void copy_table(int n, int m){
    for(int i = 0 ; i < H ; i++){
        for(int j = 0; j < W; j++){
            table[N-n][i][j] = table[N-m][i][j];
        }
    }
}
int find_ans(int n){
    int ans = 0;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0; j < W; j++){
            if(table[N-n+1][i][j]!=0)
                ans++;
        }
    }
    return ans;
}
void brick_del(int x, int y, int n){
    int z = N-n; 
    int range = table[z][y][x];
    table[z][y][x] = 0;
    for(int i = -range + 1; i < range; i++){
        if((x+i>=0) && (x+i<W)){
            if(table[z][y][x+i] >1)
                brick_del(x+i, y, n);
            else
                table[z][y][x+i]=0;
        }
        if((y+i>=0) && (y+i<H)){
            if(table[z][y+i][x] >1)
                brick_del(x, y+i, n);
            else
                table[z][y+i][x]=0;
        }
    }
}
void brick_down(int n){
    int z = N-n;
    for(int x=0; x<W; x++){
        int finger = H-1;
        int y = H - 1;
        while(y>=0){
            if((table[z][y][x]!=0) && (finger==y) ){
                y--;
                finger--;
            }
            else if( table[z][y][x]!=0 ){
                table[z][finger][x] = table[z][y][x];
                table[z][y][x] = 0;
                y--;
                finger--;
            }
            else
                y--;
        }
    }
}
int brick_brute_force(int n){
    if(n==0)
        return find_ans(n);
    int ans = 2000;
    for(int i = 0; i<W; i++){
        int x = i, y = 0;
        while((y<H) && (table[N-n][y][x] == 0))
            y++;
        if(y<H){
            brick_del(x, y, n-1);
            brick_down(n-1);
            copy_table(n-2, n-1);
            ans = min(ans, brick_brute_force(n-1));
            copy_table(n-1, n);
        }
        ans = min(ans, find_ans(n)); // for all 0
    }
    return ans;
}

            

int main(int argc, char** argv)
{
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();

	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> W >> H;
        for(int i = 0 ; i < H ; i++){
            for(int j = 0; j < W; j++){
                cin >> table[0][i][j];
                table[1][i][j] = table[2][i][j] = table[3][i][j] = table[4][i][j] = table[5][i][j] =  table[0][i][j];
            }
        }
		int ans = brick_brute_force(N);
        cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}
