#include <iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
};

class list{
	
	public:
		node* head;
	node* head2;
		list();
		void insert(int n);
		void insert2(int n);
		void concat();
		int countOfNodes();
		void traverse();
		void traverse2();
};



list::list(){
	head=NULL;
	head2=NULL;
	
}

// Count Numbers Of Nodes
int list::countOfNodes(){
	int n=0;
	if(head==NULL){
		n=0;
	}
	else{
		node*temp=head;
		while(temp!=NULL){
			temp=temp->next;
			n++;
		}
	}
	return n;
}


//Insert Frount for head2
void list::insert2(int n){
node *newNode=new node;
newNode->data=n;
newNode->next=NULL;
newNode->next=head2;
head2=newNode;	
}

//Insert Frount for head
void list::insert(int n){
	node *newNode=new node;
	newNode->data=n;
	newNode->next=head;
	head=newNode;
}

//concatenate two linked lists
void list::concat(){
		if(head==NULL)
			cout<<"Can not concat\n";
		else{
			node *t=head;
			while(t->next!=NULL)
				t=t->next;		
			t->next=head2;
			while(t!=NULL)
				t=t->next;
			t=head;
			while(t!=NULL){
				cout<<t->data<<" ";
				t=t->next;
			}		
		}	
		
}

//display function
void list::traverse(){
	if(head==NULL){
		cout<<"The List is empty!\n";
	}
	
	else{
		node *temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;		
	}
}

//display function
void list::traverse2(){
	if(head2==NULL){
		cout<<"The List is empty!\n";
	}
	
	else{
		node *temp=head2;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;		
	}
}

int main(){
	list l;
	cout<<"node 1\n";
	l.insert(10);
	l.insert(20);
	l.insert(30);
	l.insert(40);
	l.traverse();
	cout<<"node 2\n";
	l.insert2(100);
	l.insert2(200);
	l.insert2(300);
	l.insert2(400);
	l.traverse2();
	cout<<"The concatenate\n";
	l.concat();
	cout<<"\nThe Numbers of nodes is "<<l.countOfNodes()<<endl;
}
