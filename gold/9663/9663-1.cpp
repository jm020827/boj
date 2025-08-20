#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n;

// void drawBoard(vector<pair<int,int>>& queenplace) {
//     vector<vector<char>> board(n, vector<char>(n));
//     for(int i=0;i<n;i++) {
//         for(int j=0;j<n;j++) {
//             for(pair<int,int> q : queenplace) {
//                 if(q.first == i && q.second == j && board[i][j] == 0 || board[i][j] == 'O') {
//     	            board[i][j] = 'Q';
//     	            break;
//     	        }
//     	        else if( q.first == i || q.second == j 
//     	            || q.first - q.second == i - j 
//     	            || q.first + q.second == i + j) { // column ||  우하향 대각선 || 우상향 대각선이 겹치는 경우
//     	            board[i][j] = 'X';
//                     break;
//     	        }
//     	        else {
//     	            board[i][j] = 'O';
//     	            break;
//     	        }
// 	        }
//         }
//         cout << "\n";
//     }
    
//     for(int i=0;i<n;i++) {
//         for(int j=0;j<n;j++) {
//             cout << board[i][j];
//         }
//         cout << "\n";
//     }
    
//     for(pair<int,int> q : queenplace) {
//         cout << "{" << q.first << ", " << q.second << "}\n";
//     }
//     cout << "\n";
// }


int dfs(int depth, int cnt, vector<pair<int,int>>& queenplace) {
	if(depth == n) {
		return cnt+1;
	}
	
	
	for(int j=0; j<n; j++) {
        // cout << "-----[depth " << depth << "/ column " << j << "]-----\n";
	    int skip = 0;
	    for(pair<int,int> q : queenplace) {
	        if( q.second == j 
	            || q.first - q.second == depth - j 
	            || q.first + q.second == depth + j) { // column ||  우하향 대각선 || 우상향 대각선이 겹치는 경우
                skip = 1;	            
	        }
	    }
	    if(skip == 1) {
	       // cout << "skip\n";
	        continue;
	    }
        queenplace.push_back({depth, j});
	    
        // drawBoard(queenplace);
	    cnt = dfs(depth+1, cnt, queenplace);
	   // cout << "depth " << depth << " / cnt : " << cnt << "\n";
		queenplace.pop_back();
	}
	
	return cnt;
}

int main()
{
	int cnt = 0;
	cin >> n;

	vector<pair<int,int>> queenplace;

	int queen = n;

	cnt = dfs(0, 0, queenplace);

	cout << cnt;

	return 0;
}

/*
9663 - 개선된 버전.

board를 무식하게 그리지 않고 queen 의 위치들만 vector에 저장해서 매 depth의 매 column마다 공격당하는 위치인지 판단함.
하지만 여전히 for loop 를 이용하므로 
최대 N (depth) * N (column) * N (queen) 의 반복 필요.

Time out!

*/