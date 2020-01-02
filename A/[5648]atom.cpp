#include<iostream>
using namespace std;
int atom[1000][4];//    {x, y, direction, score}
int atom_num;
int init_atom_num;
int collide_xy[500][2];
int table[4001][4001] = {0};
 
void swap_array(int *arr1, int *arr2, int length){
    for(int i = 0; i < length; i++ ){
        int temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
}   
 
int atom_move(int lklk){
    int collide_idx = 0;
    for(int idx = 0; idx < atom_num; idx++){
        if(atom[idx][2]==0){
            atom[idx][1]++;
        }
        else if(atom[idx][2]==1){
            atom[idx][1]--;
        }
        else if(atom[idx][2]==2){
            atom[idx][0]--;
        }
        else if(atom[idx][2]==3){
            atom[idx][0]++;
        }
        if ((atom[idx][0]>2000) || (atom[idx][0]<-2000) || (atom[idx][1]>2000) || (atom[idx][1]<-2000)){
            swap_array(atom[idx], atom[atom_num-1], 4);
            atom_num--;
            idx--;
        }
        else{
            table[2000 + atom[idx][0]][2000 +atom[idx][1]]++;
            if((table[2000 + atom[idx][0]][2000 +atom[idx][1]])==2){
                collide_xy[collide_idx][0] = atom[idx][0];
                collide_xy[collide_idx][1] = atom[idx][1];
                collide_idx++;
            }
        }
    }
    for(int idx = 0; idx < atom_num; idx++){
        table[2000 + atom[idx][0]][2000 +atom[idx][1]] = 0;
    }
    return collide_idx;
}
int atom_collide(int collide_idx){
    if(collide_idx == 0){
        return 0;
    }
    int ans = 0;
    for(int idx = 0; idx < collide_idx; idx++){
        int x = collide_xy[idx][0];
        int y = collide_xy[idx][1];
        for(int i = 0; i < atom_num; i++){
            if((x==atom[i][0]) && (y==atom[i][1])){
                ans += atom[i][3];
                swap_array(atom[i], atom[atom_num-1], 4);
                atom_num--;
                i--;
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
        cin >> atom_num;
        init_atom_num = atom_num;
        for(int i = 0; i < atom_num; i++){
            cin >> atom[i][0] >> atom[i][1] >> atom[i][2] >> atom[i][3];
            atom[i][0] *=2;
            atom[i][1] *=2;
        }
        if(atom_num>1){
            for(int i = 0; i < 4002; i++){
                if(atom_num<2){
                    break;
                }
                ans += atom_collide(atom_move(i));
            }
        }
        cout << "#" << test_case << " " << ans <<endl;
    }
    return 0;
}
