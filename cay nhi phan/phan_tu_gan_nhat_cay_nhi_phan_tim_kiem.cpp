#include<bits/stdc++.h>
using namespace std;

//const int MAX_INF = numeric_limits<int>::max();

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* MIN = NULL;
int MIN1 = 100;

TreeNode* makeTree(vector<string>& s) {
    if (s.empty() || s[0] == "null")
        return nullptr;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(stoi(s[0]));
    q.push(root);
    int i = 1;
    while (!q.empty() && i < s.size()) {
        TreeNode* tmp = q.front();
        q.pop();
        if (s[i] != "null" && tmp->data > stoi(s[i])) {
            tmp->left = new TreeNode(stoi(s[i]));
            q.push(tmp->left);
        }
        i++;
        if (i < s.size() && s[i] != "null" && tmp->data < stoi(s[i])) {
            tmp->right = new TreeNode(stoi(s[i]));
            q.push(tmp->right);
        }
        i++;
    }
    return root;
}

TreeNode* phan_tu_gan_nhat(TreeNode* root, int k) {
    if (root == nullptr)
        return nullptr;
    if (root->data == k)
        return root;
    if (k < root->data) {
        if(abs(MIN1-k) > abs(root->data-k)){
            MIN1=root->data;
        }
        TreeNode* left = phan_tu_gan_nhat(root->left, k);
        return left;
    }
    else if(k > root->data){
        if(abs(MIN1-k) > abs(root->data-k)){
            MIN1=root->data;
        }
        TreeNode* right = phan_tu_gan_nhat(root->right, k);

        return right;
    }
}

int main() {
    string s;
    vector<string> st;
    getline(cin, s);
    string s1;
    stringstream ss(s);
    while (ss >> s1) {
        st.push_back(s1);
    }

    TreeNode* root = makeTree(st);

    int k;
    cin >> k;

    root=phan_tu_gan_nhat(root, k);

    cout << MIN1 << endl;

    return 0;
}
