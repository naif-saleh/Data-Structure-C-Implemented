#include <iostream>
using namespace std;


 void inc(int n)
 {
 	if(n < 0)
 	return ;
 	
	 else
	  cout<<"round:"<<n<<endl;
	  inc(n-1);
 	
 }  
 
 
 int fact(int n)
 {
 	if(n == 0 || n == 1)
 	return 1 ;
 	
 	else
 	return n * fact(n-1);
 }
 
 float fibo(float n)
 {
 	if(n == 0 || n == 1)
 	return n;
 	
 	else
 	
 	return fibo(n-1) + fibo(n-2);
 }
 
 
 int sum(int n)
 {
 	if(n == 1)
 	return n;
 	
 	else
 	  return n + sum(n - 1);
 }
 
 
 int sumBtweenNumbers(int x , int y)
 {
 	if(x == y)
 	return x;
 	
 	else
 	
 	  return y + sumBtweenNumbers(x , y-1);
 }
 
 
 void print_star(int n)
 {
 	if(n < 0)
 	return;
 	
 	 print_star(n-1);
 	  for(int i=0; i<n; i++)
 	  cout<<"*";
 	  cout<<endl;
 	 
 }
 
 void printDigits(int n)
 {
 	if(n == 0)
 	return;
 	
 	else
 	
 	printDigits(n/10);
 	cout<<n % 10<<endl;
 }

int main(int argc, char** argv) {
	
//      float x , y;
//	  cout<<"Enter number\n";
//	  cin>>x>>y;
//	 
//	  cout<<sumBtweenNumbers(x , y); 

   printDigits(854522);     
	return 0;
}
