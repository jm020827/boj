#include <iostream>
using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int a;
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(a < x) {
            cout << a << " ";
        }
    }
    return 0;
    
}

/*
10871 -정수 N개로 이루어진 수열 A와 정수 X가 주어진다. 이때, A에서 X보다 작은 수를 모두 출력하는 프로그램

입력을 받을 때마다 판단 후 그대로 출력하여 해결

*/