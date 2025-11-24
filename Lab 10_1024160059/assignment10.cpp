#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool hasDuplicate(vector<int> nums) {
    unordered_set<int> s;
    for (int n : nums) {
        if (s.count(n)) return true;
        s.insert(n);
    }
    return false;
}

void commonElements(vector<int> a, vector<int> b) {
    unordered_set<int> s(a.begin(), a.end());
    for (int x : b) if (s.count(x)) cout << x << " ";
    cout << endl;
}

void frequencyCount(vector<int> nums) {
    unordered_map<int,int> m;
    for (int n : nums) m[n]++;
    for (auto p : m) cout << p.first << " -> " << p.second << endl;
}

int firstNonRepeating(vector<int> nums) {
    unordered_map<int,int> m;
    for (int n : nums) m[n]++;
    for (int n : nums) if (m[n] == 1) return n;
    return -1;
}

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

bool hasLoop(Node* head) {
    unordered_set<Node*> s;
    while (head) {
        if (s.count(head)) return true;
        s.insert(head);
        head = head->next;
    }
    return false;
}

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

bool findDuplicate(TreeNode* root, unordered_set<int>& s) {
    if (!root) return false;
    if (s.count(root->val)) return true;
    s.insert(root->val);
    return findDuplicate(root->left, s) || findDuplicate(root->right, s);
}

int main() {
    vector<int> nums1 = {1,2,3,1};
    cout << hasDuplicate(nums1) << endl;

    vector<int> A = {1,2,3,4}, B = {3,4,5,6};
    commonElements(A, B);

    vector<int> nums2 = {2,3,2,4,3,2};
    frequencyCount(nums2);

    vector<int> nums3 = {4,5,1,2,0,4};
    cout << firstNonRepeating(nums3) << endl;

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    n1->next = n2;
    n2->next = n3;
    n3->next = n2;
    cout << hasLoop(n1) << endl;

    TreeNode* r = new TreeNode(4);
    r->left = new TreeNode(2);
    r->right = new TreeNode(4);
    unordered_set<int> s;
    cout << findDuplicate(r, s) << endl;

    return 0;
}