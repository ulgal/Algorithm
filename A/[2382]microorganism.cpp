#include<iostream>
using namespace std;
int N, M, K;
int collide_cnt, medicine_cnt, dummy_cnt;
int table[100][100][1000] = {0};
int collide[1000][2] = {0};
int medicine[1000] = {0};
int dummy[1000] = {0};
struct microOrganism{
    int x;
    int y;
    int num;
    int dir;
};
microOrganism mO[1000];

void showAns(){
    for(int i = 0; i < K; ++i){
        cout << i << ": " << mO[i].x << " " << mO[i].y << " " << mO[i].num << " " << mO[i].dir <<endl;
    }
    for(int i = 0; i < collide_cnt; ++i){
        int lim = table[collide[i][1]][collide[i][0]][0];
        for(int j = 1; j <= lim; ++j){
            cout << "collide x, y, pos: " << collide[i][0] << " " << collide[i][1] << " " << table[collide[i][1]][collide[i][0]][j] << endl;
        }
    }
    for(int i = 0; i < medicine_cnt; ++i){
        cout << "med: " << medicine[i] << endl;
    }
    for(int i = 0; i < dummy_cnt; ++i){
        cout << "dum: " << dummy[i] << endl;
    }
}



void microOrganismMove(){
	int i = 0;
    collide_cnt = medicine_cnt = 0;
    for(i=0; i < K; ++i){
    	switch(mO[i].dir){
        	case 1:
            	mO[i].y--;
                break;
            case 2:
            	mO[i].y++;
                break;
            case 3:
            	mO[i].x--;
                break;
            case 4:
            	mO[i].x++;
                break;
        }
        table[mO[i].y][mO[i].x][0]++;
        if(table[mO[i].y][mO[i].x][0] == 2){
            collide[collide_cnt][0] = mO[i].x;
            collide[collide_cnt][1] = mO[i].y;
            collide_cnt++;
        }
        if(mO[i].x == 0 || mO[i].x == N-1 || mO[i].y == 0 || mO[i].y == N-1){
        	medicine[medicine_cnt] = i;
            medicine_cnt++;
        }
        table[mO[i].y][mO[i].x][table[mO[i].y][mO[i].x][0]] = i;
    }
}

void microOrganismMedicine(){
    int i;
    for(i = 0; i < medicine_cnt; ++i){
    	mO[medicine[i]].num /= 2;
        switch(mO[medicine[i]].dir){
            case 1:
                mO[medicine[i]].dir = 2;
                break;
            case 2:
                mO[medicine[i]].dir = 1;
                break;
            case 3:
                mO[medicine[i]].dir = 4;
                break;
            case 4:
                mO[medicine[i]].dir = 3;
                break;
        }
    }
}

void microOrganismCollide(){
	int i, j;
    dummy_cnt = 0;
    for(i = 0; i < collide_cnt; ++i){
        int col_num = table[collide[i][1]][collide[i][0]][0];
        int max_position = table[collide[i][1]][collide[i][0]][1];
        for(j=2; j <= col_num; ++j){
            if(mO[table[collide[i][1]][collide[i][0]][j]].num > mO[max_position].num){
                max_position = table[collide[i][1]][collide[i][0]][j];
            }
        }
        for(j = 1; j <= col_num; ++j){
            if(table[collide[i][1]][collide[i][0]][j]!=max_position){
                mO[max_position].num += mO[table[collide[i][1]][collide[i][0]][j]].num;
                dummy[dummy_cnt] = table[collide[i][1]][collide[i][0]][j];
                dummy_cnt++;
            }
        }
        table[mO[max_position].y][mO[max_position].x][0] = 1;
        table[mO[max_position].y][mO[max_position].x][1] = max_position;
    }
}

void dummySort(int start, int end){
    int length = end-start+1;
    if(length>1){
        int p = start + length/2;
        int temp = dummy[p];
        dummy[p] = dummy[end];
        dummy[end] = temp;
        int finger1 = start, finger2;
        for(finger2 = start; finger2<end; ++finger2){
            if(dummy[finger2]>dummy[end]){
                temp = dummy[finger1];
                dummy[finger1] = dummy[finger2];
                dummy[finger2] = temp;
                finger1++;
            }
        }
        temp = dummy[finger1];
        dummy[finger1] = dummy[end];
        dummy[end] = temp;
        dummySort(start, finger1-1);
        dummySort(finger1+1, end);
    }

}

void removeDummy(){
    int i;
    dummySort(0, dummy_cnt-1);
    for(i = 0; i < dummy_cnt; ++i){
        mO[dummy[i]].x = mO[K-1].x;
        mO[dummy[i]].y = mO[K-1].y;
        mO[dummy[i]].num = mO[K-1].num;
        mO[dummy[i]].dir = mO[K-1].dir;
        K--;
    }
}

void tableInit(){
    int i;
    for(i = 0; i< K; ++i){
        table[mO[i].y][mO[i].x][table[mO[i].y][mO[i].x][0]] = 0;
        table[mO[i].y][mO[i].x][0]--;
    }
}
int makeAns(){
    int sum = 0, i;
    for(i=0; i <K; ++i){
        sum += mO[i].num;
    }
    return sum;
}


void theTimeGoesOn(){
    int i, j;
    for (i=0; i < M; ++i){
        microOrganismMove();
        microOrganismMedicine();
        microOrganismCollide();
        removeDummy();
        tableInit();
    }
}



int main(){
    int test_case, T, i;
    cin >> T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N >> M >> K;
        for(i=0; i < K; ++i){
            cin >> mO[i].y >> mO[i].x >> mO[i].num >> mO[i].dir;
        }
        theTimeGoesOn();
        cout << "#" << test_case << " " << makeAns() << endl;
    }
    return 0;
}