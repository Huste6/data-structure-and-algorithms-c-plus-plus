class Solution{
	public:
		Node* removelement(node *head,int val){
			if(head==nullptr) return head;
		//tao 1 dslk moi
		node *dummy=new node(0);
		dummy->next=head;
		node* prev=dummy;
		node *curr=head;
		while(curr!=nullptr){
			if(curr->val==val){
				prev->next=curr->next;
				delete(curr);
				curr=curr->next;
			}else{
				prev=prev->next;
				curr=curr->next;
			}
		}
		return dummy->next;
}
};
