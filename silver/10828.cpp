#include <iostream>
#include <cstring>
using namespace std;
int stack[10000];
int tp;

void push(int v) {
    stack[tp++] = v;
}

void pop() {
    if(tp == 0) {
        cout << -1 << "\n";
    }
    else {
        cout << stack[--tp] << "\n";    
    }
}

void size() {
    cout << tp << "\n";
}

void empty() {
    if(tp == 0) {
        cout << 1 << "\n";
    }
    else {
        cout << 0 << "\n";
    }
}

void top() {
    if(tp == 0) {
        cout << -1 << "\n";
    }
    else {
        cout << stack[tp-1] << "\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string cmd;
    int value;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> cmd;
        if(cmd == "push") {
            cin >> value;
            push(value);
        }
        else if(cmd == "pop") {
            pop();
        }
        else if(cmd == "size") {
            size();
        }
        else if(cmd == "empty") {
            empty();
        }
        else if(cmd == "top") {
            top();
        }
    }
    

    return 0;
}


/*

10828 - stack 구현 문제

stack array 의 tp 를 옮겨가며 스택을 구현.

*/