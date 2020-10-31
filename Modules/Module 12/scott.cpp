#include <fstream>
#include<iostream>
#include<string>

using namespace std;

    struct RecType///struct used for searches and adding
    {
        int studentID;
        string fName;
        string lName;
    };


class StudentHT
{
private:
    int hashFunc(int idNum)///hash function
    {
        return idNum%TABLE_SIZE;
    }

public:
    int idSearches;
    int nodeSearches;
    double avgSearches;
    int TABLE_SIZE;
    struct NodeType///struct that holds data in hash table
    {
        int studentID;
        string fName;
        string lName;
        NodeType * next;
    };
    NodeType** hashPtr;
     StudentHT(int SIZE)
     {
         TABLE_SIZE = SIZE;
         hashPtr = new NodeType*[SIZE];
         for (int i = 0; i < SIZE; i++)
         {
             hashPtr[i] = nullptr;
         }
     }
     ~StudentHT()
     {
            for (int i = 0; i < TABLE_SIZE; ++i)
            {
                NodeType* entry = hashPtr[i];
                while (entry != NULL)
                {
                    NodeType* prev = entry;
                    entry = entry->next;
                    delete prev;
                }
            }
            delete[] hashPtr;
     }
     void insert (RecType item)///Inserts an item into the Hash Table
     {
        int bucket = hashFunc(item.studentID); ///create hash key for entry

        struct NodeType * newItem = new struct NodeType;///load new Node with data
        newItem->studentID = item.studentID;
        newItem->fName = item.fName;
        newItem->lName = item.lName;
        newItem->next = nullptr;

        if (hashPtr[bucket] == nullptr)///if first location in hash table is empty, enter data
        {
           hashPtr[bucket] = newItem;

        }
        else///move cursor forward until open data spot is found
        {
            struct NodeType *temp = hashPtr[bucket];
            while (temp->next != NULL)
           {
               temp = temp->next;
           }
           temp->next = newItem;
        }


     }//void insert
     RecType search(RecType item)///Will search an item in hash table and will return it. If not found will return an item containing -1 for id.
     {
        idSearches++;
        int bucket = hashFunc(item.studentID); ///create hash key for search

        RecType *target = new RecType;
        if (hashPtr[bucket] != nullptr)///if first location in hash table is NOT empty
        {
            struct NodeType *temp = hashPtr[bucket];
            while (temp !=nullptr)
            {
                nodeSearches++;
                if (temp->studentID == item.studentID)///when the entry is found, return the target
                {
                    target->studentID = temp->studentID;
                    target->fName = temp->fName;
                    target->lName = temp->lName;
                    return *target;
                }//if temp
                temp =temp->next;
            }//while !nullptr
        }//if
        target->studentID =-1;
        return *target;
     }//Rectyppe search




     void startStatistics();
     void endStatistics();
     void displayStatistics();
};


int main()
{
    string fileName = "Add.txt";
    string searchTxt = "Search.txt";
    int i;
    StudentHT hashish(100);///create a hash table with this amount of entries

    hashish.startStatistics();

    fstream inputFile;
    inputFile.open(fileName.c_str(), ios::in);

    if (inputFile.is_open()) ///initial loading from master file into hash
    {
        while(!inputFile.eof())
        {
            RecType alpha;
            inputFile >> alpha.studentID;
            alpha.fName = "Mark";   ///because there are no names in the files, we use this to fill the data
            alpha.lName = "Samples";

            hashish.insert(alpha);
        }
        inputFile.close();
    }
    else
    cout << "File 'Add' cannot be opened.";

    inputFile.open(searchTxt.c_str(), ios::in);
    if (inputFile.is_open()) ///Search time!
    {
        while(!inputFile.eof())
        {
            RecType beta;
            inputFile >> beta.studentID;
            beta.fName = "Mark";    ///because there are no names in the files, we use this to fill the data
            beta.lName = "Samples";

            hashish.search(beta);

        }
        inputFile.close();
    }
    else
    cout << "File 'Search' cannot be opened.";

    hashish.endStatistics();
    hashish.displayStatistics();

}


void StudentHT::startStatistics()///initializeds statistics to zero
{
     idSearches = 0;
     nodeSearches = 0;
     avgSearches = 0;
}
void StudentHT::endStatistics()///calculates average
{
    avgSearches = (double)nodeSearches/idSearches;
}
void StudentHT::displayStatistics()
{
    cout << "Total Number Of ID'S Searched: " << idSearches << endl;
    cout << "Total Number Of Nodes Searched: " << nodeSearches << endl;
    cout << "Average Of Nodes Searched Per ID: " << avgSearches << endl;
}




