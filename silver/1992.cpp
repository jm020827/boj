#include <iostream>
using namespace std;
int n;
char b[64][64];

char q[4097];
int cnt = 0;

void quadTree(int y, int x, int size) {
    int k = b[y][x];
    bool isFull = true;
    for(int i=y;i<y+size;i++){
        for(int j=x;j<x+size;j++){
            if(b[i][j] != k) {
                isFull = false;
                break;
            }
        }
        if(!isFull) {
            break;
        }
    }
    
    if(isFull) {
        q[cnt++] = k;
    }
    else {
        int half = size/2;
        q[cnt++] = '(';
        for(int i=0;i<size;i+=half){
            for(int j=0;j<size;j+=half){
                quadTree(y+i,x+j,half);
            }
        }
        q[cnt++] = ')';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> b[i][j];   
        }
    }
    
    
    quadTree(0,0,n);
    
    for(int j=0;j<cnt;j++){
        cout << q[j];   
    }
    

    return 0;
}

/*

1992 - 0과 1 로 이루어진 흑백 영상을 압축하는 쿼드 트리 데이터 구조를 구현하는 문제.
0과 1로 가득찬 2차원 배열을 (좌상단/우상단/좌하단/우하단) 순서로 0또는 1로 가득 차있는 부분은 0,1로 각각 표현하여 압축하는 구조.
예 : (0(0011)(0(0111)01)1)

분할정복으로 지정 위치에서 지정 크기만큼의 부위가 한 비트로 가득차있다면, 그 값을 반환,
그렇지 않다면 좌상-우상-좌하-우하로 4등분해 한 값으로 가득찬 부분으로 줄어들때까지 재귀한다.
char 배열에 (사실상 queue 역할) 그 순서대로 값을 저장한 뒤 그대로 출력한다.

*/