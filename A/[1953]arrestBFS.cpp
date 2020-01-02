#include<iostream>
using namespace std;
//bfs로 구현하는게 좋다
int N, M, K, R, C, ans;
int map[50][50] = {0};
bool checked[50][50] = {false};

struct Node{
    int x;
    int y;
    int n;
    int dir;
    class Node* next;
};

Node *listFirst;
Node *listEnd;

void listInit(){
    if(listFirst == NULL){
        return;
    }
    else{
        Node * cur;
        cur = listFirst;
        while(cur!=NULL){
            listFirst = cur->next;
            free(cur);
            cur = listFirst;
        }
    }
}

void listAdd(int x1, int y1, int n1, int dir1){
    Node * new_node = (Node*)malloc(sizeof(Node));
    new_node->x = x1;
    new_node->y = y1;
    new_node->n = n1;
    new_node->dir = dir1;
    new_node->next = NULL;

    if(listFirst == NULL){
        listFirst = new_node;
        listEnd = listFirst;
    }
    else{
        listEnd->next = new_node;
        listEnd = new_node;
    }
}


void checkingBfs(){
    Node *curr = listFirst;
    while(curr->next!=NULL){
        curr = (curr->next);
        int x = curr->x;
        int y = curr->y;
        int n = curr->n;
        int dir = curr->dir;
        if(checked[y][x]){
            continue;
        }
        if(n>K){
            break;
        }
        if(!(x>=0 && x<M && y>=0 && y<N)){
            continue;
        }
        switch(map[y][x]){
            case 1://cout << y << " " << x << " " << n << " " << 1 << endl;
                {
                    checked[y][x] = true;
                    ans++;
                    listAdd(x+1, y, n+1, 4);
                    listAdd(x-1, y, n+1, 3);
                    listAdd(x, y+1, n+1, 2);
                    listAdd(x, y-1, n+1, 1);
                    break;
                }
            case 2:
                {if(dir!=3 && dir != 4){//cout << y << " " << x << " " << n << " " << 2 << endl;
                    checked[y][x] = true;                    
                    ans++;
                    listAdd(x, y+1, n+1, 2);
                    listAdd(x, y-1, n+1, 1);
                }
                break;}
            case 3:
                {if(dir!=1 && dir != 2){//cout << y << " " << x << " " << n << " " << 3 << endl;
                    checked[y][x] = true;                    
                    ans++;
                    listAdd(x+1, y, n+1, 4);
                    listAdd(x-1, y, n+1, 3);
                }
                break;}
            case 4:
                {if(dir!=1 && dir != 4){//cout << y << " " << x << " " << n << " " << 4 << endl;
                    checked[y][x] = true;                   
                    ans++;
                    listAdd(x+1, y, n+1, 4);
                    listAdd(x, y-1, n+1, 1);
                }
                break;}
            case 5:
                {if(dir!=2 && dir != 4){//cout << y << " " << x << " " << n << " " << 5 << endl;
                    checked[y][x] = true;                    
                    ans++;
                    listAdd(x+1, y, n+1, 4);
                    listAdd(x, y+1, n+1, 2);
                }
                break;}
            case 6:
                {if(dir!=2 && dir != 3){//cout << y << " " << x << " " << n << " " << 6 << endl;
                    checked[y][x] = true;                    
                    ans++;
                    listAdd(x-1, y, n+1, 3);
                    listAdd(x, y+1, n+1, 2);
                }
                break;}
            case 7:
                {if(dir!=1 && dir != 3){//cout << y << " " << x << " " << n << " " << 7 << endl;
                    checked[y][x] = true;                    
                    ans++;
                    listAdd(x-1, y, n+1, 3);
                    listAdd(x, y-1, n+1, 1);
                }
                break;}
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
			}
		}
        ans = 0;
        listInit();
        listAdd(-1, -1, 0, 0);
        listAdd(C, R, 1, 0);
        checkingBfs();
        cout << "#" << test_case << " " << ans << endl;
    }
}