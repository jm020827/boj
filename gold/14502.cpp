#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int n, m;
int map[8][8];
int visited[8][8];
int tmpMap[8][8];
pair<int,int> candidate[64];
int currSafe;
int maxSafe = 0;
queue<pair<int, int>> q;


void resetMap() {
    while(!q.empty()) {
        q.pop();
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(map[i][j] == 2) {
                q.push({i,j});
                visited[i][j] = 4;
            }
            if(map[i][j] == 0 && visited[i][j] >= 4) {
                tmpMap[i][j] = 0;
                visited[i][j] -= 4;
                currSafe ++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    currSafe = n*m;
    int tile = 0;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> tile;
            map[i][j] = tile;
            tmpMap[i][j] = tile;
            if(tile > 0) {
                currSafe --;
            }
            if(tile == 0) {
                candidate[cnt++] = {i,j};
            }
            if(tile == 2) {
                q.push({i,j});
                visited[i][j] += 4;
            }
        }
    }
    
    
    int wall;
    int x1,y1,x2,y2,x3,y3;
    pair<int,int> p1, p2, p3;
    for(int a=0;a<cnt-2;a++) {
        p1 = candidate[a];
        y1 = p1.first;
        x1 = p1.second;
        tmpMap[y1][x1] = 3;
        currSafe--;
        for(int b=a+1;b<cnt-1;b++) {
            p2 = candidate[b];
            y2 = p2.first;
            x2 = p2.second;
            tmpMap[y2][x2] = 3;
            currSafe--;
            for(int k=b+1;k<cnt;k++) {
                p3 = candidate[k];
                y3 = p3.first;
                x3 = p3.second;
                tmpMap[y3][x3] = 3;
                currSafe--;
                {
                    while(!q.empty()) {
                		pair<int,int> p = q.front();
                		q.pop();
                
                		int i = p.first;
                		int j = p.second;
                
                		tmpMap[i][j] = 2;
                		
                		if(i > 0 && tmpMap[i-1][j] == 0 && visited[i-1][j] < 4) {
                			q.push({i-1,j});
                			visited[i-1][j] += 4;
                			currSafe--;
                		}
                		if(j > 0 && tmpMap[i][j-1] == 0 && visited[i][j-1] < 4) {
                			q.push({i,j-1});
                			visited[i][j-1] += 4;
                			currSafe--;
                		}
                		if(i < n-1 && tmpMap[i+1][j] == 0 && visited[i+1][j] < 4) {
                			q.push({i+1,j});
                			visited[i+1][j] += 4;
                			currSafe--;
                		}
                		if(j < m-1 && tmpMap[i][j+1] == 0 && visited[i][j+1] < 4) {
                			q.push({i,j+1});
                			visited[i][j+1] += 4;
                			currSafe--;
                		}
                		
                		if(currSafe < maxSafe) {
                		    break;
                		}
                        
                    }
                    
                    
                    if(currSafe > maxSafe) {
                        maxSafe = currSafe;
                    }
                    
                    resetMap();
                    
                }
                tmpMap[y3][x3] = 0;
                currSafe++;
            }
            tmpMap[y2][x2] = 0;
            currSafe++;
        }
        tmpMap[y1][x1] = 0;
        currSafe++;
    }
    
    cout << maxSafe;

    return 0;
}

/*

14502 - N*M 크기의 지도에서 2로 표시되어있는 바이러스가 퍼지지 않는 안전영역이 최대가 되도록 3개의 벽을 세우는 문제

입력을 받을 때 후보 좌표들을 candidate에 저장해두고, 시작 바이러스 지점은 queue q 에 미리 저장해둔다.
그 뒤 candidate를 돌며 nmC3 개의 벽을 모두 세워보며 그때마다 바이러스가 bfs로 퍼지는 경우를 시뮬레이션해본다.
안전영역이 max safe 보다 적게 나와지는 순간 바로 백트래킹으로 해당 bfs를 취소시키며 시간을 줄였다.

처음엔 dfs로 벽 후보들을 구하고, depth가 3에 닿을 때 bfs 로 전환하는 방식으로 구현했으나
dfs로 3개 조합 구하는게 쉽지 않아서 candidate 배열에 저장해두고 3-pointer 전략으로 벽 세움

*/