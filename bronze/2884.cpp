#include <iostream>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int h,m;
    cin >> h >> m;
    
    m = m-45;
    if(m < 0) {
        h-=1;
        m+=60;
        if(h < 0) {
            h += 24;
        }
    }
     
    cout<< h << " " << m;

    return 0;
}

/*

2884 - 45분 일찍 알람을 맞추는 문제

45분을 빼주면 된다. 근데 분은 0~60이고 시는 0~23 인것을 감안해서..

*/