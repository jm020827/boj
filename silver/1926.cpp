#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m;
queue<pair<int,int>> q;
int paint[505][505];
int area = 0;
    
void bfs(int i, int j) {
    q.pop();
    area++;

    if(j > 0 && paint[i][j-1] == 1) {
        paint[i][j-1]++;
        q.push({i, j-1});
    }
    if(j < m && paint[i][j+1] == 1) {
        paint[i][j+1]++;
        q.push({i, j+1});
    }
    if(i > 0 && paint[i-1][j] == 1) {
        paint[i-1][j]++;
        q.push({i-1, j});
    } 
    if(i < n && paint[i+1][j] == 1) {
        paint[i+1][j]++;
        q.push({i+1, j});
    } 
    
    while(!q.empty()) {
        pair<int, int> newPos = q.front();
        bfs(newPos.first, newPos.second);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n, m;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> paint[i][j];
        }
    }
    
    
    int cnt = 0;
    int maxArea = 0;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(paint[i][j] == 1) {
                area = 0;
                pair<int,int> pos = {i,j};
                paint[i][j]++;
                q.push(pos);
                bfs(i,j);
                
                cnt++;
                if(area > maxArea) {
                    maxArea = area;
                }
            }
        }
    }
    
    cout << cnt << "\n" << maxArea;
    

    return 0;
}

/*

1926 - 1로 이어진 그림의 개수와 최대 넓이를 구하는 문제

그림을 2차원 배열에 옮기고, BFS 를 통해 각 그림의 개수와 넓이를 구했다.
이때 이미 방문한 위치는 값을 1 -> 2 로 증가시킴으로써 표시했고
넓이는 전역변수로 둬서 매 그림마다 매 위치 접근시 area 를 1 추가하도록 하고, 
그림을 모두 탐색하면 넓이 변수를 초기화하는 식으로 계산했다.

*/