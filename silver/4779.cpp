#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int n;
int len;
char line[531500];

void cantor(int st, int ed, int depth) {
    if(st == ed) {
        return;
    }
    int range = ed - st + 1;
    int tmp = range / 3;
    memset(line + st + tmp, ' ', sizeof(char)*tmp);
    cantor(st, st+ tmp - 1, depth + 1);
    cantor(ed - tmp + 1, ed, depth + 1);
}

void print_line() {
    for(int i=0;i<len;i++) {
        cout << line[i];
    }
}

int main()
{
    ios::sync_with_stdio(0);

    
    while(cin >> n) {
        len = pow(3, n);
        memset(line, '-', sizeof(char)*len);
        cantor(0, len-1, 0);
        
        print_line();
        cout << "\n";
    }
    

    return 0;
}

/*

4779 - 칸토어 집합의 근사를 구하는 문제

- 로 가득찬 3^N 짜리 배열에서 분할 정복으로 가운데 1/3 지점만 지워나가다 길이가 1이 될 때 종료. 그 결과를 출력했다.
depth 는 안써도되거나 depth 활용해야되는데 귀찮아서 걍 냅둠


*/