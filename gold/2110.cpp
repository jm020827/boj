#include <iostream>
#include <algorithm>
using namespace std;
int n, c;
int x[200005];

bool check(int dist) {
    int cnt = 1;
    int i = 0;
    while(i < n-1) {
        int j = i + 1;
        for(j=i+1;j<n;j++) {
            // cout << "  x[" << j << "](" << x[j] <<") - x[" << i << "](" << x[i] <<")";
            int d = x[j] - x[i];
            if(d >= dist) {
                // cout << " >= dist (" << dist << ")";
                cnt++;
                // cout << "\n";
                break;
            }
            // cout << "\n";
        }
        i = j;
        if(cnt >= c) {
            break;
        }
    }
    
    if(cnt >= c) {
        // cout << "dist (" << dist << ") is True\n"; 
        return true;
    }
    else {
        // cout << "dist (" << dist << ") is False\n"; 
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for(int i=0;i<n;i++) {
        cin >> x[i];
    }
    
    sort(x, x+n);
    
    int dist = 1;
    int st = 0;
    int ed = x[n-1];
    int ans = 1;
    
    while(st <= ed){
        dist = (st + ed) / 2;
        // cout << "dist : " << dist << " | start : " << st << " | end : " << ed << "\n";
        if(check(dist)) {
            ans = dist;
            st = dist + 1;
        }
        else {
            ed = dist - 1;
        }
    }
    
    cout << ans;

    return 0;
}

/*

2110 - 공유기 설치 문제. N 개의 집에 C개의 공유기를 최대한 멀리 떨어뜨려 설치할 때, 제일 인접한 공유기의 최대거리를 구하는 문제

dist 를 x_i의 범위인 0부터 입력된 x의 최댓값 사이에서 절반씩 쪼개가며
만약 이 dist 이상의 값들로 공유기를 c개 이상 설치할 수 있다면 더 큰 절반의 범위에서 dist를 다시 확인하고, 안된다면 더 작은 절반 범위로 쪼갠다.
이를 반복하여 check(dist) 를 만족하는 dist 의 최댓값을 구하여 해결.

(이분탐색 & 매개변수탐색)

TODO - 왜 바로 i -> j 로 넘어가며 거리를 계산하는게 먹히는지 잘 모르겠다. 
i->j 가 당장은 통과하지만 j+1 로 넘어가는게 뒤에서 더 크게 차이를 만들 수도 있는거 아닌가..?
헷갈리지만 아무튼 통과~;;

*/