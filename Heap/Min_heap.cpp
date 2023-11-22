#include <iostream>
#include <vector>
using namespace std;

class Patient {
public:
    string name;
    int urgency;

    Patient()
    {
        name = "";
        urgency = 0;
    }
    Patient(string name, int urgency) {
        this->name=name;
        this->urgency=urgency;
    }
};

class Heap {
public:
    vector<Patient> htree;

    int getParent(int child) 
    {
        return (child-1)/2;
    }

    int getLeft(int parent) 
    {
        return (2*parent)+1;    
    }

    int getRight(int parent) 
    {
        return (2 * parent) + 2;
    }

    void swap(int a, int b) 
    {
        Patient temp = htree[a];
        htree[a] = htree[b];
        htree[b] = temp;
    }

    void heapifyUp(int index) 
    {
        while (index > 0 && htree[index].urgency < htree[getParent(index)].urgency) 
        {
            swap(index, getParent(index));
            index = getParent(index);
        }
    }

    void heapifyDown(int index) 
    {
        int left = getLeft(index);
        int right = getRight(index);
        int smallest = index;

        if (left < htree.size() && htree[left].urgency < htree[smallest].urgency)
        {
            smallest = left;
        }
        
        if (right < htree.size() && htree[right].urgency < htree[smallest].urgency)
        {
            smallest = right;
        }
        
        if (smallest != index)
        {
            swap(smallest,index);
            heapifyDown(smallest);
        }
    }

    void del() 
    {
        if (htree.empty())
        {
            cout<<"Nothing to Delete"<<endl;
        }
        else
        {
            swap(0,htree.size() - 1);
            htree.pop_back();
            heapifyDown(0);
        }
        
    }
    void updateUrgency(string patientName, int newUrgency) 
    {
        for (int i = 0; i < htree.size(); i++)
        {
            if (htree[i].name == patientName)
            {
                htree[i].urgency = newUrgency;
            }
            
            if (newUrgency < htree[getParent(i)].urgency)
            {
                heapifyUp(i);
            }
            else
            {
                heapifyDown(i);
            }
        }
    }
    void insert(Patient patient) 
    {
        htree.push_back(patient);  
        heapifyUp(htree.size() - 1);  
    }

    void display() {
        if (htree.empty()) 
        {
            cout << "No appointments to display." << endl;
            return;
        }
        cout << "Current Appointments:" << endl;
        for (int i = 0; i < htree.size(); i++) 
        {
            cout << "Name: " << htree[i].name << ", Urgency: " << htree[i].urgency << endl;
        }
        cout<<endl;
    }
};

int main() {
    Heap priorityQueue;
    int choose,urgency;
    string name;
    
    while (true)
    {
        cout<<"Choose the option below: "<<endl;
        cout<<"1. Insert the Patient's Details"<<endl;
        cout<<"2. Delete the Patient's Record"<<endl;
        cout<<"3. Update the Patient's Urgency"<<endl;
        cout<<"4. Display the Patient's Details"<<endl;
        cout<<"5. See who's Next"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your option: ";
        cin>>choose;
        if (choose == 1)
        {
            cout<<"Enter Patient's Name: ";
            cin>>name;
            cout<<"Enter Patient's Urgency: ";
            cin>>urgency;

            Patient patient(name,urgency);

            priorityQueue.insert(patient);
        }
        else if (choose == 2)
        {
            priorityQueue.del();
        }
        else if (choose == 3)
        {
            cout<<"Enter Patient's Name: ";
            cin>>name;
            cout<<"Enter Patient's Urgency: ";
            cin>>urgency;
            
            priorityQueue.updateUrgency(name,urgency);
        }
        else if (choose == 4)
        {
            priorityQueue.display();
        }
        else if (choose == 5)
        {
            priorityQueue.del();
            priorityQueue.display();
        }
        else if (choose == 6)
        {
            cout<<endl<<"Closing the program"<<endl;
            break;
        }
        else
        {
            cout<<"Invalid Option choose btw (1-5)"<<endl;
        }
    }
    
    return 0;
}
