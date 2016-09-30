#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <math.h>
using namespace std;

struct Node {
    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
    int val;
    Node* left;
    Node* right;
};

void preOrder(Node* head) {
    if (head == nullptr) {
        return;
    }
    cout << head->val << " ";
    preOrder(head->left);
    preOrder(head->right);
}

void inOrder(Node* head) {
    if (head == nullptr) {
        return;
    }
    inOrder(head->left);
    cout << head->val << " ";
    inOrder(head->right);
}

void postOrder(Node* head) {
    if (head == nullptr) {
        return;
    }
    postOrder(head->left);
    postOrder(head->right);
    cout << head->val << " ";
}

void iterPreOrder(Node* head) {
    if (head == nullptr) {
        return;
    }
    stack<Node*> s;
    Node* curr = head;
    while (curr != nullptr || !s.empty()) {
        if (curr != nullptr) {
            s.push(curr);
            cout << curr->val << " ";
            curr = curr->left;
        }
        else {
            curr = s.top();
            s.pop();
            curr = curr->right;
        }
    }
}

void iterInOrder(Node* head) {
    if (head == nullptr) {
        return;
    }
    stack<Node*> s;
    Node* curr = head;
    while (curr != nullptr || !s.empty()) {
        if (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        else {
            curr = s.top();
            s.pop();
            cout << curr->val << " ";
            curr = curr->right;
        }
    }
}

int main() {
    Node n(11);
    Node* put = &n;
    put->left = new Node(6);
    put->right = new Node(15);
    put->left->left = new Node(3);
    put->left->left->right = new Node(5);
    put->left->right = new Node(8);
    put->left->right->left = new Node(7);
    put->right = new Node(15);
    put->right->left = new Node(13);
    put->right->right = new Node(18);
    put->right->right->left = new Node(16);
    put->right->right->right = new Node(19);
    cout << "Preorder: ";
    preOrder(put);
    cout << endl;
    
    cout << "In order: ";
    inOrder(put);
    cout << endl;
    
    cout << "Postorder: ";
    postOrder(put);
    cout << endl;
    
    cout << "Preorder: ";
    iterPreOrder(put);
    cout << endl;
    
    cout << "In order: ";
    iterInOrder(put);
    cout << endl;
    
//    cout << "Postorder: ";
//    iterPostOrder(put);
//    cout << endl;
}


