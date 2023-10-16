#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

void themnodevaocay(TreeNode*& head, int x) {
    if (head == nullptr) {
        TreeNode* tmp = new TreeNode(x);
        head = tmp;
    }
    else {
        if (head->val > x) {
            themnodevaocay(head->left, x);
        }
        else if (head->val < x) {
            themnodevaocay(head->right, x);
        }
    }
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;
    stack<pair<TreeNode*, int>> st;
    st.push({ root, 0 });
    while (!st.empty()) {
        auto [node, curr] = st.top();
        st.pop();
        curr += node->val;
        if (node->left == nullptr && node->right == nullptr) {
            if (curr == targetSum) {
                return true;
            }
        }
        if (node->left != nullptr) {
            st.push({ node->left, curr });
        }
        if (node->right != nullptr) {
            st.push({ node->right, curr });
        }
    }
    return false;
}

int GoodNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    stack<pair<TreeNode*, int>> st;
    st.push({root, INT_MIN});
    int ans = 0;
    while (!st.empty()) {
        auto [node, val] = st.top();
        st.pop();
        if (node->val >= val) {
            ans++;
        }
        if (node->left != nullptr) {
            st.push({node->left, max(node->val, val)});
        }
        if (node->right != nullptr) {
            st.push({node->right, max(node->val, val)});
        }
    }
    return ans;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;
    if (root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right != nullptr) {
        return root;
    }
    if (left != nullptr) return left;
    return right;
}

int main() {
    TreeNode* root = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        themnodevaocay(root, x);
    }
    if (hasPathSum(root, 139)) {
        cout << "Co duong di\n";
    }
    else {
        cout << "Khong co duong di\n";
    }
    cout << GoodNodes(root) << endl;

    TreeNode* p = new TreeNode(37);
    TreeNode* q = new TreeNode(55);
    cout << lowestCommonAncestor(root, p, q)->val << endl;

    return 0;
}
