/**
Filename	: llist_queue.cpp
Name		: Maharshi Aditya Pothani
ID			: 5051028
Date		: March 30, 2016
Professor	: Dr. Mingon Kang
Program		: To Implement Queue using Linked List
**/


#include <iostream>

//Linked List structure
typedef struct Node
{
    int nData;         // data
    struct Node *pNext; // pointer to the next node
}Node;


class Queue
{

    private:
    		Node *pHead;
    		Node *pTail;
    		int i;

    public:
           Queue();						//constructor
           ~Queue();					//destructor
           void Enqueue(int nData);		//Add Elements into Queue
           int Dequeue();				//Delete Elements from Queue
           int IsEmpty();				//Check if Queue is Empty or not
           void display();				//Display Queue

};

Queue :: Queue()
{
	//initializing tail and head to NULL
    pTail = NULL;
    pHead = pTail;
    i = 0;
}

void Queue :: Enqueue(int nData)
{
    Node *pItem = new Node;
    pItem->nData = nData;
    pItem->pNext = NULL;

    if (pTail != NULL)  // If queue is not empty
    	pTail->pNext = pItem; //add to tail
    else
    	pHead = pItem; //add to head

    pTail = pItem;
    i++;
    std::cout << "  " << nData ;
}

int Queue :: Dequeue()
{
   if (IsEmpty())
    {
        std::cout << "Queue is empty" << std::endl;
        return 0;
    }

    Node *pNext = pHead->pNext; //next pointer
    int item = pHead->nData;
    // deallocating
    delete pHead;

    // update basepointer
    pHead = pNext;
    i--;

    if (i == 0)
    	pTail = NULL;

    return item;
}

int Queue :: IsEmpty()
{
	if (i > 0)
		return 0;
	else
		return 1;
}

void Queue :: display()
{
	std::cout << "  " << i << std::endl;
    Node *pIter = pHead;
    while (pIter != NULL)
    {
    	Node *pNext = pIter->pNext;
        std::cout << pIter << "\t" << pIter->nData << "\t" << pIter->pNext << std::endl;
        pIter = pNext;
    }
}

Queue :: ~Queue()
{
    // deallocation
    Node *pIter = pHead;
    while (pIter != NULL)
    {
    	Node *pNext = pIter->pNext;
        delete pIter; 					//deallocate
        pIter = pNext;
    }
    pHead = NULL;
    pTail = NULL;
    i = 0;
}

int main()
{
	Queue queue; // Supposed that the array size is 10.

	// Add 8 data

	for (int i = 0; i < 8; i++)
        queue.Enqueue(i);

	std::cout << "\n Elements in the queue: ";
	queue.display();

	std::cout << "Deleting elements in queue: " <<std::endl;

	// Dequeue 5 times and display (so 3 data will be remained)

	for (int i = 0; i < 5; i++)
        std::cout << queue.Dequeue()<<" ";

	std::cout << std::endl << "Elements in the queue after deletion: ";
	queue.display();

	// Add 6 more data (so 9 data will be remained)

	for (int i = 0; i < 6; i++)
        queue.Enqueue(10 + i);

	 // print all data of the queue

	std::cout << "\nElements in the queue after addition: ";
	queue.display();

	while (!queue.IsEmpty())
		std::cout << queue.Dequeue()<<" ";

	std::cout << std::endl << "Elements in the queue after deletion of all elements: ";
	queue.display();
	queue.Dequeue(); //test statement to check wether queue is empty or not

	return 0;
}

