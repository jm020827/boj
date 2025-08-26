#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int n, budget;
int arr[10005];

int binary_search(int target) {
    int start = 0;
    int end = n-1;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(arr[mid] < target) {
            start = mid + 1;
        }
        else if(arr[mid] > target) {
            end = mid - 1;
        }
        else {
            return mid;
        }
    }
    return end;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    int sum = 0;
    int max = 0;
    int num;
    
    for(int i=0;i<n;i++) {
        cin >> num;
        arr[i] = num;
        sum += num;
        if(max < num) {
            max = num;
        }
    }
    cin >> budget;
    
    
    if(sum <= budget) {
        cout << max;
    }
    else {
        sort(arr, arr+n);
        
        int params = (arr[0]+arr[n-1])/2;
        int prevParams = params;
        
        bool isSmall = false;
        int cnt = 0;
        while(true) {
            
            int idx = binary_search(params);
            
            int sumArr = accumulate(arr, arr+idx+1, 0);
            int sumLimit = (n-1-idx) * params;
            
            if(sumArr + sumLimit == budget) {
                cout << params;
                break;
            }
            
            else if(sumArr + sumLimit > budget) {
                if(cnt == 0) {
                    isSmall = false;
                    cnt++;
                    continue;
                }
                if(isSmall) {
                    cout << prevParams;
                    break;
                }
                else {
                    prevParams = params;
                    params -= 1;
                }
            }
            
            else {
                if(cnt == 0) {
                    isSmall = true;
                    cnt ++;
                    continue;
                }
                if(!isSmall) {
                    cout << params;
                    break;
                }
                else {
                    prevParams = params;
                    params += 1;
                }
            }
        }
        
    }

    return 0;
}


/*

2512 - 예산 배정 문제. 요청받은 예산 중 상한금액을 초과한 경우 상한금액만큼만 지급하여 총합이 총 예산보다 작은 가장 큰 수를 찾는 문제

요청액 총합이 전체 예산보다 작은 경우, 그냥 최대값 출력
그렇지 않은 경우, 배열을 정렬한 뒤 가장 작은 값과 큰 값의 평균을 매개변수로 두고, 이분 탐색을 통해 그 값이 들어갈 인덱스 위치를 찾았다.
해당 인덱스 위치를 기준으로 이하의 요청액들은 전부 더하고, 초과하는 요청액들은 전부 매개변수 값만큼으로 계산해 더한다.
이 총합이 총 예산을 넘지 않는 가장 큰 수가 될때까지 반복한다.

N 이 최대 1만 이므로
sort - O(NlogN) : 최대 13만
accumulate - O(N) : 최대 1만
N 이 최대 1만이므로 이분탐색은 O(logN) -> 한번 탐색할 때 최대 13번. 요청액의 최댓값은 10만이므로, 매개변수는 평균인 5만에서 시작하는 것이 최대, 반복은 최대 5만번.
곱하면 아무리 많아도 65만회 반복

-> 최대 80여만회 계산이므로 충분히 1초이내에 계산 완료 가능!


*/