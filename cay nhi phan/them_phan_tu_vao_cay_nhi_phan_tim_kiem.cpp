#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void them_node_vao_cay(TreeNode*& root, int x) {
    if (root == NULL) {
        TreeNode* newnode = new TreeNode(x);
        root = newnode;
    } else {
        if (root->data > x)
            them_node_vao_cay(root->left, x);
        else if (root->data < x)
            them_node_vao_cay(root->right, x);
    }
}

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
        if (node[i] != "null" && curr->data > stoi(node[i])) {
            curr->left = new TreeNode(stoi(node[i]));
            q.push(curr->left);
        }
        i++;
        if (i < node.size() && node[i] != "null" && curr->data < stoi(node[i])) {
            curr->right = new TreeNode(stoi(node[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int height(TreeNode* root) {
    if (root == NULL)
        return 0;
    else {
        return max(height(root->left), height(root->right)) + 1;
    }
}

vector<string> st;

void duyet_theo_level(TreeNode* root, int level) {
    if (root == NULL) {
        st.push_back("null");
        return;
    }

    if (level == 1) {
        st.push_back(to_string(root->data));
    } else if (level > 1) {
        duyet_theo_level(root->left, level - 1);
        duyet_theo_level(root->right, level - 1);
    }
}

void duyet(TreeNode* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        duyet_theo_level(root, i);
    }
}

int main() {
    vector<string> vt;
    string s;
    getline(cin, s);
    stringstream ss(s);
    string s1;
    while (ss >> s1) {
        vt.push_back(s1);
    }

    TreeNode* root = makeTree(vt);

    int x;
    cin >> x;

    them_node_vao_cay(root, x);

    duyet(root);

    int check = 0;
    for (int i = st.size() - 1; i >= 0; i--) {
        if (st[i] == "null") {
            st.erase(st.begin()+i);
        } else {
            for (int j = 0; j < st.size(); j++) {
                cout << st[j]<<"\n";
            }
            cout<<"\n";
            return 0;
        }
    }

    return 0;
}


