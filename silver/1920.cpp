#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[100005];

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
            return 1;
        }
    }
    return 0;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    int num;
    for(int i=0;i<n;i++) {
        cin >> num;
        arr[i] = num;
    }
    
    sort(arr, arr+n);
    
    
    cin >> m;
    for(int j=0;j<m;j++) {
        cin >> num;
        cout << binary_search(num) << "\n";
    }
    

    return 0;
}


/*

1920 - n 개의 정수 중에 m개의 정수가 있는지 찾는 문제.

n 개의 정수가 담긴 배열을 sort 하고 m 개의 정수 각각에 대해 이분 탐색을 실시하여 각각을 O(logN) 이내로 찾아냈다.

*/