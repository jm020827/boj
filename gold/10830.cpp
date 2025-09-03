#include <iostream>
#include <cstring>
using namespace std;

int n;
long long b;
long long mat[5][5];

void matrix_power(long long matrix[5][5], long long result[5][5]) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            result[i][j] = 0;
            for(int k=0;k<n;k++) {
                result[i][j] += matrix[i][k] * matrix[k][j];
            }
            result[i][j] %= 1000;
        }
    }
}

void matrix_multiplication(long long matrix1[5][5], long long matrix2[5][5], long long result[5][5]) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            result[i][j] = 0;
            for(int k=0;k<n;k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] %= 1000;
        }
    }
}

void split_mul(long long tmpB, long long matrix[5][5], long long result[5][5]) {
    if(tmpB == 1) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                result[i][j] = matrix[i][j] % 1000;
            }
        }
        return;
    }
    if(tmpB == 2) {
        matrix_power(matrix, result);
        return;
    }
    
    if(tmpB%2 == 0) {
        
        long long new0[5][5];
        split_mul(tmpB/2, matrix, new0);
        
        matrix_power(new0, result);
        return;
    }
    
    else {
        long long new1[5][5];
        split_mul(tmpB/2, matrix, new1);
        
        long long new2[5][5];
        matrix_power(new1, new2);
        
        matrix_multiplication(new2, mat, result);
        
        return;
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> b;
    
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> mat[i][j];
        }
    }
    
    long long result[5][5];
    
    split_mul(b, mat, result);
    
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*

10830 - N*N 행렬의 B 제곱을 구하는 문제

분할정복을 통해 B 를 2로 계속 나누어가며 1제곱 또는 2제곱의 조합으로 행렬곱을 쌓아올려
최대 logB 번의 행렬곱만 진행하면 되므로 1000억제곱도 제한 시간내에 계산 가능

개선점 1 : tmpB가 홀수일 때 split_mul 을 두번 해서 dfs 처럼 진행됐음. 이미 구한 tmpB/2 제곱한 행렬을 제곱하고 1 제곱 더 하여 tmpB 제곱을 구성하도록 변경함.
개선점 2 : 1제곱일때 (tmpB가 1일 때) 그대로 복사해서 1000이 들어있는 행렬은 1000%1000 = 0 으로 변환이 안되었음. 그래서 행렬 복사할 때 matrix[i][j] % 1000 을 추가. 

*/