/*---------------------------------------------------------------------------------------
  Name:Mayur Sanjay Potdar
  Date: 3/9/2016
  CWID: 50155714
  Title: Linked list over the stack
----------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

struct Stack//created stack strucute
{
    int ndata;
    int nvalue;
    struct Stack * next;
} * start_value = NULL;



void stack_push(Stack *pList, int nData)// PuSh_vaLUes__in-STACK.
{
    int n_num;
    cout<<"ProVide the number of inputs you want to enter into the stack ? :\t";
    cin>>n_num;
    cout << "\nEnter the "<<  n_num <<" values in stack :-\n" ;
    for (int i=1;i<=n_num;i++)
    {
        struct Stack * new_node = new Stack;
        struct Stack * curr;
        curr = start_value;

        cin >> new_node->ndata;
        new_node->next = NULL;
        struct Stack *n_temp1=new_node;

        if(start_value==NULL)
        {
            start_value=n_temp1;
            curr=n_temp1;
        }
        else
        {
            n_temp1->next=start_value;
            start_value=n_temp1;
        }
     }
}

void stack_display(Stack *ptr)
{
    int i = 1;
    struct Stack * ncurr_val;
    ncurr_val = start_value;

    if(ncurr_val==NULL)//To check the linked list is empty or not
    {
        cout << "Stack Empty - nothing to display....!!! \n\n";
    }
    cout<<"---------****************---------------------****************-------------\n";
    while(ncurr_val!= NULL)//will find the whole linked list till the end of the node by NULL value
    {
        cout<<"["<<ncurr_val->ndata<<"]  |  ";
        ncurr_val = ncurr_val->next;
        i++;
    }
    cout<<"\n---------****************---------------------****************-------------\n";
    cout <<endl;
}

void pop_all(Stack *ptr)// Delete stack one by one
{
    struct Stack *n_temp;

    if(start_value==NULL)
    {
        cout<<"StaCk_EmPty"<<endl;
    }
    n_temp =start_value;
    start_value = start_value->next;
    delete n_temp;
    stack_display(ptr);
}


int main()
{
    int n_number;
    int nData ;
    do
    { // asking for user choice using switch case
    cout <<endl;
    cout << "1] Push to the_staCk \n";
    cout << "2] DiSpLay the_staCk  \n";
    cout << "3] Pop one_element at_a-tiMe \n";
    cout << "0] StAcK-EXIT" ;
    cout<<"\n\n  PaSS_yOur_ch0ice_optin :- \t";
    cin >> n_number;

    switch (n_number)
    {

        case 1:
            stack_push(start_value,nData); //calling  first linked list add function
        break;

        case 2:
            stack_display(start_value); //calling display function
        break;

        case 3:
            pop_all(start_value); //calling freeAll function
            break;
        }

    } while (n_number!=0);

    return 0;
}
