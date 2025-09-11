#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int h,m,c;
    
    cin >> h >> m;
    cin >> c;
    
    while(m+c >= 60) {
        h += 1;
        c -= 60;
        if(h >= 24) {
            h-=24;
        }
    }
    
    cout << h << " " << m+c;
    

    return 0;
}

/*

2525 - 더해진 시간을 구하는 문제

분단위는 계속 60씩 빼주고 시 단위는 24 넘을 때만 한번 빼줘서 해결. 1000분은 24시간을 넘지 않으니까..

*/