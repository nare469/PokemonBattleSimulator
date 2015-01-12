#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

class Queue                  //class definition
{
	struct node
	{
		int n;
		node *link;
	};
	node *front, *rear;
	public:
		Queue()
		{
			front = NULL;
			rear = NULL;
		}
		void Insert();
		void Delete();
		void Traverse();
};

void Queue::Insert()               //Insert function
{
	node *ptr = new node;
	if (ptr == NULL)
	{
		cout<<"NO SPACE"<<endl;
		exit(0);
	}
	ptr->link = NULL;
	cout<<"Enter the value of the element you want to enter...";
	cin>>ptr->n;
	if (front == NULL && rear == NULL)
	{
		 front = ptr;
		 rear = ptr;
	}
	else
	{
		 rear->link = ptr;
		 rear = ptr;
	}
}

void Queue::Delete()                    //Function to delete
{
	node *temp = new node;
	temp = front;
	cout<<"Deleting "<<front->n<<endl;
	if (front == NULL)
	{
		cout<<"Empty queue!"<<endl;
		exit(0);
	}
	front = front->link;
	delete temp;
}

void Queue::Traverse()                   //Traverse the queue
{
	cout<<"The queue is:"<<endl;
	node *temp = new node;
	temp = front;
	while(temp!=NULL)
	{
		cout<<temp->n<<endl;
		temp = temp->link;
	}
}

int main()
{
	int choice;
	Queue Q;
	char ch = 'y';
	do
	{
		cout<<"1. Insert an element"<<endl;                 //Menu
		cout<<"2. Delete an element"<<endl;
		cout<<"3. Display the queue"<<endl;
		cout<<"Enter your choice...";
		cin>>choice;
		clrscr();
		switch(choice)
		{
			case 1:
				Q.Insert();
				break;
			case 2:
				Q.Delete();
				break;
			case 3:
				Q.Traverse();
		}
		cout<<"Do you want to continue? (Y/N)...";
		cin>>ch;
		clrscr();
	} while (ch == 'y' || ch == 'Y');
}






