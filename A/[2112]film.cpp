#include<iostream>
using namespace std;
int film[13][20] = {0};
int film_copy[13][20] = {0};
int D, W, K, ans;
bool occupied[13] = {false};

bool pass(){
    int i, j, length;
    for(i = 0; i < W; ++i){
        length = 1;
        for(j = 0; j < D-1; ++j){
            if(film[j][i] == film[j+1][i]){
                length++;
            }
            else{
                length = 1;
                if(j>D-K)
                    break;
            }
            if(length >= K){
                break;
            }
        }
        if(length < K){
            return false;
        }
    }
	return true;
}

void dfs(int n, int st){
    if(n<ans){
    	if(pass()){
            ans = n;
        }
        else{
            int i, j, k;
            for(i = st; i < D; ++i){
                if(!occupied[i]){
                    occupied[i] = true;
                    for(j = 0; j<2; ++j){
                        for(k = 0; k<W; ++k){
                            film[i][k] = j;
                        }
                        dfs(n+1, i);
                    }
                    for(j = 0; j < W; ++j){
        				film[i][j] = film_copy[i][j];
                    }
                    occupied[i] = false;
                }
                if(n+1>=ans)
                    break;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int T, test_case, i, j;
    cin >> T;
    for(test_case = 1; test_case<=T; ++test_case){
    	cin >> D >> W >> K;
        for (i = 0; i < D; ++i){
        	for(j = 0; j < W; ++j){
            	cin >> film[i][j];
                film_copy[i][j] = film[i][j];
            }
		}
        if(K==1)
            cout << "#" << test_case << " " << 0 << endl;
        else{
            ans = K;
            dfs(0, 0);
            cout << "#" << test_case << " " << ans << endl;
        }   
    }
}
