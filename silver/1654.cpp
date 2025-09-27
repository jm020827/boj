#include <iostream>
#include <algorithm>
using namespace std;
int k, n;
int x[10005];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for(int i=0;i<k;i++) {
        cin >> x[i];
    }
    
    sort(x, x+k);
    
    long st = 1;
    long ed = x[k-1];
    
    long ans = 1;
    
    while(st <= ed) {
        long mid = (st + ed) / 2;
        int cnt = 0;
        for(int i=0;i<k;i++) {
            cnt += (x[i] / mid);
        }
        if(cnt >= n) {
            ans = mid;
            st = mid + 1;
        }
        else {
            ed = mid - 1;
        }
    }
    
    cout << ans;
    

    return 0;
}

/*

1654 - K 개의 랜선을 쪼개 N개의 랜선을 구하는 문제.

가장 긴 랜선을 최대길이, 1을 최소길이로 잡고 이분탐색하듯이 반으로 쪼개가며 탐색했다.
절반값 mid로 각 랜선을 나눠 나오는 랜선의 개수를 비교해 N보다 작으면 더 작은 절반 범위를, 크거나 같으면 더 큰 절반 범위로 쪼개가며 구했다.
(매개변수탐색)  

*/