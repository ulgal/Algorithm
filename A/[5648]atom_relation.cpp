#include<iostream>
using namespace std;
int atom[1001][4]; //	{x, y, direction, score} // 0 to 999 - input , 1000 - null state
int atom_num; // input atom num
int collide_candidate_cnt; // possible collide pair
struct Collide{ // collide after - n time
    int x;
    int y;
    int collide_after;
};
Collide collide_candidate[1000000]; // max_atom_num - 1000, max_pair -> 999*1000/2 = 499500(impossible)

void can_collide(int x, int y){ // 충돌 가능한 후보 배열에 넣어주기
    if(atom[x][0] > atom[y][0]){
        int temp = x;
        x = y;
        y = temp;
    }
    if(atom[x][2]== 0 && atom[y][2] == 1){ // 상 + 하
        if( (atom[x][0] == atom[y][0]) && (atom[x][1] < atom[y][1]) )
            collide_candidate[collide_candidate_cnt++] = {x, y, (atom[y][1]-atom[x][1])/2};
    }
    else if(atom[x][2] == 0 && atom[y][2] == 2){ // 상 + 좌
        if( (atom[y][0] - atom[x][0])==(atom[y][1] - atom[x][1]))
            collide_candidate[collide_candidate_cnt++] = {x, y, (atom[y][0] - atom[x][0])};
    }
    else if(atom[x][2]==1 && atom[y][2] == 0){ // 하 + 싱
        if( ( atom[x][0] == atom[y][0]) && (atom[x][1] > atom[y][1]) )
            collide_candidate[collide_candidate_cnt++] = {x, y, (atom[x][1] - atom[y][1])/2};
    }
    else if(atom[x][2] == 1 && atom[y][2] == 2){  // 하 + 좌
        if ( (atom[y][0]-atom[x][0]) == (atom[x][1] - atom[y][1]))
            collide_candidate[collide_candidate_cnt++] = {x, y, (atom[x][1] - atom[y][1])};
    }
    else if(atom[x][2] == 3 && atom[y][2] == 0){  // 우 + 상
        if ( (atom[y][0] - atom[x][0] ) == (atom[x][1] - atom[y][1]) )
            collide_candidate[collide_candidate_cnt++] = {x, y, (atom[x][1] - atom[y][1])};
    }
    else if(atom[x][2] == 3 && atom[y][2] == 1){ // 우 + 하
        if( (atom[y][0] - atom[x][0])==(atom[y][1] - atom[x][1]))
            collide_candidate[collide_candidate_cnt++] = {x, y, (atom[y][0] - atom[x][0])};
    }
    else if(atom[x][2] == 3 && atom[y][2] == 2){ // 우 + 좌
        if( (atom[x][1] == atom[y][1]))
            collide_candidate[collide_candidate_cnt++] = {x, y, (atom[y][0] - atom[x][0])/2};
    }
}

void col_swap(int x, int y){ // get index, swap by index
    Collide temp = collide_candidate[x];
    collide_candidate[x] = collide_candidate[y];
    collide_candidate[y] = temp;
}

void collide_sort(int first, int last){ // quick sort
    int length = last - first + 1;
    if(length > 1){
        col_swap(first + length/2, last);
        int finger1 = first;
        for(int finger2 = first; finger2 < last; finger2++){
            if(collide_candidate[finger2].collide_after < collide_candidate[last].collide_after){
                col_swap(finger1, finger2);
                finger1++;
            }
        }
        col_swap(finger1, last);
        collide_sort(first, finger1-1);
        collide_sort(finger1+1, last);
    }
}

int make_collide(){ // collide
    if(collide_candidate_cnt == 0)
        return 0;
    int ans = 0;
    for(int i = 0; i < collide_candidate_cnt; i++){
    	int cmp = collide_candidate[i].collide_after, finger = i;
        while((finger<collide_candidate_cnt) && (cmp==collide_candidate[finger].collide_after)) // 동시에 충돌하는 범위
            finger++;
        for(int j = i; j < finger; j++){ // i to finger-1까지 동시에 충돌, 충돌한 값들의 에너지 더해주고 충돌한 값은 x좌표 4444, 에너지값 0으로 초기화하여 중복 충돌 방지 
            ans += atom[collide_candidate[j].x][3] + atom[collide_candidate[j].y][3];
            atom[collide_candidate[j].x][0] = 4444;
            atom[collide_candidate[j].x][3] = 0;
            atom[collide_candidate[j].y][0] = 4444;
            atom[collide_candidate[j].y][3] = 0;
        }
        for(int j = finger; j < collide_candidate_cnt; j++){ // 충돌으로 사라진 값들 이후 시간대에서 찾은 후 포함 시 충돌 후보에서 null state로 보내기
            if((atom[collide_candidate[j].x][0]==4444) || (atom[collide_candidate[j].y][0]==4444)){
                collide_candidate[j].x = 1000;
                collide_candidate[j].y = 1000;
            }
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
        int ans = 0;
        collide_candidate_cnt = 0;
        cin >> atom_num;
        for(int i = 0; i < atom_num; i++){
            cin >> atom[i][0] >> atom[i][1] >> atom[i][2] >> atom[i][3];
            atom[i][0] *=2;
            atom[i][1] *=2;
        }
        if(atom_num>1){
            for(int i = 0; i < atom_num; i++){
                for(int j = i+1; j < atom_num; j++){
                    can_collide(i, j);
                }
            }
            collide_sort(0, collide_candidate_cnt-1);
            ans = make_collide();
        }
        cout << "#" << test_case << " " << ans <<endl;
	}
	return 0;
}
