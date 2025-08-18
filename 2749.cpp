#include <iostream>
using namespace std;

int main()
{
    int result = 0;
    long long n = 0;
    cin >> n;
    
    long long dp[3];
    dp[0] = 0;
    dp[1] = 1;
    
    n = n % 1500000;
    
    for(int i=2;i<=n;i++){
        dp[i%3] = dp[(i-2)%3]%(1000000) + dp[(i-1)%3]%(1000000);
    }
    
    result = dp[n%3]%1000000;
    
    cout<< result << endl;

    return 0;
}
/*
2749 - 피보나치 수열 3

피사노 주기를 활용하여 해결.

* 피사노 주기 : 
피보나치 수열의 값을 M 으로 나눈 나머지로 나열했을 때 반드시 P 의 주기를 가짐. 
fib[N] % M == fib[N % P] % M
이때 M 이 10^k (k > 2) 이라면 P = 15 * 10^(k-1)  

*/