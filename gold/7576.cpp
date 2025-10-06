#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int m,n;
int board[1005][1005];
int visited[1005][1005];
int depth[1005][1005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> board[i][j];
		}
	}

	queue<pair<int,int>> q;


	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(board[i][j] == 1) {
				q.push({i,j});
		        visited[i][j] = 1;
				depth[i][j] = 0;
			}
		}
	}

	int i = 0;
	int j = 0;

	while(!q.empty()) {

		pair<int,int> p = q.front();
		q.pop();

		i = p.first;
		j = p.second;

		board[i][j] = 1;

		if(i > 0 && board[i-1][j] == 0 && visited[i-1][j] == 0) {
			q.push({i-1,j});
			visited[i-1][j] = 1;
			depth[i-1][j] = depth[i][j] + 1;
		}
		if(j > 0 && board[i][j-1] == 0 && visited[i][j-1] == 0) {
			q.push({i,j-1});
			visited[i][j-1] = 1;
			depth[i][j-1] = depth[i][j] + 1;
		}
		if(i < n-1 && board[i+1][j] == 0 && visited[i+1][j] == 0) {
			q.push({i+1,j});
			visited[i+1][j] = 1;
			depth[i+1][j] = depth[i][j] + 1;
		}
		if(j < m-1 && board[i][j+1] == 0 && visited[i][j+1] == 0) {
			q.push({i,j+1});
			visited[i][j+1] = 1;
			depth[i][j+1] = depth[i][j] + 1;
		}

	}
	
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(board[i][j] == 0) {
                cout << -1;
                return 0;
			}
		}
	}

	cout << depth[i][j];


	return 0;
}

/*

7576 - NxM 크기 박스의 각 칸에 들어있는 과일의 익음이 전파되는데 걸리는 날을 구하는 문제.

NxM 2차원 배열에 대해 bfs 로 해결한다.
depth 는 동일한 모양의 2차원 배열에 매 칸마다 depth 를 마킹하는 식으로 기록해두고, 
마지막 반복이 가장 긴 날이었을 것이므로 마지막 반복 위치의 좌표에 적힌 depth 를 출력하도록 함.

depth 를 통해 간략히 방문 여부를 확인하려 했던 것은 첫 시작 좌표의 depth = 0 이므로 첫 시작 좌표로 재방문하는 경우도 생김  
-> visited 배열에 따로 즉각 방문 표시하여 방문 체크

*/