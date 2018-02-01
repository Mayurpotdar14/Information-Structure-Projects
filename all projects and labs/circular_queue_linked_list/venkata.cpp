
Conversation opened. 1 read message.

Skip to content
Using Gmail with screen readers
Mayur


More
6 of 6,972

(no subject)
Inbox
	x
VENKATA THILAK PONNAGANTI

Attachments12:26 AM (13 hours ago)

to me
Attachments area

Click here to Reply or Forward
4.31 GB (28%) of 15 GB used
Manage
Terms - Privacy
Last account activity: 13 hours ago
Details


VENKATA THILAK PONNAGANTI's profile photo
	VENKATA THILAK PONNAGANTI
Show details

// Full Name : VENKATA THILAK PONNAGANTI
// CWID      : 50160638
#include<iostream>
using namespace std;

class QUEUE
{
	private:
		struct node
		{
			int item; node* next;
			node(int x)
			{
				item = x; next = 0;
			}
		};
		typedef node *link;
		link head, tail;

	public:
		QUEUE(int)
		{
			head = 0;
		}

		int empty() const
		{
			return head == 0;
		}

	void put(int x)            		// Enqueue : Inserts the elements in the queue
	{
		link t = tail;
		tail = new node(x);
		if (head == 0)
			head = tail;
		else
			t->next = tail;
	}

	int get()						// Dequeue : Gets the element from the queue and removes it from the queue
	{
		if (head == 0)
		{
			cout << "Nothing to get; Queue is Empty" << endl;
			return 0;
		}

		else
		{
			int v = head->item; link t = head->next;
			delete head;
			head = t;
			return v;
		}
	}

	void peekAll()					// Displays the entire content of the queue in first-in first-out order; no change in the queue
	{
		link temp = head;
		if (temp == 0)
			cout << "Nothing to peek, Queue is Empty" << endl;
		if ( temp != 0 )
		{
			while ( temp->next != 0 )
			{
				cout<< temp->item <<" ";
				temp = temp->next;
			}
			cout<< temp->item<<endl;
		}
	}
};


int main()
{
	char userInput;
	int newVal, headVal;
	QUEUE a(100);
	cout<<"Please choose from the following:\n P x: puts x into queue\n G : outputs the head element and delete"<<endl;
	cout<<" E : To check is the Queue is empty\n F : Display the content of the Queue in FIFO"<<endl;
	while(true)
	{

		cin >> userInput;
		if(userInput=='P'|| userInput=='p')
		{

			cin >> newVal;
			a.put(newVal);
		}
		else if(userInput=='G'|| userInput=='g')
		{
			headVal = a.get();
			if(headVal != 0)
				cout << headVal << endl;
		}
		else if(userInput=='E'|| userInput=='e')
		{
			headVal=a.empty();
			if(headVal==0)
				cout<<"QUEUE is not empty"<<endl;
			else
				cout<<"QUEUE is empty"<<endl;
		}
		else if(userInput =='F'|| userInput =='f')
		{
			a.peekAll();
		}
		else if (userInput=='Q'|| userInput=='q')
			break;
		else
		{
			cout << "Invalid Choice" << endl;
		}
	}

	return 0;
}
