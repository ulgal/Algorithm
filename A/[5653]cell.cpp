#include<iostream>

using namespace std;
int table[350][350] = {0}; // 0: non-occupied , 0<x : occupied
int N, M, K;

struct Cell{
    int x;
    int y;
    int activated; // 0: not-activated , 1: alive, -1: dead
    int activated_cnt; // activated -> 1 : power to zero , activated -> 0 : power to zero , activate -> -1:dead
};
Cell cell[10][100000];
int cell_cnt[10];

void initTable(){
    for(int p = 0; p < 10; p++)
        for(int i = 0; i < cell_cnt[p]; i++)
            table[cell[p][i].x][cell[p][i].y] = 0;
}
void cellUpdate(){
    for(int p = 0; p < 10; p++){
        for(int i = 0; i < cell_cnt[p]; i++){
            cell[p][i].activated_cnt--;
            if(cell[p][i].activated == 1 && cell[p][i].activated_cnt == 0)
                    cell[p][i].activated = -1;
            else if(cell[p][i].activated == 0 && cell[p][i].activated_cnt == 0){
                    cell[p][i].activated = 1;
                    cell[p][i].activated_cnt = p + 1;
            }
        }
    }
    
}

void cellMark(){
    for(int p = 9; p>=0; p--){
    	int bound = cell_cnt[p];
		for(int i = 0; i < bound; i++){
            if(cell[p][i].activated==0 || cell[p][i].activated==-1)
                continue;
            if(table[cell[p][i].x-1][cell[p][i].y]==0){
                table[cell[p][i].x-1][cell[p][i].y] = p + 1;
                cell[p][cell_cnt[p]] = { cell[p][i].x-1, cell[p][i].y, 0, p + 2};
                cell_cnt[p]++;
            }
            if(table[cell[p][i].x+1][cell[p][i].y]==0){
                table[cell[p][i].x+1][cell[p][i].y] = p + 1;
                cell[p][cell_cnt[p]] = { cell[p][i].x+1, cell[p][i].y, 0, p + 2};
                cell_cnt[p]++;
            }
            if(table[cell[p][i].x][cell[p][i].y-1]==0){
                table[cell[p][i].x][cell[p][i].y-1] = p + 1;
                cell[p][cell_cnt[p]] = { cell[p][i].x, cell[p][i].y-1,  0, p +2};
                cell_cnt[p]++;
            }
            if(table[cell[p][i].x][cell[p][i].y+1]==0){
                table[cell[p][i].x][cell[p][i].y+1] = p + 1;
                cell[p][cell_cnt[p]] = { cell[p][i].x, cell[p][i].y+1, 0, p + 2};
                cell_cnt[p]++;
            }
        }
    }
    
}
int cellAnswer(){
    int ans=0;
    for(int p = 0; p < 10; p++){
        for(int i = 0; i < cell_cnt[p]; i++){
            if(cell[p][i].activated>=0)
                ans++;
        }
    }
    return ans;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> M >> K;
        initTable();
        for(int i = 0; i < 10; i++)
        	cell_cnt[i] = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> table[i+150][j+150];
                if(table[i+150][j+150]>0){
                    cell[table[i+150][j+150]-1][cell_cnt[table[i+150][j+150]-1]] = {i+150, j+150, 0, table[i+150][j+150] + 1};
                    cell_cnt[table[i+150][j+150]-1]++;
                }
            }
        }

        for(int i=0; i <= K; i++){
            cellMark();
            cellUpdate();
        }
        cout << "#" << test_case << " " << cellAnswer() << endl;
	}
	return 0;
}

