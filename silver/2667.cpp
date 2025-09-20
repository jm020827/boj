#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int n;
int visited[25][25];
int cnt;
int dstY[4] = {-1, 0, 1, 0};
int dstX[4] = {0, -1, 0, 1};
int house[625];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<string> map(n);
    for(int i=0;i<n;i++){
        cin >> map[i];
    }
    
    
    
    queue<pair<int, int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j] == '1' && visited[i][j] == 0) {
                cnt++;
                visited[i][j] = cnt;
                q.push({i,j});
                house[cnt]++;
                while(!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();
                    int y = p.first;
                    int x = p.second;
                    
                    for(int k=0;k<4;k++) {
                        int ny = y+dstY[k];
                        int nx = x+dstX[k];
                        if(ny >= 0 && ny < n && nx >=0 && nx < n) {
                            if(map[ny][nx] == '1' && visited[ny][nx] == 0) {
                                visited[ny][nx] = cnt;
                                q.push({ny, nx});
                                house[cnt]++;
                            }
                        }
                    }
                }
                
            }
        } 
    }
    
    sort(house+1, house+cnt+1);
    cout << cnt << "\n";
    for(int i=1;i<=cnt;i++) {
        cout << house[i] << "\n";
    }
    

    return 0;
}


/*

2667 - N*N 지도에서 붙어있는 집들로 이루어진 단지의 개수와 각 단지별 집의 개수를 출력하는 문제

bfs를 활용해 집을 추적해 단지를 세고 단지 내 집 개수를 센 후 출력하여 해결.

*/