#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int dp[1000005];
    
    cin >> n;
    
    dp[1] = 0;
    
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + 1;
        if(i%2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
        if(i%3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
    }
    
    
    cout<< dp[n];

    return 0;
}

/*

1463 - 정수 N을 3으로 나누거나 2로 나누거나 1을 빼는 세 동작 중 하나를 반복해 가장 짧은 횟수를 구하는 문제

시간 제한이 없다면 BFS 로 세개의 선택을 계속 탐색하는 것도 방법
하지만 시간제한을 줄이기 위해 N의 범위가 1 ~ 10^6 (100만) 밖에 안되므로
dp 로 모든 N 의 경우에 대한 횟수를 구해두는 방식으로 해결.

*/