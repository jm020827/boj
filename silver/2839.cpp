#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
    int five_bag = 0;
    int three_bag = 0;
    
    int tmp = n;
    
    int min = 5005;
    while(three_bag <= n/3) {
        min = 5005;
        tmp = n;
        five_bag = 0;
        
        for(int i=0;i<three_bag;i++) {
            tmp -= 3;
        }
        
        while(tmp > 0) {
            tmp -= 5;
            five_bag++;
        }
        
        if(tmp == 0) {
            if(min > five_bag + three_bag) {
                min = five_bag + three_bag;
                n = tmp;
                break;
            }
        }
        
        three_bag++;
    }
    
    if(n != 0) {
        cout << -1;
    }
    else {
        cout << five_bag + three_bag;
    }

    return 0;
}

/*

2839 - N kg 의 설탕을 5kg과 3kg 짜리 가방에 나눠 담는 최소 개수를 구하는 문제

그리디하게 전부 5kg 가방에 담는 것부터 시작해 3kg 가방을 하나씩 늘려가며 해결.


*/