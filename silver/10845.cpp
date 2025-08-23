#include <iostream>
#include <string>
using namespace std;

int arr[10000];
int cnt = 0;
int head = 0;
int tail = 0;


void push(int n) {
    arr[tail] = n;
    tail += 1;
    cnt += 1;
}

void pop() {
    if(cnt == 0) {
        cout << "-1\n";
    }
    else {
        cout << arr[head] << "\n";
        head += 1;
        cnt -= 1;
    }
}

void size() {
    cout << cnt << "\n";
}

void empty() {
    if(cnt == 0) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
    }
}

void front() {
    if(cnt > 0) {
        cout << arr[head] << "\n";
    }
    else {
        cout << "-1\n";
    }
}

void back() {
    if(cnt > 0) {
        cout << arr[tail-1] << "\n";
    }
    else {
        cout << "-1\n";
    }
}

int main()
{
    int n;
    cin >> n;
    
    
    string cmd;
    int num;
    for(int i=0;i<n;i++) {
        cin >> cmd;
        if(cmd == "push") {
            cin >> num;
            push(num);
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
        else if(cmd == "front") {
            front();
        }
        else if(cmd == "back") {
            back();
        }
    }
    

    return 0;
}


/*
10845 - queue 를 구현하는 문제

최대 1만번의 명령을 받기 때문에 1만개 이상의 push 는 불가하므로
1만짜리 int array 를 선언해서 push 시 tail을, pop 시 head를 증가시키며 queue 를 제어하도록 하여 해결함

*/