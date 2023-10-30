//5 3 6 7 11 4 15 8 null null 0 null null null 2 null null 1
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
int distMin(TreeNode *root)
{
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    return 1;
    if(root->left==NULL)
    return distMin(root->right)+1;
    if(root->right==NULL)
    return distMin(root->left)+1;
    return min(distMin(root->left),distMin(root->right))+1;
}
//cac nut phai nhat cua cay nhi phan dung bfs

vector<int> rightSideView(TreeNode*root)
{
    //if(root==nullptr) return vector{};
    vector<int> ans;
    queue<TreeNode*> myqueue;
    myqueue.push(root);
    while(!myqueue.empty()){
        int currLength=myqueue.size();
        for(int i=0;i<currLength;i++){
            TreeNode*node=myqueue.front();myqueue.pop();
            if(i==currLength-1){
                ans.push_back(node->val);
            }
            if(node->left!=nullptr){
                myqueue.push(node->left);
            }
            if(node->right!=nullptr){
                myqueue.push(node->right);
            }
        }
    }
    return ans;
}
//gia tri lon nhat tren moi hang
vector<int> LargestValue(TreeNode*root)
{
    vector<int> ans;
    queue<TreeNode*> myqueue;
    myqueue.push(root);
    while(!myqueue.empty()){
        int j=myqueue.size();
        int max_row=INT_MIN;
        for(int i=0;i<j;i++){
            TreeNode*node=myqueue.front();myqueue.pop();
            max_row=max(max_row,node->val);
            if(node->left!=nullptr){
                myqueue.push(node->left);
            }
            if(node->right!=nullptr){
                myqueue.push(node->right);
            }
        }
        ans.push_back(max_row);
    }
    return ans;
}
//tong gia tri cac nut la co do sau lon nhat
int height(TreeNode*node)
{
    if(node==NULL) return 0;
    else{
        return max(height(node->left),height(node->right))+1;
    }
}
int sum_of_Level(TreeNode*node,int level)
{
    int sum=0;
    if(node==nullptr) return 0;
    if(level==1){
        sum=node->val;
    }else if(level>1){
        sum+=sum_of_Level(node->left,level-1);
        sum+=sum_of_Level(node->right,level-1);
    }
    return sum;
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
    cout<<distMin(root)<<endl;
    vector<int> ans=rightSideView(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> ans1=LargestValue(root);
    for(auto it:ans1){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<sum_of_Level(root,height(root))<<endl;
    return 0;
}
