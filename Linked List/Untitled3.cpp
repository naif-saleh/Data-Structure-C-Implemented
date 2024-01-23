#include<iostream>
using namespace std;

class Node 
{
	public:
		int data;
		Node *next;
};


class ops
{
	public:
		Node *head;
		
		ops()
		{
			head = NULL;
		}
		
		
		
		
		
		bool isEmpty(){return head == NULL;}
		
		//insert Front...........
		void insertFront(int num)
		{
			Node *newnode = new Node();
			newnode->data = num;
			
			if(isEmpty()){
				newnode->next = NULL;
				head = newnode;
			}else{
				newnode->next= head;
				head = newnode;
			}
		}
		
		
		
		//insert End..............
		void insrtEnd(int num)
		{
			Node *newnode = new Node();
			Node *temp = head;
			
			newnode->data = num;
			while(temp->next != NULL){
				temp = temp->next;
			}
			
			temp->next = newnode;
			newnode->next = NULL;
		}
		
		
		//inser Befor.......
		void insertBefor(int num , int newnum)
		{
			Node *newnode = new Node();
			Node *temp = head;
			
			newnode->data = newnum;
			while(temp != NULL && temp->next->data != num)
			{
				temp = temp->next;
			}
			
			newnode->next = temp->next;
			temp->next = newnode;
		}
		
		//Delete first........
		void delFirst()
		{
			int num;
			Node *delptr = head;
			
			num = delptr->data;
			head = head->next;
			delete delptr;
			
		}
		
		//Delete By Name.......
		void delBycall(int num)
		{
		   
		   if(isEmpty())
		   cout<<"List is empty\n";
		   
		   Node *delptr = head;
		   if(head->data == num)
		   {
		   	head = head->next;
		   	delete delptr;
		   }
		   else{
		   	
		   	Node *prev = NULL;
		   	delptr = head;
		   	while(delptr->data != num)
		   	{
		   		prev = delptr;
		   		delptr= delptr->next;
		   	}
		   	
		   	prev->next = delptr->next;
		   	delete delptr;
		   	
		   }
		   
		
		}
		
		
		
		//Search Item..............
		bool search(int item)
		{
			bool found = false;
			Node *temp = head;
		    while(temp != NULL){
		       
			   if(temp->data == item)
				found = true;
				temp = temp->next;
		    }
			return found;
						
		}
		
		
		
		//Counting items.......................
		int count()
		{
			Node *temp = head;
			int counter = 0;
			while(temp != NULL){
				counter ++;
				temp = temp->next;
			}
			return counter;
		}



       //Travearsing function.......
       
       void print()
       {
       	Node *temp = head;  
       	while(temp != NULL){
       		cout<<temp->data<<"";
       		temp = temp->next;
       	}
       	cout<<"\n";
       }



		
};






int main()
{
     
     ops op;
     string info; string delF = "deleteF"; string delByIt = "deleteI";
     int time , num , newnum , opreatio;
     char OP ='R' || 'r';
	 
	      

    

    

	while(OP == 'R' || 'r'){
		     cout<<" -------------------------------------------OUR SERVICES-----------------------------------\n\n";
     cout<<"\n\n 1- Insert item at first\n 2- Insert item at end\n 3- Insert item befor\n 4- print the list's items\n 5- check if item found or not\n 6- Number of items in list\n 7- Deletion services\n 8- Exit... '";
     cout<<"\n\n";
     cout<<"---------------------------------------------------------\n";

			cout<<"Enter your order\n\n_____________________________________________________________________________________________\n\n";

     cin>>opreatio;
     switch(opreatio){
     	case 1:{
    
	      cout<<"How many bumber/s do you wanna insert\n";
          cin>>time;
          cout<<"\n\n";
          cout<<"---------------------------------------------------------\n\n";

	
	 		 for(int i=1; i<=time; i++){
     	cout<<"Enter num "<<i<<endl;
     	cin>>num;
     	op.insertFront(num);
       }
      
      cout<<"\n---------------------------------------------------------\n\n";
		
     		break;
     	}
     	
     	case 2:{
     		
     		 cout<<"How many bumber/s do you wanna insert\n";
             cin>>time;
             cout<<"\n\n";
             cout<<"---------------------------------------------------------\n\n";

     		
     		 cout<<"Enter num to add end\n";
             cin>>num;
        	 op.insrtEnd(num);
        	   cout<<"\n---------------------------------------------------------\n\n";

     		break;
     	}
     	
     		case 3:{
     			if(op.isEmpty()){
     				cout<<"Sorry, item you wanna add befor is'n found\n";
     			}else{
     				
     				 cout<<"How many bumber/s do you wanna insert\n";
                     cin>>time;
      				 cout<<"\n\n";
      				 cout<<"---------------------------------------------------------\n\n";

     			
     		 cout<<"Enter num to add befor\n";
 		     cin>>num;
     		 cout<<"Enter the num u wanna add\n";
     		 cin>>newnum;
     		 op.insertBefor(num , newnum);
     		   cout<<"\n---------------------------------------------------------\n\n";
        }
     		break;
     	}
     	
     		case 4:{
     				if(op.isEmpty()){
     				cout<<"Sorry,the list is empty\n";
     			}else{
		      cout<<"your list include: "; op.print();	 
		        cout<<"\n---------------------------------------------------------\n\n";
	     }
			 break;
     	}
     		case 5:{
     				if(op.isEmpty()){
     				cout<<"Sorry,the list is empty\n";
     			}else{
     		 cout<<"Enter item to check if it is found or not\n";
   		     cin>>num;
     		 cout<<"the item is "<< op.search(num);
      		 cout<<"\n\n";
      	     cout<<"\n---------------------------------------------------------\n\n";
     	}
			 break;
     	}

           	case 6:{
           			if(op.isEmpty()){
     				cout<<"Sorry,the list is empty\n";
     			}else{
     		  cout<<"You have: "<<op.count();
       		  cout<<"\n\n";
      	      cout<<"---------------------------------------------------------\n\n";
     	}
			 break;
     	}     	
     	
     	case 7:{
     	
		 	cout<<"- if you wanna delete the first item 'type [deleteF]'.....\n\n";
            cout<<"- if you wanna delete the item by its name enter delet by name'type [deleteI]'.....\n\n";
          cin>>info;
     		
     	 if (info == delF){
                    
		        op.delFirst();
      	        cout<<"\nYou deleted first item successfully: \n";op.print();	
                }
				else if(info == delByIt){
                cout<<"\n\n";
                cout<<"---------------------------------------------------------\n\n";
	            cout<<"Enter num to be deleted\n";
                cin>>num;
                op.delBycall(num);
                cout<<"\nThe item is deleted successfully: \n";op.print();
	            cout<<"\n\n\n"; 
		  
                }   
	           else{cout<<"\n\n---------Please enter order correctly--------\n\n\n\n";}

     		
     		break;
     	}
     	
     	default:{cout<<"Thanks for your visting\n";break;	}
    
     
      cout<<"\n\nPress 'R' to order again (*__*) Or any character to exit...\n\n\n";
     cin>>OP;
     
 }
  
}
  
  
  
  
  
  
     
     
}
