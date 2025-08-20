#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> cards;
    int num;
    for(int i=0; i< n; i++) {
        cin >> num;
        cards.push_back(num);
    }
    
    sort(cards.begin(), cards.end(), greater<int>());
    
    int max = -1;
    int sum;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++) {
                sum = cards[i] + cards[j] + cards[k];
                if(sum > max && sum <= m) {
                    max = sum;
                }
            }
        }
    }
    
    cout << max;
    
    return 0;
}

/*
2798 - 블랙잭. N 개의 숫자 중 3개의 합이 M 을 넘지 않는 가장 큰 수를 찾는 문제

vector 로 선언한 cards에 숫자를 넣고 내림차순으로 정렬한뒤 브루트포스 (전체 탐색) 으로 찾았다. 

이때 N이 최대 100밖에 되지 않으므로 O(NlogN) 정렬은 시간에 거의 영향 X. 그러므로 정렬을 해둠으로써 최대 O(N^3)의 탐색 시간을 최소화함.

*/