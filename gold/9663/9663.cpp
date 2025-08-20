#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n;

void drawBoard(int row, bool col[], bool crossRight[], bool crossLeft[]) {
    vector<vector<char>> board(n, vector<char>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if( i <= row && col[j] &&
    	        crossRight[15 + i-j] &&
	            crossLeft[i+j] ) {
	                board[i][j] = 'Q';
	            }
            if( i == row || col[j] ||
    	        crossRight[15 + i-j] ||
	            crossLeft[i+j]) { // column ||  우하향 대각선 || 우상향 대각선이 겹치는 경우
	                if(board[i][j] != 'Q') {
	                    board[i][j] = 'X';
	                }
            }
            else {
	                board[i][j] = 'O';
            }
        }
        cout << "\n";
    }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
    
    cout << "\n";
}


int dfs(int depth, int cnt, bool col[], bool crossRight[], bool crossLeft[]) {
	if(depth == n) {
		return cnt+1;
	}
	
	
	for(int j=0; j<n; j++) {
	   // cout << "[depth " << depth << " / column : " << j << "]\n";
        if( col[j] ||
    	        crossRight[14 + depth-j] ||
	            crossLeft[depth+j]) { // column ||  우하향 대각선 || 우상향 대각선이 겹치는 경우
            // cout << "skip\n";
            continue;
        }
	    
	    col[j] = true;
	    crossRight[14+ depth-j] = true;
	    crossLeft[depth+j] = true;
	    
        // drawBoard(depth, col, crossRight, crossLeft);
	    cnt = dfs(depth+1, cnt, col, crossRight, crossLeft);
	   // cout << "depth " << depth << " / cnt : " << cnt << "\n";
	    col[j] = false;
	    crossRight[14 + depth-j] = false;
	    crossLeft[depth+j] = false;
	}
	
	return cnt;
}

int main()
{
	int cnt = 0;
	cin >> n;

	vector<pair<int,int>> queenplace;
	
	bool col[15] = {false}; // 같은 열
	bool crossRight[29] = {false}; // 우하향 (차가 같으면 겹침)
	bool crossLeft[29] = {false}; // 우상향 (합이 같으면 겹침)


	cnt = dfs(0, 0, col, crossRight, crossLeft);

	cout << cnt;

	return 0;
}

/*

9663 - N * N 의 체스판에 N 개의 퀸이 서로 공격당하지 않도록 배치하는 경우의 수를 구하는 문제.

처음에 브루트포스 (전체 탐색) 만 생각하고 풀어서 n*n 크기의 2차원 vector board를 만들고 거기에 하나하나 표시, 확인해가며 풀었으나 당연히 타임 오버

그 다음엔 board를 지우고 vector<pair<int,int>> 자료형의 queenspace 를 만들어 
queen 의 위치만 기록, 매번 매 depth의 매 칸마다 퀸에게 공격받는지를 판단했더니 조금은 개선됐으나 여전히 타임오버

그래서 아예 queen 의 위치를 기록하지말고 아예 공격당하는 위치만 기록하도록 바꿈. 
col, crossRight, crossLeft 로 각각 같은 열, 같은 우하향 대각선, 같은 우상향 대각선에 위치해있는지만 확인하도록 함.
col은 같은 index 값이 true이면, crossRight는 행,열의 차가 같은 index의 값이 true면, crossLeft는 합이 같은 index 의 값이 true면 공격당하는 위치로 판단
-> O(1) 만에 판단 가능해짐.
-> 판단 연산을 O(1) 내에 끝내게 만드니 브루트포스 알고리즘임은 동일하나 기하급수적으로 시간을 단축시킬 수 있었음.

**** 
백트래킹 : dfs와 유사하지만 약간 다른 점은 아니다 싶으면 다시 돌아오는 것. 
이 코드에서는 dfs 내의 반복문에서 조건에 맞으면, dfs를 타고 더 깊이까지 들어가도록, 조건에 맞지않으면 return 0 로 나오도록 구현했다.
****

P.S. 
cnt 를 dfs 끝에서 +1 해주는 것이 헷갈려서 처음에 좀 헤맸다 ㅋㅋ 
중간에 cnt+ dfs() 이런식으로 짜기도하고.. 
dfs, 백트래킹, 브루트포스 최적화 등에 대해 알아갈 수 있는 문제였다.


*/