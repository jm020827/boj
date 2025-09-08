#include <iostream>
#include <algorithm>
using namespace std;
int n;
int pre[100005];
int in[100005];
int post[100005];


struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

int postIdx = 0;

void reconstTree(Node* node, int inIdx, int st, int ed) {

    if(postIdx == 0) {
        return;
    }
    
    auto it = find(in+inIdx+1, in+ed+1, post[postIdx-1]);
    if(it != in+ed+1) {
        postIdx--;
        Node* right = new Node(post[postIdx]);
        node->right = right;
        reconstTree(right, it - in,  inIdx+1, ed);
    }
    
    it = find(in+ st, in+inIdx, post[postIdx-1]);
    if(it != in+inIdx) {
        postIdx--;
        Node* left = new Node(post[postIdx]);
        node->left = left;
        reconstTree(left, it - in, st, inIdx-1);
    }

    
}

int preIdx = 0;
void preOrder(Node* node) {
    cout << node->value << " ";
    if(node->left != nullptr) {
        preOrder(node->left);
    }
    if(node->right != nullptr) {
        preOrder(node->right);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++) {
        cin >> in[i];
    }
    for(int i=0;i<n;i++) {
        cin >> post[i];
    }
    
    
    postIdx = n-1;
    Node* root = new Node(post[n-1]);
    auto it = find(in, in+n, post[n-1]);
    
    reconstTree(root, it - in, 0, n-1);
    
    preOrder(root);

    return 0;
}

/*

2263 - inOrder, postOrder 결과를 보고 preOrder 를 출력하는 문제

4256 번에서 주어진 순회와 출력해야하는 순회를 바꾸기만 한 문제. (preOrder <-> postOrder)
postOrder 를 거꾸로 돌아가면 우측 선행의 preOrder과 같아지므로 postIdx 를 하나씩 줄여가며,
inOrder 에서 위치와 커버 범위를 찾으며 재귀적으로 reconstTree 를 right -> left 순으로 수행한다.

그렇게 재구성된 tree를 preorder로 순회하며 출력하면 해결.

*/