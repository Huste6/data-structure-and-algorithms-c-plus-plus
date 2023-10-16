#include <bits/stdc++.h>
using namespace std;

#define INF 10000

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode* makeTree(vector<string>& node) {
    if (node.empty() || node[0] == "null") {
        return nullptr;
    }
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(stoi(node[0]));
    q.push(root);
    int i = 1;
    while (!q.empty() && i < node.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (node[i] != "null") {
            curr->left = new TreeNode(stoi(node[i]));
            q.push(curr->left);
        }
        i++;
        if (i < node.size() && node[i] != "null") {
            curr->right = new TreeNode(stoi(node[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
    while (!st.empty()) {
        auto [node, depth] = st.top();
        st.pop();
        if (node->right != nullptr) {
            st.push({node->right, depth + 1});
        }
        if (node->left != nullptr) {
            st.push({node->left, depth + 1});
        }
        if (node->right == nullptr && node->left == nullptr) {
            return depth;
        }
    }
    return 0;
}

int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string s1;
    vector<string> node;
    while (ss >> s1) {
        node.push_back(s1);
    }
    TreeNode* root = makeTree(node);



    return 0;
}
