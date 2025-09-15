#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t,n;
    int dp[11];
    
    cin >> t;
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4;i<11;i++) {
        // dp[i] = dp[i-1]*2 - dp[i-4];
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    
    for(int i=0;i<t;i++) {
        cin >> n;
        cout << dp[n] << "\n";
    }
    
    return 0;
}

/*

9095 - 자연수를 1,2,3의 합으로 표현하는 방법의 수를 구하는 문제 

dp[n] = dp[n-1] + dp[n-2] + dp[n-3] 의 점화식을 활용해 dp 로 풀면된다.


*/