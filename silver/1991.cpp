#include <iostream>
using namespace std;

int n;
struct Node {
    char value;
    Node* left;
    Node* right;
    Node() : value(0), left(nullptr), right(nullptr) {}
};
Node tree[26];

void preorder(Node* node) {
    cout << node->value;
    if(node->left != nullptr) {
        preorder(node->left);
    }
    if(node->right != nullptr) {
        preorder(node->right);
    }
    return;
}

void inorder(Node* node) {
    if(node->left != nullptr) {
        inorder(node->left);
    }
    cout << node->value;
    if(node->right != nullptr) {
        inorder(node->right);
    }
    return;
}

void postorder(Node* node) {
    if(node->left != nullptr) {
        postorder(node->left);
    }
    if(node->right != nullptr) {
        postorder(node->right);
    }
    cout << node->value;
    return;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    char node, left, right;
    for(int i=0;i<n;i++) {
        cin >> node >> left >> right;
        if(tree[node-65].value == 0) {
            tree[node-65].value = node;
        }
        if(left != '.') {
            tree[left-65].value = left;
            tree[node-65].left = &tree[left-65];
        }
        if(right != '.') {
            tree[right-65].value = right;
            tree[node-65].right = &tree[right-65];
        }
    }
    
    // for(int i=0;i<n;i++) {
    //     cout << "tree[" << char(i+65) << "]\n|-value : " << tree[i].value << "\n";
    //     if(tree[i].left != nullptr) {
    //         cout << "|-left : " << tree[i].left->value << "\n";
    //     }
    //     if(tree[i].right != nullptr) {
    //         cout << "|-left : " << tree[i].right->value << "\n";
    //     }
    // }
    
    preorder(&tree[0]);
    cout << "\n";
    inorder(&tree[0]);
    cout << "\n";
    postorder(&tree[0]);

    return 0;
}


/*

1991 - 트리의 선위순회, 중위순회, 후위순회하는 결과를 각각 출력하는 문제

preorder, inorder, postorder는 최근에 pre, in 으로 트리를 재구성해 postorder로 출력하는 문제를 풀어봤기에 금방 풀었다.
문제는 입력을 바탕으로 트리를 구성하는 거였는데 자세히 입력을 받아 편하긴 했지만 귀찮았다.
node 배열에서 각 노드의 value 가 0 일때 빈 노드로 보고 
매 입력 줄마다 채우고 왼쪽, 오른쪽 노드를 지정하면서 트리를 구성하고
선위 중위 후위 순회의 결과를 각각 출력했다. 

*/