#include <iostream>
using namespace std;

char paint[6570][6570];

void star(int n, int y, int x) {
    // cout << "n : " << n << " : (" << x << ", " << y << ")\n";
    if(n == 3) {
        for(int i=y;i<y+3;i++) {
            for(int j=x;j<x+3;j++) {
                if(i==y+1 && j==x+1) {
                    paint[i][j] = ' ';
                }
                else {
                    paint[i][j] = '*';
                }
            }
        }
    }
    else {
        for(int i=y;i<y+n;i+=n/3) {
            for(int j=x;j<x+n;j+=n/3) {
                
                if(i==y+n/3 && j==x+n/3) {
                    for(int a=y+n/3;a<y+2*n/3;a++) {
                        for(int b=x+n/3;b<x+2*n/3;b++) {
                            paint[a][b] = ' ';
                        }
                    }
                }
                else {
                    star(n/3, i, j);
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    
    cin >> n;
    
    star(n, 0, 0);
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << paint[i][j];
        }
        cout << "\n";
    }
 

    return 0;
}

/*

2447 - 3의 거듭제곱 크기의 특정모양이 반복되는 정사각형 (프랙탈) 을 그리는 문제

재귀를 이용한 분할 정복으로 해결.

*/