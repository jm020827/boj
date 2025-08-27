#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int N, M;
int arr[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr+N);
    
    int a, b = arr[0];
    int j = 0;
    int min = 2000000000;
    
    
    for(int i=0;i<N;i++) {
        int a = arr[i];
        if(a-b < M) {
            continue;
        }
        else if(a-b > M) {
            if(min > a-b) {
                min = a-b;
            }
            while(a-b > M) {
                j++;
                b = arr[j];
                if(a-b < M) {
                    break;
                }
                else if(a-b > M) {
                    if(min > a-b) {
                        min = a-b;
                    }
                    continue;
                }
                else {
                    min = a-b;
                    cout << min;
                    return 0;
                }
            }
        }
        else {
            min = a-b;
            cout << min;
            return 0;
        }
    }
    
    cout << min;
    

    return 0;
}

/*

2230 - N 개의 정수 중 그 차가 M 이상이면서 가장 작은 값을 구하는 문제

더블포인터로 (이렇게하는건지는 정확히 모르겠지만) 
a가 N 순환을 도는 동안 가장 작은 값으로 시작하는 b와의 차이가 M 보다 큰 경우, 
b도 한칸 씩 키워가며 각 경우의 최소 차를 구한다.

*/