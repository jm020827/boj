#include <iostream>
using namespace std;
int n;
int b[2200][2200];
int cnt[3];

void slice_paper(int y, int x, int size) {
    bool isFull = true;
    int num = b[y][x];
    for(int i=y;i<y+size;i++) {
        for(int j=x;j<x+size;j++) {
            if(b[i][j] != num) {
                isFull = false;
            }
        }
    }
    
    if(isFull) {
        cnt[num+1] ++;
        return;
    }
    else {
        for(int i=y;i<y+size;i+=(size/3)) {
          for(int j=x;j<x+size;j+=(size/3)) {
                slice_paper(i,j,size/3);
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
            cin >> b[i][j];
        }
    }
    
    slice_paper(0,0,n);
    
    
    for(int i=0;i<3;i++) {
        cout<< cnt[i] << "\n";
    }

    return 0;
}

/*

1780 - -1, 0, 1 로 가득찬 N x N 행렬에서 각 수로 가득찬 행렬의 개수를 구하는 문제

매 크기 단계별로 한 숫자로 가득차있는 경우 cnt를 증가,
가득차 있지 않을 경우 분할 정복으로 9개로 쪼개 재귀적으로 구함 

*/