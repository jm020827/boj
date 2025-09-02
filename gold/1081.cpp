#include <iostream>
#include <cmath>
using namespace std;


long long getZeroToNum(int n) {
    long long sum = 0;
    for(int i=0;i<=n;i++) {
        sum += i;
    }
    
    return sum;
}

long long getTotal(int n, int degree) {
    if(degree == 0) { // 일의 자리수
        return getZeroToNum(n);
    }
    long long ten = pow(10, degree);
    
    int quot = n/ten;
    int rmd = n%ten;
    
    long long total = (quot * (rmd+1)) + (getZeroToNum(quot-1) * ten) + (45 * (ten/10) * degree * quot);
    
    return total + getTotal(rmd, degree-1);
}

int main()
{
    int L, U;
    cin >> L >> U;

    long long tmp = 0;
    
    int dL = 0;
    int dU = 0;
    
    if(L <= 1) {
        dL = 1;
    }
    else {
        tmp = L-1;
        while(tmp > 0) {
            dL++;
            tmp /= 10;
        }
    }
    if(U == 0) {
        dU = 1;
    }
    else { 
        tmp = U;
        while(tmp > 0) {
            dU++;
            tmp /= 10;
        }
    }
    
    long long totalU =  getTotal(U, dU-1);
    long long totalL = getTotal(L-1, dL - 1);
    
    cout << totalU - totalL;


    return 0;
}

/*

1081 - L 이상 U 이하인 모든 정수들의 각 자릿수의 합을 구하는 문제

L,U의 범위가 0~20억이므로 단순히 이중 for문 반복으로는 O(N^2) 이 나와버리므로 2초의 시간제한을 넘겨버린다.

그래서 분명 규칙이 있을 것이라 생각하고 각 자리수의 합이 어떻게 분리돼서 더해지는지, 몇번 등장하는지 등을 머리 굴려서 규칙을 찾아봤다.
역시나 점화식이 나오더라.

10^n의 자리수까지 있는 정수 N에 대해 10^d 의 자리의 수가 q, 그 아래 나머지가 rmd라고 했을 때, 
total = (k * (rmd+1)) + ((0~q-1) * 10^d) + (45 * 10^(d-1) * d * k);
이게 10^d-1 자리까지 0으로 채워졌을 때 그 아래에 나올 수 있는 모든 자릿수들의 합이다.
즉 이걸 10^n의 자리부터 1의 자리까지 반복할 경우 0~N 까지 자릿수의 총합이 나온다.
(예 : 5678 -> 0~5000 + 0~678 + 0~78 + 0~8)

두 정수 사이의 자릿수 총합은 두 정수 각각의 자릿수 총합의 차와 같으므로 L-1, U 에 대해 각각 구한 뒤 차를 구하면 답을 구할 수 있다.

*/