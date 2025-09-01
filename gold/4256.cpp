#include <iostream>
#include <algorithm>
using namespace std;

int n;
int pre[1005];
int in[1005];
int post[1005];

struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};


int preNum = 0;

void reconstBT(Node* node, int inIdx, int st, int ed) {
    if(preNum >= n-1) {
        return;
    }
    
    auto childIt = find(in + st, in + inIdx, pre[preNum+1]);
    if(childIt != in + inIdx) { // 자식이 부모보다 왼쪽에 있을 때
        preNum++;
        Node* leftChild = new Node(pre[preNum]);
        node->left = leftChild;
        reconstBT(leftChild, childIt - in, st, inIdx-1);
    }
    
    childIt = find(in + inIdx+1, in + ed + 1, pre[preNum+1]);
    if(childIt != in + ed + 1) { // 자식이 부모보다 오른쪽에 있을 때
        preNum++;
        Node* rightChild = new Node(pre[preNum]);
        node->right = rightChild;
        reconstBT(rightChild, childIt - in, inIdx+1, ed);
    }
}

void postOrder(Node* node) {
    if(node->left != nullptr) {
        postOrder(node->left);
    }
    if(node->right != nullptr) {
        postOrder(node->right);
    }
    cout << node->value << " ";
}

/* 
PS 문제에서는 OS가 자동으로 메모리를 정리해주므로안해도 되지만 
실제 연구/프로젝트에서 실제 트리를 만들어야하는 거라면 delete 해줘야한다. 
*/
void deleteTree(Node* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for(int i=0;i<T;i++) {
        cin >> n;
        for(int j=0;j<n;j++) {
            cin >> pre[j];
        }
        for(int j=0;j<n;j++) {
            cin >> in[j];
        }
        
        Node* root = new Node(pre[0]);
        auto it = find(in + 0, in + n, root->value);
        
        reconstBT(root, it - in, 0, n-1);
        
        postOrder(root);
        
        cout << "\n";
        
        // deleteTree(root);
        preNum = 0;
    }
    
    return 0;
}

/*

4256 - 이진 트리의 전위 순회, 중위 순회한 결과를 받아서 후위 순회를 출력하는 문제

전위 순회와 중위 순회 결과를 바탕으로 트리를 복원해내 후위 순회로 출력하였다.
1. 전위 순회 배열에서 순서대로 한칸씩 이동.
2. 다음 노드가 중위 순회 배열에서 어디에 있는지 확인.
3. 왼쪽 범위 내에 있다면 node->left 에 연결하고 왼쪽 노드로 진입
4. 오른쪽 범위 내에 있다면 node->right 에 연결하고 오른쪽 노드로 진입
5. 범위 밖에 있다면 다음 것이 child Node 가 아니면서 자신이 leafNode 이므로 return.
6. 이것을 재귀로 반복해서 트리를 재구성
7. 재구성된 트리를 후위순회하며 출력

*/