#include <iostream>
using namespace std;

/*
 
https://blog.encrypted.gg/922

N 이하의 자연수 중에서 3의 배수이거나 5의 배수인 수를
모두 합한 값을 반환하는 함수 func1(int N)을 작성하라.
N은 5만 이하의 자연수이다.

func1(16) = 60,
func1(34567) = 278812814,
func1(27639) = 178254968

*/

int main()
{
    long long n;   
    cin >> n;
    long long total = 0;
    
    
    cout << (((5*(n/5)*((n/5)+1)))/2) + (((3*(n/3)*((n/3)+1)))/2) - (((15*(n/15)*((n/15)+1)))/2) << endl;
    // O(1) 방식
    
    for(int i =0; i<= n; i++) {
        if(i%3 ==0 || i%5 == 0) {
            total += i;
        }
    }
    // O(n) 방식
    
    cout << total << endl;
    return 0;
}

