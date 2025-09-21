#include <iostream>
#include <string>
using namespace std;
int n,k;
int card[10];
int picked[10];
int dp[5000000];
int cnt;

void dfs(int num, int depth) {
    if(depth == k) {
        for(int i=0;i<cnt;i++) {
            if(num == dp[i]) {
                return;
            }
        }
        dp[cnt] = num;
        cnt++;
        // cout << num << "\n";
        return;
    }
    
    for(int i=0;i<n;i++) {
        if(picked[i] == 0) {
            picked[i] = 1;
            string str = to_string(num) + to_string(card[i]);
            dfs(stoi(str), depth+1);
            picked[i] = 0;            
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> k;
    for(int i=0;i<n;i++) {
        cin >> card[i];
    }
    
    
    for(int i=0;i<n;i++) {
        dfs(0, 0);
    }
    
    cout << cnt;

    return 0;
}

/*

5568 - n 개의 카드중 k 개를 골라 배열해서 만들어지는 수의 개수를 구하는 문제

n개 중 k 개를 골라 조합되는 수를 dp 에 넣어두고 백트래킹 dfs로 순회하며 조합해보고 dp 에 없다면 수 증가 및 dp 에 추가, 있다면 뒤로 돌아가며 해결.

*/