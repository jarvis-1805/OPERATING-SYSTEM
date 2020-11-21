#include <iostream>
#define MAX 100

using namespace std;

class memory_allocation
{
    private:
        int ch;
        int noProcess, noPartition;
        int internalFrag, externalFrag;
        int partition[MAX];
        int process[MAX];
        int flag[MAX];
    
    public:
        memory_allocation();

        void options();
        int choice();
        void choice_calling(int);

        void first_fit(int *, int *);
        void best_fit(int *, int *);
        void worst_fit(int *, int *);
        void fragmentation(int);
};

memory_allocation::memory_allocation()
{
    noProcess = 0;
    noPartition = 0;
    internalFrag = 0;
    externalFrag = 0;
    ch = 0;
    cout << "\n======== MEMORY ALLOCATION ========\n";
    cout << "\nEnter the number of memory partition space: ";
    cin >> noPartition;
    for(int i=0; i<noPartition; i++)
    {
        cout << "Enter size of memory partition " << i+1 << ": ";
        cin >> partition[i];
    }

    cout << "\nEnter no. of processes: ";
    cin >> noProcess;
    for(int i=0; i<noProcess; i++)
    {
        cout << "Enter size of process " << i+1 << ": ";
        cin >> process[i];
    }
}

void memory_allocation::options()
{
    cout << "\n====== MENU ======\n";
    cout << "1: FIRST FIT"
        << "\n2: BEST FIT"
        << "\n3: WORST FIT"
        << "\n0: EXIT" << endl;
}

int memory_allocation::choice()
{
    cout << "\nEnter your choice: ";
    cin >> ch;

    return ch;
}

void memory_allocation::choice_calling(int ch)
{
    int copyPartition[noPartition], copyProcess[noProcess];
    switch(ch)
    {
        case 1:
            for(int i=0; i<noPartition; i++)
                copyPartition[i] = partition[i];
            for(int i=0; i<noProcess; i++)
            {
                copyProcess[i] = process[i];
                flag[i] = 0;
            }
            internalFrag = 0;
            externalFrag = 0;
            first_fit(copyPartition, copyProcess);
            break;
        case 2:
            for(int i=0; i<noPartition; i++)
                copyPartition[i] = partition[i];
            for(int i=0; i<noProcess; i++)
            {
                copyProcess[i] = process[i];
                flag[i] = 0;
            }
            internalFrag = 0;
            externalFrag = 0;
            best_fit(copyPartition, copyProcess);
            break;
        case 3:
            for(int i=0; i<noPartition; i++)
                copyPartition[i] = partition[i];
            for(int i=0; i<noProcess; i++)
            {
                copyProcess[i] = process[i];
                flag[i] = 0;
            }
            internalFrag = 0;
            externalFrag = 0;
            worst_fit(copyPartition, copyProcess);
            break;
        case 0:
            exit(0);
        default:
            cout << "\nINVALID CHOICE!\n";
    }
}

void memory_allocation::first_fit(int *partition, int *process)
{
    for(int i=0; i<noProcess; i++)
    {
        for(int j=0; j<noPartition; j++)
        {
            if(process[i] <= partition[j])
            {
                cout << "\nProcess of size " << process[i] << " unit is mapped to partition of: " << partition[j] << " unit.";
                internalFrag += partition[j] - process[i];
                partition[j] = 0;
                flag[i] = 1;
                break;
            }
        }
        if(flag[i] == 0)
        {
            cout << "\nThere is no memory partition available for process having size: " << process[i];
        }
    }

    fragmentation(internalFrag);
}

void memory_allocation::best_fit(int *partition, int *process)
{
    int temp = 0;
    for(int i=0; i<noPartition; i++)
    {
        for(int j=i+1; j<noPartition; j++)
        {
            if(partition[j] < partition[i]) 
            {
                temp = partition[i];
                partition[i] = partition[j];
                partition[j] = temp;
            }
        }
    }
    for(int i=0; i<noProcess; i++)
    {
        for(int j=0; j<noPartition; j++)
        {
            if(process[i] <= partition[j])
            {
                cout << "\nProcess of size " << process[i] << " unit is mapped to partition of: " << partition[j] << " unit.";
                internalFrag += partition[j] - process[i];
                partition[j] = 0;
                flag[i] = 1;
                break;
            }
        }
        if(flag[i] == 0)
        {
            cout << "\nThere is no memory partition available for process having size: " << process[i];
        }
    }
    
    fragmentation(internalFrag);
}

void memory_allocation::worst_fit(int *partition, int *process)
{
    int temp, flag1 = 1;
    for(int i = 1; (i <= noPartition) && flag1; i++)
    {
        flag1 = 0;
        for (int j=0; j<(noPartition -1); j++)
        {
            if (partition[j+1] > partition[j]) 
            { 
                temp = partition[j];     
                partition[j] = partition[j+1];
                partition[j+1] = temp;
                flag1 = 1;  
            }
        }
    }
    for(int i=0; i<noProcess; i++)
    {
        for(int j=0; j<noPartition; j++)
        {
            if(process[i] <= partition[j])
            {
                cout << "\nProcess of size " << process[i] << " unit is mapped to partition of: " << partition[j] << " unit.";
                internalFrag += partition[j] - process[i];
                partition[j] = 0;
                flag[i] = 1;
                break;
            }
        }
        if(flag[i] == 0)
        {
            cout << "\nThere is no memory partition available for process having size: "<< process[i];
        }
    }
    
    fragmentation(internalFrag);
}

void memory_allocation::fragmentation(int internalFrag)
{
    for(int i=0; i<noPartition; i++)
    {
        if(partition[i] != 0)
        {
            externalFrag += partition[i];
        }
    }
    cout << "\nInternal fragmentation is: " << internalFrag;
    cout << "\nExternal fragmentation is: " << externalFrag;
    cout << endl;
}

int main()
{
    int choice;
    memory_allocation ob;
    do
    {
        ob.options();
        choice = ob.choice();
        ob.choice_calling(choice);
    }while(1);

    return 0;
}