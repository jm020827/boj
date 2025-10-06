#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
int n;
pair<int, int> m[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int a, b;
    for(int i=0;i<n;i++) {
        cin >> b >> a;
        m[i] = {a,b};
    }
    
    sort(m, m+n);
    
    int curr = 0;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(m[i].second < curr) continue;
        curr = m[i].first;
        cnt++;
    }
    
    cout << cnt;

    return 0;
}

/*

1931 - 회의를 배치할 수 있는 최대 개수를 구하는 문제.

그리디 알고리즘으로 해결.
끝나는 시간 기준으로 회의 정렬, 같다면 시작 시간 기준 정렬. (sort(). pair 의 자체 기능으로)
그렇게 정렬된 회의 array 를 순회.
만나자마자 그 회의를 채택하는 방식
-> 처음 만나는 회의가 남은 회의 중 가장 빨리 끝나면서 가장 가까이 시작하는 회의.

이때 cnt=1 로 초기화하고 m[i].second >= curr 이면 만나게 해놨더니
첫 회의가 시작과 끝 시간이 동일한 경우에는 첫 회의를 한번 더 세버리는 문제 발생했음.
고쳤더니 해결!

*/