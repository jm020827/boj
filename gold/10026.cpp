#include <iostream>
using namespace std;
int n;
char paint[105][105];

void dfs(int y, int x, char color) {
    paint[y][x] += 32;
    
    if(y > 0 && paint[y-1][x] == color) {
        dfs(y-1, x, color);
    }
    if(x > 0 && paint[y][x-1] == color) {
        dfs(y, x-1, color);
    }
    if(y < n-1 && paint[y+1][x] == color) {
        dfs(y+1, x, color);
    }
    if(x < n-1 && paint[y][x+1] == color) {
        dfs(y, x+1, color);
    }
}

void print_paint() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << paint[i][j];            
        }
        cout << "\n";
    }
    cout << "\n";
}

void reset_blind() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            paint[i][j] -= 32;
            if(paint[i][j] == 'G') {
                paint[i][j] = 'R';
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> paint[i][j];            
        }
    }
    
    int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(paint[i][j] < 97) {
                dfs(i, j, paint[i][j]);
                cnt++;
            }
        }
    }
    
    reset_blind();
    cout << cnt << " ";
    
    
    cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(paint[i][j] < 97) {
                dfs(i, j, paint[i][j]);
                cnt++;
            }
        }
    }
    
    cout << cnt;

    return 0;
}


/*

10026 - N x N 크기의 R,G,B 로 가득찬 그림에서 적록색맹이 아닌 사람과 적록색맹인 사람이 구별하는 구역의 개수를 구하는 문제

paint[][] 를 순회하여 새로운 색을 만날 때마다 dfs 로 구역을 소문자로 바꿔 마킹하고, 구역의 개수를 증가시키며 구한다.
이후 G 를 R 로 바꿔 적록색맹이 보는 paint 로 바꾸고 똑같이 순회하여 구역의 개수를 구한다. 

*/