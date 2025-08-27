#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int card[500005];
int num[500005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> card[i];
    }
    sort(card, card+n);
    
    cin >> m;
    
    int target;
    for(int i=0;i<m;i++) {
        cin >> target;
        num[i] = upper_bound(card, card+n, target) - lower_bound(card,card+n, target);
    }
    
    for(int i=0;i<m;i++) {
        cout << num[i] << " ";
    }
    
    
    return 0;
}

/*

10816 - N 개의 정수 배열에서 M 개의 정수가 각각 몇개 들어있는지를 구하는 문제.

이분 탐색으로 N개의 정수 배열을 탐색하여 최대 길이가 50만인 배열을 log_2(500000) = 19회 내외로 전부 탐색 가능. 
그리고 해당 정수가 배열에서 얼마나 있는지는 첫번째로 발견한 목표 정수로부터 양쪽으로 O(N) 탐색을 진행. 

하는 방식은 역시나 시간초과라서 target + 0.5f 를 찾았을 때 나오는 위치와 
target - 0.5f 를 찾았을 때 나오는 위치 사이의 거리로 계산 방식을 바꿨으나 이건 좀 더 정답이다가 결국은 시간 초과가 남.
(충분히 O((n+m)logn) 안으로 풀 수 있을 것 같은데.. 자세한건 나중에 공부해보자.)

그래서 algorithm 라이브러리에 있는 STL인 upper_bound, lower_bound 라는 함수를 써서
배열 내 target의 위치를 찾아내 해결했다. 
이분 탐색을 활용해 O(logn) 으로 찾는 메소드라고 하는데
내가 만든 함수도 O(logn)인데 뭐가 다른지 찾아봐야겠다. 

*/