#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

struct node {
    int data;
    struct node* left;  //node ben trai
    struct node* right; //node ben phai
};

typedef struct node node;
typedef node* tree;

void khoitao(node*& head) {
    head = NULL;
}

//ham them phan tu vao cay nhi phan
void themnodevaocay(node*& head, int x) {
    if (head == NULL) {
        node* tmp = new node;
        tmp->data = x;
        tmp->left = NULL;
        tmp->right = NULL;
        head = tmp;
    }
    else {
        if (head->data > x) {
            themnodevaocay(head->left, x); //them vao ben trai
        }
        else if (head->data < x) {
            themnodevaocay(head->right, x); //de quy them vao ben phai
        }
    }
}

//ham kiem tra so nguyen to
bool ktsnt(int x) {
    if (x < 2) return false;
    else {
        if (x == 2) return true;
        else {
            if (x % 2 == 0) return false;
            else {
                for (int i = 3; i <= sqrt(x); i += 2) {
                    if (x % i == 0) return false;
                }
            }
        }
        return true;
    }
}

int dem = 0;

//ham dem so luong so nguyen to
void xulyslsnt(node* head, int& dem) {
    if (head != NULL) {
        if (ktsnt(head->data)) dem++;
        xulyslsnt(head->left, dem);
        xulyslsnt(head->right, dem);
    }
}

//ham tim kiem
node* search(node* head, int key) {
    if (head == NULL || head->data == key) {
        return head;
    }
    if (head->data < key) {
        return search(head->right, key);
    }
    return search(head->left, key);
}

void search1(node* head, int key) {
    if (head == NULL) return;
    else {
        if (head->data < key) search1(head->right, key);
        else if (head->data > key) search1(head->left, key);
        else {
            return;
        }
    }
}

//xuat cac node co 2 con
void node_co_2_con(node* head) {
    if (head != NULL) {
        //xuly:
        if (head->left != NULL && head->right != NULL)
        {
            cout << head->data << " ";
        }
        
        node_co_2_con(head->left);
        node_co_2_con(head->right);
    }
}

//xuat cac node co 1 con
void node_co_1_con(node* head) {
    if (head != NULL) {
        //xuly:
        if (head->left != NULL && head->right == NULL) {
            cout << head->data << " ";
        }
        else if (head->left == NULL && head->right != NULL) {
            cout << head->data << " ";
        }
        node_co_1_con(head->left);
        node_co_1_con(head->right);
    }
}

//xuat ra cac node la
void node_la(node* head) {
    if (head == NULL) return;
    if (head != NULL) {
        if (head->left == NULL && head->right == NULL) {
            cout << head->data << " ";
        }
        node_la(head->left);
        node_la(head->right);
    }
}
//ham tim kiem node co gia tri lon nhat
//cach khong toi uu
int MAX=INT_MIN;
int TimMax(node *head){
	if(head!=NULL){
		if(MAX<head->data) MAX=head->data;
		TimMax(head->left);
		TimMax(head->right);
	}
	return MAX;
}
//cach 2:
int timmax(node *head){
	//neu node cha ma khong ton tai cay con trai va cay con phai
	if(head->left==NULL && head->right==NULL) return head->data;
	int max=head->data;
	//de quy sang trai neu ton tai cay con trai
	/*if(head->left!=NULL){
		int left=timmax(head->left);
		//left la bien se giu gia tri cua cai node ngoai cung nhat ben trai cua node cha
		if(max<left) max=left;
	}*/
	if(head->right!=NULL){
		int right=timmax(head->right);
		if(max<right) max=right;
	}
	return max;
}
//ham tim kiem phan tu nho nhat
int timmin(node* head){
	if(head->left==NULL && head->right==NULL) return head->data;
	int min=head->data;
	if(head->left!=NULL){
		int left=timmin(head->left);
		if(min>left){
			min=left;
		}
	}
	return min;
}
//ham tim node the mang
void DiTimNodeTheMang(node *&tmp,node *&tmp1){
	//duyet sang ben trai nhat cua cay con phai
	if(tmp1->left!=NULL){
		DiTimNodeTheMang(tmp,tmp1->left);
	}else{//tim ra duoc node trai nhat
		tmp->data=tmp1->data;//cap nhat cai data cua node can xoa chinh la data cua node the mang
		tmp=tmp1; // cho node tmp tro den node the mang=> xoa node tmp ra khoi man hinh
		tmp1=tmp1->right;//cap nhat node cha cua node the mang bang NULL
	}
}
//xoa 1 phan tu bat ki trong node
//xoa node la va node 1 con
void XoaNode(node *&head,int val){
	if(head==NULL) return;
	else{
		if(head->data > val){
			XoaNode(head->left,val); // duyet sang nhanh trai cua cay
		}else if(head->data<val){
			XoaNode(head->right,val);//duyet sang nhanh phai cua cay
		}else{
			node *tmp=head;
			//neu nhu nhanh trai bang null tung duong cay con phai
			if(head->left==NULL){
				head=head->right;
			}else if(head->right==NULL){
				head=head->left;
				//duyet sang trai cua node can xoa de cap nhat moi lien ket giua node cha cua node can xoa voi node con cua node can xoa
			}else{
				//xoa node 2 con tim ra node the mang cho node can xoa
				// node the mang phai dam bao quy tac cay nhi phan tim kiem
				// c1: tim node trai nhat cua cay con phai(cay con phai cua node can xoa)
				node *tmp1=head->right;
				//node tmp1 la node the mang cua node can xoa
				//dam nhan tim ra node trai nhat
				DiTimNodeTheMang(tmp,tmp1);
				// c2: tim node phai nhat cua cay con trai(cay con trai cua node can xoa)
				
			}
			delete(tmp);
		}
	}
}
//xoa node 2 con tim ra node the mang cho node can xoa
// node the mang phai dam bao quy tac cay nhi phan tim kiem
//tim node trai nhat cua cay con trai(cay con trai cua node can xoa)
//tim node phai nhat cua cay con phai(cay con phai cua node can xoa)

void printtree(node* head) {
    if (head != NULL) {
        printtree(head->left);
        cout << head->data << " ";
        printtree(head->right);
    }
}
//ham tra ve level cua cay
int treeLevel(node *t){
    if(t == nullptr)
        return -1;
    
    int leftHeight = treeLevel(t->left);
    int rightHeight = treeLevel(t->right);
    
    return max(leftHeight, rightHeight) + 1;
}
//kiem tra cay do co phai la cay avl hay kong
bool checkAvl(node *t){
    if(t==NULL) return true;
    if(abs(treeLevel(t->left)-treeLevel(t->right))>1) return false;
    return checkAvl(t->left) && checkAvl(t->right);
}
//ham xoa 1 node dong thoi xoa luon node con cua no
void deletenode(node *t){
    if(t==NULL) return;
    if(t!=NULL){
        if(t->left!=NULL) deletenode(t->left);
        if(t->right!=NULL) deletenode(t->right);
        delete(t);
    }
}
void deletenumber(node *t,int x){
    if(t!=NULL){
        if(t->data==x){
            deletenode(t->right);
            deletenode(t->left);
            t==NULL;
        }else{
            if(t->data > x) deletenumber(t->left);
            else deletenumber(t->right);
        }
    }
}
int main() {
    node* head = NULL;
    while (1) {
        cout << "---------------------" << endl;
        cout << "1.nhap phan tu\n";
        cout << "2.duyet cay\n";
        cout << "3.dem so luong so nguyen to\n";
        cout << "4.tim kiem phan tu \n";
        cout << "5.xuat ra cac node co 2 con \n";
        cout << "6.xuat ra cac node co 1 con \n";
        cout << "7.xuat ra cac node la \n";
        cout << "8.phan tu lon nhat cua cay\n";
        cout << "9.phan tu nho nhat cua cay\n";
        cout << "10.xoa phan tu\n";
        cout << "0.thoat\n";
        cout << "---------------------" << endl;
        cout << "nhap lua chon: ";
        int lc;
        cin >> lc;
        if (lc == 1) {
            int x;
            cin >> x;
            for (int i = 0; i < x; i++) {
                int n;
                cin >> n;
                themnodevaocay(head, n);
            }
        }
        else if (lc == 2) {
            printtree(head);
            cout << endl;
        }
        else if (lc == 3) {
            int dem = 0;
            xulyslsnt(head, dem);
            cout << "so luong so nguyen to: " << dem << endl;
        }
        else if (lc == 4) {
            int key;
            cin >> key;
            if (search(head, key) == NULL)
                cout << "khong tim thay phan tu " << key << endl;
            else
                cout << "tim thay phan tu " << key << endl;
        }
        else if (lc == 5) {
            cout << "node co 2 con: ";
            node_co_2_con(head);
            cout << endl;
        }
        else if (lc == 6) {
            cout << "node co 1 con: ";
            node_co_1_con(head);
            cout << endl;
        }
        else if (lc == 7) {
            cout << "node la: ";
            node_la(head);
            cout << endl;
        }else if(lc==8){
        	cout<<"tim max: "<<timmax(head);
        	cout<<endl;
		}else if(lc==9){
			cout<<"tim min: "<<timmin(head);
			cout<<endl;
		}else if(lc==10){
			cout<<"xoa phan tu: ";
			int val;cin>>val;
			XoaNode(head,val);
		}
        else {
            break;
        }
    }
    return 0;
}
