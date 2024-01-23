#include <iostream>
using namespace std;


class Node
{
	public:
	int data;
	Node *left , *right;
	
	Node(int value)
	{
		data = value;
		left = right = NULL;
	}
};


class BST
{
	public:
		
	Node *root;
	BST(){root = NULL;}
	
	
	Node* insert(Node* r , int item)
	{
		if(r == NULL)
		{
			Node *newnode = new Node(item);
			r = newnode;
		}
		
		else if(item <r->data)
		        r->left = insert(r->left , item);
		else
		        r->right = insert(r->right , item);
				
				return r;       
		
	}
	
	void insert(int item)
	{
	  root = insert(root , item);
	}
	
	
	
	
	Node* search(Node * r , int item)
	{
		if(r == NULL)
		   return NULL;
		   
		else if(r->data == item )
		   return r;
		   
		else if(item < r->data)
		   return search(r->left , item);
		   
		else 
		   return search(r->right , item);
	}
	
	bool search(int item)
	{
		Node *result = search(root , item);
		
		if(result == NULL)
		return false;
	  else
	    return true;
	}
	
	
	void preorder(Node * r)   //preorder....
	{
		if(r == NULL)
		return;
		cout<<r->data<<"\t";
		preorder(r->left);
		preorder(r->right);
	}
	
	

   	void inorder(Node * r)   //inorder....
	{
		if(r == NULL)
		return;
		
		inorder(r->left);
		cout<<r->data<<"\t";
		inorder(r->right);
	}
	
	
	void postorder(Node * r)   //postorder....
	{
		if(r == NULL)
		return;
		
		postorder(r->left);
		postorder(r->right);
		cout<<r->data<<"\t";
	}
	
//	minimum value........
	Node * findmin(Node *r)
	{
		if(r == NULL)
		return NULL;
		
		else if(r->left == NULL)
		return r;
		
		else 
		return findmin(r->left);
	}
	
	//maximum value........
	Node * findmax(Node *r)
	{
		if(r == NULL)
		return NULL;
		
		else if (r->right == NULL)
		return r;
		
		else
		return findmax(r->right);
	}
	
	
	//Delete item from tree.....
	Node * Delete(Node *r , int item)
	{
		if(r == NULL)
		return NULL;
		else if(item < r->data)
		r->left = Delete(r->left , item);
		else if(item > r->data)
		r->right = Delete(r->right , item);
		
		else{
			if(r->left == NULL && r->right == NULL)
			return NULL;
			
			else if(r->left!= NULL && r->right == NULL)
			{
				r->data = r->left->data;
				delete r->left;
				r->left = NULL;
			}
			else if(r->left == NULL && r->right != NULL)
			{
				r->data = r->right->data;
				delete r->right;
				r->right = NULL;
			}
			
				else{
			Node * max = findmax(r->left);
			r->data = max->data;
			Delete(r->left , max->data);
	
	    	
		}
	
		}
		
		return r;
		
}
	

	
};






int main(int argc, char** argv) {
	
	
	BST b;
	int item , opreation , num;
    char OP ='R' || 'r';
	 
	      

    	while(OP == 'R' || 'r'){
		     cout<<" -------------------------------------------OUR SERVICES-----------------------------------\n\n";
     cout<<"\n\n 1- Insert Node\n 2- Search Node\n 3- Delete Node\n 4- Preorder Travirsing\n 5- Inorder Travirsing\n 6- Post order Travising\n 7- Max Node\n 8- Minimum Nod\n 9-Exit... '";
     cout<<"\n\n";
     cout<<"---------------------------------------------------------\n";

			cout<<"Enter your order\n\n_____________________________________________________________________________________________\n\n";

      cin>>opreation;
      
      switch(opreation){
      	case 1:{
      		 cout<<"How many bumber/s do you wanna insert\n";
             cin>>num;
          for(int i=1; i<=num; i++){
          
      		cout<<"Insert Node "<<i<<endl;
      		cin>>item;
      		b.insert(item);
      	}
      		break;
      	}
      	
      	case 2:{
      		cout<<"Enter Node for searching on: \n";
      		cin>>item;
      	  if(b.search(item)){
      	  	cout<<"item found\n";
      	  }else{
      	  	cout<<"item isn't found\n";
      	  }
      		break;
      	}
      	
      	case 3:{
      		cout<<"Enter Node for deleting: \n";
      		cin>>item;
      		b.Delete(b.root , item);
      		break;
      	}
      	
      	case 4:{
      		cout<<"\n\nThr Preorder Travising: ";b.preorder(b.root);
      		break;
      	}
       
	   case 5:{
      		cout<<"\n\nThr Inorder Travising: ";b.inorder(b.root);
      		break;
      	}
      	
      	case 6:{
      		cout<<"\n\nThr Postorder Travising: ";b.postorder(b.root);
      		break;
      	}
      	
      	case 7:{
      		Node *max = b.findmax(b.root);
      		cout<<"The max Node is: "<<max->data;
      		break;
      	}

        case 8:{
        	Node *min = b.findmin(b.root);
      		cout<<"The min Node is: "<<min->data;
      		break;
      	}
		  
		  default:{
		  	cout<<"Thanks for your visiting\n";
		  	break;
		  }	    
      }
      
      
       cout<<"\n\nPress 'R' to order again (*__*) Or any character to exit...\n\n\n";
     cin>>OP;
		




  }
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//	BST b;
//	int num;
//	cout<<"enter 5 numbers\n";
//	for(int i=0; i<5; i++){
//		cin>>num;
//        b.insert(num);
//	}
//	
//	cout<<"Traversing with preorder..............\n\n";
//	b.preorder(b.root);cout<<endl;
////	cout<<"Traversing with inorder..............\n\n";
////	b.inorder(b.root);cout<<endl;
////	cout<<"Traversing with postoreder..............\n\n";
////	b.postorder(b.root);cout<<endl;
//
//	cout<<"Enter item to search on....\n";
//	cin>>num;
//	cout<<"\n\n________________________________\n";
//	if(b.search(num))
//	cout<<"item found\n";
//	else
//	cout<<"item not found\n";
//	
//	cout<<"________________________________\n";
//	Node *min = b.findmin(b.root);
//    if(min == 0)
//    cout<<"minimum isn't exist\n";
//    else
//    cout<<"minimum = "<<min->data<<endl;
//	
//	cout<<"________________________________\n";
//	Node *max = b.findmax(b.root);
//	if(max == NULL)
//	cout<<"maximum isn't exist\n";
//	else
//	cout<<"maximum = "<<max->data<<endl;
//	
//	cout<<"\n\nEnter item to delete from\n";
//	cin>>num;
//	b.Delete(b.root , num);
//	cout<<"\n\n The tree after deleting : ";b.preorder(b.root);
//	
	
	return 0;
}
