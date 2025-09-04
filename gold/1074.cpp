#include <iostream>
using namespace std;

int n, r, c;
int cnt = -1;

void visit_square(int n, int y, int x) {
    if(n == 0) {
        cnt++;
        if(y == r && x == c) {
            cout << cnt;
        }
        return;
    }
    if(y > r || r >= y+(1 << n) || x > c || c >= x+(1 << n)) {
        cnt += (1 << (n*2));
        return;
    }
    
    int two = 1 << n;
    
    
    for(int i=y;i<y+two;i+=(two/2)) {
        for(int j=x;j<x+two;j+=(two/2)) {
            visit_square(n-1, i, j);
        }
    }
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> r >> c;

    visit_square(n, 0, 0);


    return 0;
}

/*

1074 - (2^N) X (2^N) 크기의 2차원 배열에서 Z 를 그리며 매 칸을 방문할 때, (r,c) 위치는 몇번째로 방문하는지 구하는 문제

2차원 배열에서 Z 모양으로 2^(N-1) 씩 이동하고 N 을 1씩 줄여가며 분할 정복 재귀로 방문을 진행함
그러나 시간초과가 떠서 아예 r,c 를 포함하고 있지 않은 범위에 들어온 경우 그 범위의 부분 배열을 전부 지나왔다고 치고 cnt 를 크기만큼 증가시키고 넘어가여 시간을 단축시킴  

*/