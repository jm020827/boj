#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long l, r, b, k;
    cin >> l >> r >> b >> k;
    
    
    if(l <= b) {
        cout << b * k;
        return 0;
    }
    else {
        if(l%b > 0) {
            l = l + (b - (l % b));  
        }
        cout << l * k;
        return 0;
    }

    return 0;
}

/*

28173 - b 초마다 goose 를 만나고, kill 쿨타임이 끝나있다면 바로 죽일 때, k 마리 geese 를 죽일 수 있는 최소 시간을 구하는 문제

goose 만나는 주기 b가 쿨타임보다 길다면 b * k
goose 만나는 주기보다 최소 쿨타임 l 이 길다면 l 보다 큰 b 의 배수 중 가장 가까운 수 * k

값 범위가 1~10^9 였기에 long long 자료형으로 바꿔야했다.

*/