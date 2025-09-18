#include <iostream>
// #include <set>
using namespace std;
int sudoku[9][9];
bool row[9][9], col[9][9],box[9][10];
bool isFin = false;

int getBox(int i, int j) {
    return 3*(i/3) + j/3;
}

void print_depth(int depth) {
    for(int i=0;i<depth;i++) {
        cout << " ";
    }
}

void print_sudoku() {
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }
}


bool check(int y, int x, int n) {
    if(row[y][n] == true) return false;
    if(col[x][n] == true) return false;
    if(box[getBox(y,x)][n] == true) return false;
    return true;
}

void solve(int y, int x) {
    if(isFin) return;
    if(y == 9) {
        isFin = true;
        print_sudoku();
        return;
    }
    
    int ny = (x == 8 ? y+1 : y);
    int nx = (x == 8 ? 0 : x+1);
    
    if(sudoku[y][x] == 0) {
        for(int n=1;n<=9;n++) {
            int b = getBox(y,x);
            if(!row[y][n] && !col[x][n] && !box[b][n]) {
                sudoku[y][x] = n;
                row[y][n] = col[x][n] = box[getBox(y,x)][n] = true;
                
                solve(ny, nx);
                if(!isFin) {
                    sudoku[y][x] = 0;
                    row[y][n] = col[x][n] = box[getBox(y,x)][n] = false;
                }
            }
        } 
    } else {
            solve(ny, nx);
    }
    
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            cin >> sudoku[i][j];
            int val = sudoku[i][j];
            if(val!=0) {
                row[i][val] = true;
                col[j][val] = true;
                box[getBox(i,j)][val] = true;
            }
        }
    }
    
    solve(0,0);
  

    return 0;
}

/*

2580 - 스도쿠 문제

백트래킹과 dp 를 이용해 해결.
처음 입력받을 때 행, 렬, 박스 단위로 dp 에 기록해두고
(0,0) 부터 비어있는 칸을 순회하며 dp 에 없는 n을 넣고 다음 빈칸으로 넘어가보며 진행하다가 막히는 경우 돌아온다.
최종 (8,8) 에 도달해서 넘어갈 경우 출력하고 종료.

dp 를 쓰지 않은 버전에 비해 월등히 빠른 속도를 냈다.
좀 더 공부해볼것.

P.S. 군대에서 매일 같이 하던 스도쿠, 알고리즘으로 풀 수 있을 것 같다고 막연히 생각만 했는데 어느정도 공부하고 백준에서 마주하여 풀게되고나니 기분이 오묘하다.. 시간이 참 빠르구나.

*/