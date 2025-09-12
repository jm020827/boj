#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int n,m;
char maze[105][105];
int dist[105][105];

int distX[] = {0, -1, 0, 1};
int distY[] = {-1, 0, 1, 0};

// void print_maze() {
//     for(int i=0;i<n;i++) {
//         for(int j=0;j<m;j++) {
//             cout << maze[i][j];
//         }
//         cout << "\n";
//     }
//     cout << "\n";
// }

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> maze[i];
    }
    
    queue<pair<char, char>> q;
    
    q.push({0,0});
    dist[0][0] = 1;
    
    int minLen = 10005;
    int distance = 0;
    
    // cout << "\n";
    // print_maze();
    
    while(!q.empty()) {
        pair<char, char> curr = q.front();
        q.pop();
        
        int y = curr.first;
        int x = curr.second;
        
        if(y == n && x == m) {
            break;
        }
        
        
        for(int i=0;i<4;i++){
            // cout << "maze[" << y << " + " << distY[i] << "][" << x <<  " + " << distX[i] << "] == " << maze[y + distY[i]][x + distX[i]] << "\n";
            if(maze[y + distY[i]][x + distX[i]] == '1') {
                q.push({y + distY[i], x + distX[i]});
                maze[y + distY[i]][x + distX[i]] += 1;
                dist[y + distY[i]][x + distX[i]] = dist[y][x] + 1;
            }
        }
        
        // cout << "dist[" << y << "][" << x << "] = " << dist[y][x] << "\n"; 
        // print_maze();
        
        
    }
    
    cout << dist[n-1][m-1];
    
    
    return 0;
}

/*

2178 - N x M 크기의 미로의 (1,1) 에서 (N,M) 까지 닿는 최소거리를 구하는 문제

bfs로 현재 위치 기준 네 방향의 좌표를 전부 queue 에 넣어두고 
maze와 같은 크기의 2차원 배열 dist에 현재 거리 + 1 을 집어넣어 각 위치별 거리를 저장해둠
bfs를 돌다가 가장 먼저 (N,M) 도달하는 경우가 가장 짧은 거리이므로
바로 dist[n-1][m-1] 출력해 해결.

*/