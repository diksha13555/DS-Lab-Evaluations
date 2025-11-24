#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};

Node* insertNode(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insertNode(root->left, val);
    else if (val > root->data) root->right = insertNode(root->right, val);
    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

bool searchRec(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

bool searchIter(Node* root, int key) {
    while (root) {
        if (root->data == key) return true;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return false;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) return root->right;
        else if (!root->right) return root->left;
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (!root) return 0;
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

bool isBSTUtil(Node* root, int minV, int maxV) {
    if (!root) return true;
    if (root->data <= minV || root->data >= maxV) return false;
    return isBSTUtil(root->left, minV, root->data) && isBSTUtil(root->right, root->data, maxV);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

Node* inorderSuccessor(Node* root, Node* target) {
    Node* succ = NULL;
    while (root) {
        if (target->data < root->data) {
            succ = root;
            root = root->left;
        } else root = root->right;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* target) {
    Node* pred = NULL;
    while (root) {
        if (target->data > root->data) {
            pred = root;
            root = root->right;
        } else root = root->left;
    }
    return pred;
}

void heapSort(vector<int>& arr, bool inc) {
    if (inc) {
        make_heap(arr.begin(), arr.end(), greater<int>());
        for (int i = arr.size() - 1; i >= 0; i--) {
            pop_heap(arr.begin(), arr.begin() + i + 1, greater<int>());
        }
    } else {
        make_heap(arr.begin(), arr.end());
        for (int i = arr.size() - 1; i >= 0; i--) {
            pop_heap(arr.begin(), arr.begin() + i + 1);
        }
    }
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    cout << searchRec(root, 40) << endl;
    cout << searchIter(root, 90) << endl;

    cout << findMax(root)->data << endl;
    cout << findMin(root)->data << endl;

    Node* t = root->left;
    cout << inorderSuccessor(root, t)->data << endl;
    cout << inorderPredecessor(root, t)->data << endl;

    root = deleteNode(root, 20);

    cout << maxDepth(root) << endl;
    cout << minDepth(root) << endl;

    cout << isBST(root) << endl;

    vector<int> arr = {4,1,3,9,7};
    heapSort(arr, true);
    for (int x : arr) cout << x << " ";
    cout << endl;

    priority_queue<int> pq;
    pq.push(10);
    pq.push(5);
    pq.push(20);
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}