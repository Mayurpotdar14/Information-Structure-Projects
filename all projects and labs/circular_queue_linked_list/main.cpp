#include<iostream>
#include<queue>//Queue header file for queue operations
using namespace std;

class cirlist
{
private:
    struct Q_node
    {
        int nvalue;
        struct Q_node *pnext;
    }*nfront,*nrear;

    int nposition;

public:
    cirlist()
    {
        nfront=nrear=NULL;
        nposition = 0;
    }

    void Enqueue(int nvalue)
    {
        Q_node *pBase = new Q_node;
        pBase->nvalue = nvalue;
        pBase->pnext = NULL;

        if(nrear != NULL)
            nrear->pnext = pBase;
        else
            nfront = pBase;

        nrear = pBase;
        nposition ++;
        cout<<" "<<nvalue<<" ";
    }

    int Dequeue()
    {

        if (IsEmpty())//Check for queue level with IsEmpty function for values present in queue
        {
           cout << "Queue_IS_empty :-----> (No)" << endl;
           return 0;
        }

    int nItem_value;
    Q_node *ptemp = new Q_node ;
    ptemp = nfront->pnext;
    nItem_value = nfront->nvalue;

    delete nfront;

    nfront = ptemp;
    nposition --;

    if(nposition == 0)
            nrear = NULL;

    return nItem_value;
    }

    int IsEmpty()//Check_individual_element_for_deletion+from_Linked_quueue
    {
        if(nposition > 0 )//Element position #counter
            return 0;
        else
            return 1;
    }

   ~cirlist()//Destroctor
    {
        Q_node *pBase = new Q_node;
        pBase = nfront;
        while(pBase != NULL)
        {
            Q_node *pnext = pBase->pnext;
            delete pBase;
            pBase = pnext;
        }
        nfront = NULL;
        nrear = NULL;
        nposition = 0;
    }
};

int main (void)
{
    cirlist queu;
    // declaration of Queue
    // Add 8 data
    cout<<"\nInitial_List :- ";
    for (int i = 0; i < 8; i++)//Adding initial elements in the queue with fix range
        queu.Enqueue(i);

    cout<<"\n"<<endl;
    cout<<"First_five_Deleted_Elements :-  "; // Dequeue 5 times and display (so 3 data will be remained)

    for (int i = 0; i < 5; i++)//Call_dequeue_for [for loop]
        cout << queu.Dequeue()<< " ";

    cout<<"\n"<<endl;
    cout<<"New_added_elements_are with_new_variable : - ";   // Add 6 more data (so 9 data will be remained)

    for (int i = 0; i < 6; i++)
        queu.Enqueue(10 + i);

    cout<<"\n\nElemnt_deleted_one_by_one_are :- ";
    while (!queu.IsEmpty())//Delete  & Print #all elements #one by #one
        cout << queu.Dequeue() << " ";

    cout<<"\n";
    return 0;
}
