#include <iostream>
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    int arr[100005];
    int num;
    for(int i=0; i<n; i++) {
        cin >> num;
        arr[i] = num;
    }
    
    int j = 0;
    int minLength = 100005;
    int total = 0;
    
    for(int i=0;i<n;i++) {
        total += arr[i];
        if(total >= s) {
            if(minLength > i-j+1) {
                minLength = i-j+1;
            }
            while(i>=j) {
                total -= arr[j];
                j++;
                if(total >= s) {
                    if(minLength > i-j+1) {
                        minLength = i-j+1;
                    }
                    continue;
                }
                else {
                    break;
                }
            }
        }
    }
    
    if(minLength > 100000) {
        cout << 0;
    }
    else {
        cout<< minLength;
    }

    return 0;
}

/*

1806 - 길이가 N인 수열의 연속된 원소들의 합이 S 이상이 되는 것 중 가장 짧은 것의 길이를 구하는 문제

투 포인터로 i 로 진행하면서 j 가 한칸씩, 그 합이 S 이상일 때까지 j를 당기고 최소 길이를 저장해서 출력한다.
이때 처음엔 numeric 라이브러리의 accumulate() 함수를 사용했으나 매 반복마다 O(n) 의 시간이 소요되어 시간초과가 나와서,
반복마다 total을 한번씩 더하거나 빼는 방식으로 바꿔 해결했다.

*/