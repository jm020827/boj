#include <iostream>
using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    if(c-b <= 0) {
        cout << -1;
    }
    else {
        cout << (a/(c-b)) + 1;
    }

    return 0;
}

/*
1712 - 손익분기점 계산. 고정비용 A, 가변비용 B, 판매가격 C 일 때의 손익분기점을 구하는 문제

N*C - (A + N*B) > 0 이면 되므로

N > A/(C-B).

N은 양의 정수이므로 C-B 가 0보다 작거나 같은 경우만 예외처리하고, 그외에는 나눈 몫에 1을 더해주면 손익분기점이 나온다. (몫은 항상 내림되므로)

*/