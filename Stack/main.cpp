#include <iostream>
using namespace std;


class NodeStack
{
	public:
	
	int data;
	NodeStack *next;
};


class Stacklist
{
	public:
		
		NodeStack *top;
		
		Stacklist()
		{
			top = NULL;
		}
		
		
		bool isStackEmpty()
		{
			return (top == NULL);
		}
		
		void push(int number)
		{
			NodeStack *newnode = new NodeStack();
			newnode->data = number;
			
			if(isStackEmpty())
			{
				newnode->next = NULL;
				top = newnode;
			}
			else{
				newnode->next = top;
				top = newnode;
			}
		}
		
		
		
		int pop()
		{
			int value;
			
			NodeStack *delptr = top;
			value = delptr->data;
			top=top->next;
			delete delptr;
			return value;
		}
		
		
		
		void display()
		{
			NodeStack *temp = top;
			
			while(temp != NULL)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			
			cout<<"\n";
		}
		
		int count()
		{
			int counter=0;
			NodeStack *temp = top;
				while(temp != NULL)
			{
				counter ++;
				temp = temp->next;
			}
			return counter;
		}
		
		
		int peek()
		{
			return top->data;
		}
		
		
		bool search(int number)
		{
			NodeStack *temp =top;
			bool found = false;
		    while(temp != NULL){
	
			if(temp->data == number)
			found = true;
			temp = temp->next;
		}
			
			return found;
		}
};




int main()
{
	Stacklist s;
	
	int time , num , opreation;
	char OP = 'r' || 'R';
	
 
	

	while(OP == 'R' || 'r'){
	
	cout<<"\n\n1- Push Element\n 2- Pop Element\n 3- Top Element\n 4- Display Elements\n 5- Search Element\n 6- Number of Elements\n 7- Exit...\n\n"; 
	
	cout<<"--------------Cohese order----------------\n";
	cin>>opreation;
	switch(opreation){
		case 1:{
				cout<<"How many nubers you wanna insert\n";
         	cin>>time;
         	cout<<"____________________________________________________________________________\n";
        	for(int i=1; i<=time; i++)
	{
	    	cout<<"\nEnter Itme "<<i<<endl;
	    	cin>>num;
	    	s.push(num);
	}
			break;
		}
		
		case 2:{
				if(s.isStackEmpty()){
					cout<<"The stack is empty\n\n";
				}else{
					s.pop();
				cout<<"The element pop successfully\n\n";}
			break;
		}
		
		case 3:{
			if(s.isStackEmpty()){
					cout<<"The stack is empty\n\n";
			}else{cout<<"The Top element is "<<s.peek()<<"\n\n";}
			break;
		}
		
		case 4:{
			if(s.isStackEmpty()){
				cout<<"The stack is empty\n\n";
			}else{cout<<"Stack has: ";s.display();cout<<"\n\n";}
			
			break;
		}
		
		case 5:{
			
			cout<<"What's your element\n\n";
			  cin>>num;
			 if (s.search(num)){
			  cout<<"your element was found\n\n";}
			  else{cout<<"Sorry, your element wasn't found\n\n";}
			 
			break;
		}
		
		case 6:{
			if(s.isStackEmpty()){
				cout<<"Stack is empty\n\n";
			}else{cout<<"Stack has "<<s.count()<<" Element \s\n\n";}
			break;
		}
		
		default:{cout<<"Thanks for visiting us\n\n";break;}
	}
	
	cout<<"To order again press 'R' Or any character to exit\n";
	cin>>OP;


	
}

}
