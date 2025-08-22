#include <iostream>
#include <string>
using namespace std;

int S = 0;

void add(int x) {
    if(S != (S | (1 << x))) {
        S |= (1 << x);      
    }
}

void remove(int x) {
    if(S == (S | (1 << x))) {
        S ^= (1 << x);
    }
}

void check(int x) {
    if(S == (S | (1 << x))) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
    }
}

void toggle(int x) {
    if(S == (S | (1 << x))) {
        S ^= (1 << x);
    }
    else if(S != (S | (1 << x))) {
        S |= (1 << x);      
    }
}

void all() {
    S |= ((1 << 21) - 1);
}

void empty() {
    S = 0;
}

void printS() {
    
    int tmp = S;
    for(int j=0;j<20;j++) {
        tmp = tmp/2;
        cout << tmp%2;
    }
    cout << "\n";
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int M;
    cin >> M;
    
    string cmd;
    int x;
    
    for(int i = 0; i< M; i++) {
        cin >> cmd;
        if(cmd == "add") {
            cin >> x;
            add(x);
        }
        else if(cmd == "remove") {
            cin >> x;
            remove(x);
        }
        else if(cmd == "check") {
            cin >> x;
            check(x);
        }
        else if(cmd == "toggle") {
            cin >> x;
            toggle(x);
        }
        else if(cmd == "all") {
            all();
        }
        else if(cmd == "empty") {
            empty();
        }
        
    }
    

    return 0;
}

/*

11723 - 입력받는 명령어에 따라 집합을 조작하는 문제

집합을 1비트 state 만 관리하면 되므로 모든 명령어 동작을 비트마스킹으로 해결했다. 

*/