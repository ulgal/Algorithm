#include<iostream>
using namespace std;
int N, M;
int table[20][20] = {0};
int cost[41] = {0};

int maxHome(int x, int y, int limit){
    int i, j, k, home;
    for(k = limit; k > 0; --k){
        home = 0;
    	for(i = x; i < x+k; ++i){
        	for( j = y-(k+x-1-i); j < y+(k+x-i); ++j){
                if(i>=0 && i<N && j>=0 && j<N){
                    if(table[j][i] == 1){
                        home++;
                    }
                }
            }
        }
        for(i = x-1; i > x-k; --i){
        	for( j = y-(i-x+k-1); j < y+(i-x+k); ++j){
                if(i>=0 && i<N && j>=0 && j<N){
                    if(table[j][i] == 1){
                        home++;
                    }
                }
            }
        }
        if(cost[k-1] <= home*M){
            //cout << x+1 << ", " << y+1 << ", " << k << ": " << home << endl;
            return home;
        }
    }
    return 0;
}

    
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int test_case, T, i, j, limit, cnt, max_home, home;
    cin >> T;
    for(i = 1; i <= 41; ++i){
        cost[i-1] = i * i + (i-1) * (i-1);
    }
    for(test_case = 1; test_case<=T; ++test_case){
        cin >> N >> M;
        limit = 0;
        cnt = 0;
        for(i = 0; i < N; ++i){
            for(j = 0; j < N; ++j){
                cin >> table[i][j];
                if(table[i][j] == 1){
                    cnt++;
                }
            }
        }
        cnt *= M;
        while(cnt>cost[limit] && limit<=N){
            limit++;
        }
        max_home = 0;
        for( i = 0; i < N; ++i){
        	for( j = 0; j < N; ++j){
                home = maxHome(j, i, limit);
        		max_home = (max_home > home) ? max_home : home;
        	}
    	}
        cout << "#" << test_case <<" " << max_home << endl;
    }
}