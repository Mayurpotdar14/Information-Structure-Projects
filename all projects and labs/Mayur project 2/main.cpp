
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

#define HASHTABLE_SIZE 100

class HashMap
{
	HashMap *hashtable[HASHTABLE_SIZE];

	public:
	//public:
    	string key;			// Key, should be unique
        string value;       // Data, mapping to the key.
        class HashMap *pNext = NULL;  // pointer to the next node
		// constructor
		HashMap()
		{
			memset(hashtable, 0, sizeof(hashtable));
		}

		~HashMap()
		{
			HashMap *pNode = NULL;
			for (int i = 0; i < HASHTABLE_SIZE; i++)
				if ((pNode = hashtable[i]) != NULL)
					delete pNode;
		}


		// Add the key or update it.
		void install(string key, string value)
		{
			HashMap *pNode = NULL;
			// if no data of the key
			if ((pNode = lookup(key)) == NULL)
			{
				pNode = new HashMap;
				pNode->key = key;
				// add to front of linked list
				unsigned i = hashfunc(key);
				pNode->pNext = hashtable[i];
				hashtable[i] = pNode;
			}

			pNode->value = value;
		}

		// retrieve a value of the key
		string getvalue(string key)
		{
			HashMap *pNode = lookup(key);
			if (pNode == NULL)
				return "No Data Given";

			return pNode->value;
		}


		// compute index of the key in the hashtable
		unsigned int hashfunc(string key)
		{
			unsigned int nIndex = 0;
			for (int i = 0; i < key.length(); i++)
				nIndex = nIndex * 65599 + key[i];
			return nIndex % HASHTABLE_SIZE;
		}

		// find the data of the key
		HashMap *lookup(string key)
		{
			HashMap *pNode = NULL;
			for (pNode = hashtable[hashfunc(key)]; pNode != NULL; pNode = pNode->pNext)
				if (key.compare(pNode->key) == 0)
				return pNode;
			return NULL;
		}

		// deallocate memory space of the base pointer
		void deallocate(HashMap *pNode)
		{
			HashMap *pIter = pNode;
			while (pIter != NULL)
            {
                HashMap *pNext = pIter->pNext;
                delete pIter;
                pIter = pNext;
            }
		}

    int readfromfile(HashMap *start_value)//Read each value from file to passed it to the add() functions
    {
        char nvalue;
        ifstream file1;
        file1.open("data.txt");//;,iso::out,iso::binary);
        cout<<file1<<nvalue<<endl;
        cout<<"start\n";
         start_value = createlinkedlist(start_value,nvalue);
        while(file1.open("data.txt"))
        {
           start_value = createlinkedlist(start_value,nvalue);//call function for every value
        }
        cout<<"end\n";
    }

    HashMap* createlinkedlist(HashMap *start_value, char value)
    {
    HashMap *ntemp = new HashMap;
    ntemp->value = value;
    ntemp->pNext = NULL;
    if(start_value == NULL)//check for the first value in the linked list.
    {
        start_value = ntemp;
        return start_value;
    }
    else//Check for the entire linked list and add it to the function to calculate the value
    {
        HashMap *ncurr;
        ncurr = start_value;
        while(ncurr->pNext!=NULL)
        {
            ncurr = ncurr->pNext;
        }
        ncurr->pNext=ntemp;
        return start_value;
    }
}

};

int main(void)
{
    HashMap map;
    map.install("100", "One hundred");
    map.install("200", "Two hundred");
    map.install("200", "Two zero zero");
    std::cout << map.getvalue("100") << std::endl;
    std::cout << map.getvalue("200") << std::endl;

    return 0;
}
