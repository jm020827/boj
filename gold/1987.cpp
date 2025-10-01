#include <iostream>
using namespace std;
int r, c;
char board[20][20];
bool isFull = false;
int dist = 1;

void dfs(int y, int x, int depth, int check) {
    if(isFull) {
        return;
    }
    if(depth == 26) {
        isFull = true;
        dist = depth;
        return;
    }
    
    if(check & (1 << (board[y][x]-'A'))) {
        if(dist < depth) {
            dist = depth;
        }
        return;
    }
    else {
        check |= (1 << (board[y][x] - 'A'));
        if(y > 0) {
            dfs(y-1, x, depth+1, check);
        }
        if(x > 0) {
            dfs(y, x-1, depth+1, check);
        }
        if(y < r-1) {
            dfs(y+1, x, depth+1, check);
        }
        if(x < c-1) {
            dfs(y, x+1, depth+1, check);
        }
    }
    
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cin >> board[i][j];
        }
    }
    
    dfs(0,0,0, 0);
    
    cout << dist;

    return 0;
}


/*

1987 - RxC 크기의 판에서 알파벳의 중복 없이 말이 최대 몇칸을 이동할 수 있는지 구하는 문제

중복 아닌 알파벳은 비트마스킹으로 확인하며 dfs로 board를 순회하며 최대 길이를 찾는다.  

*/