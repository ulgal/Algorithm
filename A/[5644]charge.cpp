#include<iostream>
using namespace std;
int table[11][11][9] = {0}; // {x, y, 0: battery_sum, 1~: battery_sorted}
int battery[9][4] = {0}; // {battery_x, battery_y, battery_length, battery_power}
int battery_cnt;
int move_a[100];
int move_b[100];
int move_cnt;

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}
int min(int a, int b){
    if(a>b)
        return b;
    else
        return a;
}
void swap_array(int *arr1, int *arr2, int length){
    for(int i = 0; i < length; i++){
        int tmp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = tmp;
    }
}

void battery_sort(int first, int last){
    int length = last - first + 1;
    if(length>1){
        int p = length / 2;
        swap_array(battery[first +p], battery[last], 4);
        int finger1 = first;
        for(int finger2 = first; finger2 < last; finger2++){
            if(battery[finger2][3] > battery[last][3]){
                swap_array(battery[finger1], battery[finger2], 4);
                finger1++;
            }
        }
        swap_array(battery[finger1], battery[last], 4);
        battery_sort(first, finger1-1);
        battery_sort(finger1+1, last);
    }
}

void battery_mark(){
    for(int i = 1; i <= battery_cnt; i++){
        int x = battery[i][0], y = battery[i][1], range = battery[i][2];
        for(int j = -range; j <= range; j++){
        	for(int k = -range; k <= range; k++){ // j + k <= range,
            	if((( x + j ) > 0) && (( x + j ) < 11) && (( y + k ) > 0) &&(( y + k ) < 11)){
                	if(j<=0&&k<=0){
                    	if(-1*(j+k)<=range){
                        	table[y+k][x+j][i] = i;
                            table[y+k][x+j][0]++;
                        }
                    }
                    else if(j>=0&&k<=0){
                    	if((j-k)<=range){
                        	table[y+k][x+j][i] = i;
                            table[y+k][x+j][0]++;
                        }
                    }
                    else if(j<=0&&k>0){
                    	if((-j+k)<=range){
                    		table[y+k][x+j][i] = i;
                            table[y+k][x+j][0]++;
						}
					}
                    else if(j>=0&&k>=0){
                    	if((j+k)<=range){
							table[y+k][x+j][i] = i;
                            table[y+k][x+j][0]++;
                        }
                    }
                }
            }
        }
    }
}

void battery_unmark(){
    for(int i = 1; i <= battery_cnt; i++){
        int x = battery[i][0], y = battery[i][1], range = battery[i][2];
        for(int j = -range; j <= range; j++){
        	for(int k = -range; k <= range; k++){ // j + k <= range,
            	if((( x + j ) > 0) && (( x + j ) < 11) && (( y + k ) > 0) &&(( y + k ) < 11)){
                	table[y+k][x+j][0] = 0;
                    table[y+k][x+j][i] = 0;
                }
            }
        }
    }
}
int move_ab(int a1, int a2, int b1, int b2, int curr_move_cnt){
    int ax = a1, ay = a2, bx = b1, by = b2;
    int ans = 0;
    int battery_candidate[2][2] = {{0, 0}, {0, 0}};
    if(table[ay][ax][0]==1){
        for(int i = 1; i < 9; i++){
            if(table[ay][ax][i]!=0){
                battery_candidate[0][0] = table[ay][ax][i];
                break;
            }
        }
    }
    else if(table[ay][ax][0]>1){
        for(int i = 1; i < 9; i++){
            if(table[ay][ax][i]!=0){
                battery_candidate[0][0] = table[ay][ax][i];
                for(int j = i+1; j < 9; j++){
                    if(table[ay][ax][j]!=0){
                        battery_candidate[0][1] = table[ay][ax][j];
                        break;
                    }
                }
                break;
            }
        }
    }
    
    if(table[by][bx][0]==1){
        for(int i = 1; i < 9; i++){
            if(table[by][bx][i]!=0){
                battery_candidate[1][0] = table[by][bx][i];
                break;
            }
        }
    }
    else if(table[by][bx][0]>1){
        for(int i = 1; i < 9; i++){
            if(table[by][bx][i]!=0){
                battery_candidate[1][0] = table[by][bx][i];
                for(int j = i+1; j < 9; j++){
                    if(table[by][bx][j]!=0){
                        battery_candidate[1][1] = table[by][bx][j];
                        break;
                    }
                }
                break;
            }
        }
    }
    if(battery_candidate[0][0] != battery_candidate[1][0]){
        ans += battery[battery_candidate[0][0]][3] + battery[battery_candidate[1][0]][3];
    }
    else{
        ans += max(battery[battery_candidate[0][0]][3], battery[battery_candidate[1][0]][3]) + max(battery[battery_candidate[0][1]][3], battery[battery_candidate[1][1]][3]);
    }
    if(curr_move_cnt<move_cnt){
        if(move_a[curr_move_cnt]==1){
            ay--;
        }
        else if(move_a[curr_move_cnt] ==2){
            ax++;
        }
        else if(move_a[curr_move_cnt] == 3){
            ay++;
        }
        else if(move_a[curr_move_cnt]==4){
            ax--;
        }
        
        if(move_b[curr_move_cnt]==1){
            by--;
        }
        else if(move_b[curr_move_cnt] ==2){
            bx++;
        }
        else if(move_b[curr_move_cnt] == 3){
            by++;
        }
        else if(move_b[curr_move_cnt]==4){
            bx--;
        }
        curr_move_cnt++;
        return ans + move_ab(ax, ay, bx, by, curr_move_cnt);
    }
    else{
        return ans;
    }
}
        

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int ans = 0;
        cin >> move_cnt >> battery_cnt;
        for(int i = 0; i < move_cnt; i++){
            cin >> move_a[i];
        }
        for(int i = 0; i < move_cnt; i++){
            cin >> move_b[i];
        }
        for(int i = 1; i <= battery_cnt; i++){
            cin >> battery[i][0] >> battery[i][1] >> battery[i][2] >> battery[i][3];
        }
        battery_sort(1, battery_cnt);
		battery_mark();
        ans += move_ab(1, 1, 10, 10, 0);
		cout << "#" << test_case << " " << ans << endl;
        battery_unmark();
	}
	return 0;
}