#include <iostream>
using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    cout<< a+b+c;

    return 0;
}

/*
11382 - 10^12 정도의 큰 수의 합을 구하는 문제

10^12 는 2^40에 근사하므로 2^32-1 까지 커버 가능한 int 자료형으로는 구할 수 없다. 
64비트 정수까지 제공하는 long long 자료형으로 덧셈하면 된다.
*/