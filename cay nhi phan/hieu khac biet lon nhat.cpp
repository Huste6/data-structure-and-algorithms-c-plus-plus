#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode* makeTree(vector<string>& node) {
    if (node.empty() || node[0] == "null") return nullptr;
    
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
int maxDiffWithAncestor(TreeNode*root,int ancestor){
	int curr=0;
	if(root==nullptr){
		return max(curr,abs(root->val-ancestor));
	}
	curr=max(curr,abs(root->val-ancestor));
	int left=maxDiffWithAncestor(root->left,ancestor);
	int right=maxDiffWithAncestor(root->right,ancestor);
	return curr;
}
int 
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
    int maxDiff = Max_Diff(root);
    cout << maxDiff;
    
    return 0;
}
