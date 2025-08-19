#include <iostream>
#include <vector>
#include <utility>
using namespace std;

/* 1~n 까지의 XOR 에서 n % 4 값에 따라 결과가 반복됨.
 n % 4 == 0 -> n
 n % 4 == 1 -> 1
 n % 4 == 2 -> n+1
 n % 4 == 3 -> 0
*/
long long XOR(long long n) {
    switch(n % 4) {
        case 0 :
            return n;
        case 1:
            return 1;
        case 2 :
            return n+1;
        case 3 :
            return 0;
        default :
            return n;
    }
}


int main()
{
    int T;   
    cin >> T;
    
    long long S, F;
    vector<pair<long long, long long>> v;
    
    for(int i = 0; i < T; i++) {
        cin >> S >> F;
        pair<long long, long long> newPair = {S, F};
        v.push_back(newPair);
    }


    for(pair<long long, long long> p : v) {
        S = p.first;
        F = p.second;
        long long result = XOR(S-1) ^ XOR(F);
        cout << result << endl;
    }
    // 1~(S-1) 까지의 XOR 결과와 1~F 까지의 XOR 결과를 XOR 하면 S~F까지의 XOR 결과가 나온다. 

    return 0;
}


/*
10464 - XOR

XOR 의 성질과 1~N 까지의 XOR 결과의 규칙성을 활용해 해결

* XOR 의 성질 : 결합법칙, 역원성(같은 값끼리 XOR = 0), 항등원(0과 XOR 시 결과로 같은 값)
* XOR 결과의 규칙성 : 4로 나눈 나머지에 따라 1~N 까지의 XOR 결과가 결정됨

*/