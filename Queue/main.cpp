#include <iostream>
using namespace std;
 
 class Node
 {
 	public:
 		int data;
 		Node *next;
 		
 		Node()
 		{
 			data = 0;
 			next = NULL;
 		}
 };
 
 
 class Queue
 {
 	public:
 		Node *front;
 		Node *rear;
 		
 		Queue()
 		{
 			front = NULL;
 			rear = NULL;
 		}
 		
 		
 		
 		bool isEmpty()
 		{
 			if(front == NULL)
 			return true;
 		  else
 		    return false;
 		}
 		
 		
 		void Enqueu(int item)
 		{
 			Node * newnode = new Node();
 			newnode->data = item;
 			
 			if(isEmpty())
 			front = rear = newnode;
 			else{
 			
 			rear->next = newnode;
 			rear = newnode;}
 		}
 		
 		
 		int Dequeue()
 		{
 			int delvalue = -1;
 			if(isEmpty())
 			cout<<"Queue is empty\n";
 			
			 else if(front == rear){
 				delete front;
 				front = rear = NULL;
 			}
			 
			 else{
			 	Node *delptr = front;
			 	front = front->next;
			 	delvalue = delptr->data;
			 	delete delptr;
 				
 			}
 			return delvalue;
 		}
 		
 		
 		int getFront(){return front->data;}
 		
 		int getRear(){return rear->data;}
 		
 		int count()
 		{
 				int counter = 0;
				 Node *temp = front;
 			while(temp != NULL){
 				counter ++;
 				temp = temp->next;
 			}
 			return counter;
 		}
 		
 		
		 
		 
		 bool isFound(int item)
 		{
 			Node *temp = front;
 			bool found = false;
 			while(temp != NULL){
 				if(temp->data == item)
 				found = true;
 				temp = temp->next;
 			}
 			return found;
 		}
 		
 		
 		
 		
 		void Clear()
 		{
 			while(!isEmpty())
 			{
 				Dequeue();
 			}
 		}
 		
 		
 		
 		void display()
 		{
 		
 			Node *temp = front;
 			while(temp != NULL){
 				cout<<temp->data<<"";
 				temp = temp->next;
 			}
 			cout<<endl;
 		}
 		
 		
 		
 		
 };
 
 
 
 
 
 
int main(int argc, char** argv) {
	
	
	
	
	Queue Q;
	int num , item , opreation;
	char OP = 'r' || 'R';
	
	
	while(OP == 'r' || 'R'){
	
	cout<<" 1- Enqueue\n 2- Dequeue\n 3- Search in queue\n 4- Display\n 5- Number of element in queue\n 6- Clear queue\n 7- Front of queue\n 8- End of queue\n 9-Exit...";
	
	cout<<"\n--------------------------Choese order---------------------------\n";
	cin>>opreation;
	
	switch(opreation){
		
		case 1:{
			cout<<"How many element do you wanna enqueue\n";
			cin>>num;
			cout<<"________________________________________________________\n";
			for(int i=1; i<=num; i++){
				cout<<"Enter element "<<i<<endl;
				cin>>item;
				Q.Enqueu(item);cout<<"__________________________________________\n";
			}
			break;
		}
		
		case 2:{
			if(Q.isEmpty()){
				cout<<"Queue is empty\n\n";
			}
			else{
				Q.Dequeue();
				cout<<"Element was dequeued successfully\n\n";
				cout<<"__________________________________________\n";
			}
			break;
		}
		
		case 3:{
			if(Q.isEmpty()){
				cout<<"Queue is empty\n\n";
				cout<<"__________________________________________\n";
			}
			else{
				cout<<"Enter element to search for\n";
				cin>>item;
				if(Q.isFound(item)){
					cout<<"Element was fonud\n\n";
					cout<<"__________________________________________\n";
				}
				else{
					cout<<"Element wasn't found\n\n";
					cout<<"__________________________________________\n";
				}
			}
			break;
		}
		
		case 4:{
			   if(Q.isEmpty()){
				cout<<"Queue is empty\n\n";
				cout<<"__________________________________________\n";
			}
			else{
				cout<<"Queue has: ";Q.display();
				cout<<"__________________________________________\n";
			}
			break;
		}
		
		case 5:{
			if(Q.isEmpty()){
				cout<<"Queue is empty\n\n";
				cout<<"__________________________________________\n";
			}else
			{
				cout<<"Queue has "<<Q.count()<<" element\n\n";
				cout<<"__________________________________________\n";
			}
			break;
		}
		
		case 6:{
			if(Q.isEmpty()){
				cout<<"Queue is empty\n\n";
				cout<<"__________________________________________\n";
			}
			else{
				cout<<"Queue has been cleared successfully";Q.Clear();cout<<"\n\n";
				cout<<"__________________________________________\n";
			}
			break;
		}
		
		case 7:{
			if(Q.isEmpty()){
				cout<<"Queue is empty\n\n";
				cout<<"__________________________________________\n";
			}
			else{
				cout<<"First element in queue is "<<Q.getFront();
				cout<<"__________________________________________\n";
			}
			break;
		}
		
		case 8:{
			if(Q.isEmpty()){
				cout<<"Queue is empty\n\n";
				cout<<"__________________________________________\n";
			}
			else{
				cout<<"Last element in queue is "<<Q.getRear();
				cout<<"__________________________________________\n";
			}
			break;
		}
		
		default:{cout<<"Thanks for visiting us\n\n";break;cout<<"__________________________________________\n";}
		
		
	
	}
		cout<<"To order again press 'R' Or any character to exit\n";
		cin>>OP;
		
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
