#include <bits/stdc++.h>
using namespace std;

struct treenode{
    int data;
    struct treenode* left;
    struct treenode* right;
};

treenode* newnode(int x) {
    treenode* node = new treenode();
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

treenode* find_treenode(treenode* node, int x) {
    if(node == NULL)
        return NULL;

    if(node->data == x)
        return node;

    treenode* tmp = node->left;
    while(tmp != NULL) {
        treenode* q = find_treenode(tmp, x);
        if(q != NULL)
            return q;

        tmp = tmp->right;
    }

    return NULL;
}

void preorder(treenode* node) {
    if(node == NULL)
        return;

    cout<<node->data<<" ";

    treenode* tmp = node->left;
    while(tmp != NULL) {
        preorder(tmp);
        tmp = tmp->right;
    }
}

void inorder(treenode* node) {
    if(node == NULL)
        return;

    treenode* tmp = node->left;
    inorder(tmp);
    cout<<node->data<<" ";

    if(tmp != NULL) {
        tmp = tmp->right;
    }

    while(tmp != NULL) {
        inorder(tmp);
        tmp = tmp->right;
    }
}

void postorder(treenode* node) {
    if(node == NULL)
        return;

    treenode* tmp = node->left;
    while(tmp != NULL) {
        postorder(tmp);
        tmp = tmp->right;
    }

    cout<<node->data<<" ";
}

int count_node(treenode* node) {
    if(node == NULL)
        return 0;

    int s = 1;
    treenode* tmp = node->left;
    while(tmp != NULL) {
        s += count_node(tmp);
        tmp = tmp->right;
    }

    return s;
}

int count_leaves(treenode* node) {
    if(node == NULL)
        return 0;

    int s = 0;
    treenode* tmp = node->left;
    if(tmp == NULL)
        s = 1;

    while(tmp != NULL) {
        s += count_leaves(tmp);
        tmp = tmp->right;
    }

    return s;
}

int height(treenode* node) {
    if(node == NULL)
        return 0;

    int maxh = 0;
    treenode* tmp = node->left;
    while(tmp != NULL) {
        int h = height(tmp);
        if(h > maxh)
            maxh = h;
        tmp = tmp->right;
    }

    return maxh + 1;
}

int depth(treenode* node, int v, int d) {
    if(node == NULL)
        return -1;

    if(node->data == v)
        return d;

    treenode* tmp = node->left;
    while(tmp != NULL) {
        if(tmp->data == v)
            return d + 1;
        int dv = depth(tmp, v, d + 1);
        if(dv > 0)
            return dv;
        tmp = tmp->right;
    }

    return -1;
}

int depth(treenode* node, int v){
    return depth(node, v, 1);
}

treenode* parent(treenode* p, treenode* r) {
    if(r == NULL)
        return NULL;

    treenode* tmp = r->left;
    while(tmp != NULL) {
        if(p == tmp)
            return r;
        treenode* tmp1 = parent(p, tmp);
        if(tmp1 != NULL)
            return tmp1;
        tmp = tmp->right;
    }

    return NULL;
}
//kiem tra 2 cay co giong nhau hay khong
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }
    if (p == nullptr || q == nullptr) {
        return false;
    }
    if (p->val != q->val) {
        return false;
    }
    bool leftSame = isSameTree(p->left, q->left);
    bool rightSame = isSameTree(p->right, q->right);
    return leftSame && rightSame;
}
int main() {
    treenode* root = newnode(1);
    root->left = newnode(2);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->left->right->left=newnode(3);
    root->left->right->right=newnode(6);
    root->left->right->right->right=newnode(7);
    root->left->right->right->left=newnode(8);
    while(1) {
        int lc;

        cout << "---------------------------------" << endl;
        cout << "1. Duyet cay theo pre order" << endl;
        cout << "2. Duyet cay theo in order" << endl;
        cout << "3. Duyet cay theo post order" << endl;
        cout << "4. So nut tren cay" << endl;
        cout << "5. Dem so nut la" << endl;
        cout << "6. Tim kiem nut" << endl;
        cout << "7. Do cao cua nut" << endl;
        cout << "8. Do sau cua nut" << endl;
        cout << "9. Nut cha cua nut" << endl;
        cout << "---------------------------------" << endl;

        cin >> lc;

        if(lc == 1) {
            preorder(root);
            cout << endl;
        } else if(lc == 2) {
            inorder(root);
            cout << endl;
        } else if(lc == 3) {
            postorder(root);
            cout << endl;
        } else if(lc == 4) {
            cout << count_node(root) << endl;
        } else if(lc == 5) {
            cout << count_leaves(root) << endl;
        } else if(lc == 6) {
            int x;
            cin >> x;
            treenode* node = find_treenode(root, x);
            if(node != NULL)
                cout << "Node " << x << " found." << endl;
            else
                cout << "Node " << x << " not found." << endl;
        } else if(lc == 7) {
            cout << height(root) << endl;
        } else if(lc == 8) {
            int x;
            cin >> x;
            int d = depth(root, x);
            if(d != -1)
                cout << "Depth of node " << x << " is " << d << endl;
            else
                cout << "Node " << x << " not found." << endl;
        } else if(lc == 9) {
            int x;
            cin >> x;
            treenode* p = parent(find_treenode(root, x), root);
            if(p != NULL)
                cout << "Parent of node " << x << " is " << p->data << endl;
            else
                cout << "Node " << x << " not found." << endl;
        } else {
            break;
        }
    }

    return 0;
}
