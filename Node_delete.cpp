//						TO DELETE A SPECIFIC NODE Greater Than X

#include<iostream>  
using namespace std ;
struct Node
{
	int Data ;
	struct Node* Link ;
};

struct Node* Head = NULL ;

void Insert_Beg(int Value)  // To Create a list
{
	struct Node* Temp = new(struct Node) ;
	if(Head == NULL)
	{
		Temp -> Data = Value ;
		Temp -> Link = NULL ;
		Head = Temp ;
	}
	else
	{
		Temp->Data=Value;
		Temp->Link=Head;
		Head=Temp;
	}
}
	


void Print()  // To print The List 
{
	struct Node* Temp = Head ;
	
	if(Head == NULL)
		cout << "The List Is Empty" << endl ;
	while(Temp != NULL)
	{
		cout << Temp -> Data << endl ;
		Temp =  Temp -> Link ;
	}
}


void Delete(int Number)  // To Delete The Number 
{
	struct Node* Temp =  Head ;
	struct Node* Temp1 = Head ;	
	struct Node* Temp2 = Head ;
	while(Temp!=NULL)
	{
		if(Head == NULL) 
		{
			cout << "The List Is Empty" << endl ;
			return;
		}
  		if(Temp->Data <= Number && Temp == Head) 	//For First Element 
			{	
				Temp = Temp->Link ;
				Temp2 = Head ; 
				Head = Temp1->Link ;
				Temp1 = Head ;
				delete(Temp2) ;
				
			}
		
		else if(Temp->Data <= Number)
		{	 
				Temp = Temp->Link ;
				Temp2 = Temp1->Link ;
				Temp1->Link = Temp2->Link ;
				delete(Temp2);
				 
		}	
		else
		{
			Temp1 = Temp ;
			Temp = Temp->Link ;
		}
	}
}



main()
{
	int Size , Number ;
	cout << "Enter The Size Of The List"<< endl ;
	cin >> Size ;
	cout << "Enter List" << endl ;
	for(int i=0;i<Size;i++)
{ 
	cin>>Number;
	Insert_Beg(Number);
}
	cout << "List is" << endl ;
	Print() ;
	cout << "Enter The Number" << endl ;
	cin >> Number ;
	Delete(Number) ;
	cout << endl << "THE FINAL LIST IS:"<<endl;
	Print() ;
	
}
