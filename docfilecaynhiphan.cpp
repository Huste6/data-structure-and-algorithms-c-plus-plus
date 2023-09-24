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
//ham doc file
void Doc_File(node *&tree,ifstream &filein){
	int n;
	filein>>n;
	for(int i=1;i<=n;i++){
		int x;
		filein>>x;
		themnodevaocay(tree,x);
	}	
}
void Doc_File1(node *&tree,ifstream &filein){
	while(true){
		int x;
		filein >> x;
		themnodevaocay(tree,x);
		char tmp;
		filein >> tmp;
		if(filein.eof()){
			break;
		}
	}
}
void printtree(node* head) {
    if (head != NULL) {
        printtree(head->left);
        cout << head->data << " ";
        printtree(head->right);
    }
}
int main(){
	node* t=NULL;
	/*ifstream filein;
	filein.open("caynhiphan.txt",ios_base::in);
	Doc_File(t,filein);*/
	ifstream filein;
	filein.open("caynhiphan1.txt",ios_base::in);
	Doc_File1(t,filein);
	cout<<"Xuat cay theo dang LNR: ";
	printtree(t);
	cout<<endl;
	cout<<"Xuat cac node la: ";
	node_la(t);
	cout<<endl;
	cout<<"Xuat cac node co 1 con: ";
	node_co_1_con(t);
	cout<<endl;
	cout<<"Xuat cac node co 2 con: ";
	node_co_2_con(t);
	cout<<endl;
	filein.close();
}
