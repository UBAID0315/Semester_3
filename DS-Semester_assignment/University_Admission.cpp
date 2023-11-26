#include<iostream>
#include<stdlib.h>
using namespace std;

class Student
{
    public:
        string name;
        int merit;
        Student *next;

        Student(string name,int merit)
        {
            this->name = name;
            this->merit = merit;
            next = nullptr;
        }
};

class Queue
{
    private:
        Student *front;
        Student *rear;
        int length;
        int capacity;
    public:
        Queue()
        {
            front = nullptr;
            rear = nullptr;
            length = 0;
            capacity = 0;
        }
        int getlength()
        {
            return length;
        }
        void Enqueue(string name,int merit)
        {
            Student *newStudent = new Student(name,merit);

            if (length == 0)
            {
                rear = newStudent;
                front = rear;
            }
            else
            {
                rear->next = newStudent;
                rear = newStudent;
            }
            length++;
        }
        int Dequeue()
        {
            if (length == 0)
            {
                return 0;
            }
            
            Student *temp = front;
            front = front->next;
            if (front == nullptr)
            {
                rear = nullptr;
            }
            length--;
            delete temp;
            return 1;
        }

        Student* getfront() const 
        {
            if (front != nullptr) 
            {
                return front;
            }
            return nullptr;
        }
        int Process_Admission()
        {
            int merit = front->merit;

            cout<<"Processing Student Name: "<<front->name<<endl<<"Processing Student Merit: "<<front->merit<<endl;
            Student *temp = front;
            front = front->next;
            if (front == nullptr)
            {
                rear = nullptr;
            }
            length--;
            delete temp;
            return merit;
        }
        Student* peek_value() const 
        {
            if (length != 0) 
            {
                return front->next;
            } 
            else 
            {
                return NULL;
            }
        }
};

void checkingQueue(Queue queue[],string name,int merit)
{    
    if (queue[0].getlength() < queue[1].getlength() && queue[0].getlength() < queue[2].getlength())
    {
        queue[0].Enqueue(name,merit);
    }
    else if(queue[1].getlength() < queue[0].getlength() && queue[1].getlength() < queue[2].getlength())
    {
        queue[1].Enqueue(name,merit);
    }
    else if (queue[2].getlength() < queue[0].getlength() && queue[2].getlength() < queue[1].getlength())
    {
        queue[2].Enqueue(name,merit);
    }
    else
    {
        int random;
        srand(time(nullptr));
        random = (rand() % 3)+1;
        
        queue[random-1].Enqueue(name,merit);
    }
}
int main()
{
    int choose,merit,number;
    string name;
    Queue queue[3];

    while (true)
    {
        cout<<endl<<"Choose the option from below: "<<endl;
        cout<<"1. Add a student to Queue"<<endl;
        cout<<"2. Process Admission"<<endl;
        cout<<"3. Check the Queue Status"<<endl;
        cout<<"4. See who's is next"<<endl;
        cout<<"5. Exit"<<endl<<endl;
        cout<<"Enter your Option: ";
        cin>>choose;
        if (choose == 1)
        {
            cout<<"Enter Student's Name: ";
            cin>>name;
            cout<<"Enter Student's Merit: ";
            cin>>merit;

            checkingQueue(queue,name,merit);
        }
        else if (choose == 2)
        {
            cout<<"Enter the Queue Number to process: ";
            cin>>number;

            cout<<endl<<"Processing Admission for Selected Queue "<<number + 1<<endl<<endl;
            int merit = queue[number - 1].Process_Admission();
            if (merit >= 50)
            {
                cout<<endl<<"Congratulations! you got the Admission"<<endl<<endl;
            }
            else
            {
                cout<<endl<<"Oops! you got rejected for admission"<<endl<<endl;
            }
        }
        else if (choose == 3)
        {
            for (int i = 0; i < 3; i++)
            {
                cout<<"Length of Queue "<<i+1<<": "<<queue[i].getlength()<<endl;
            }
            for (int i = 0; i < 3; i++)
            {
                if (queue[i].getfront() != nullptr)
                {
                    cout<<endl<<"0-----( Data of Queue "<<i+1<<" )-----0"<<endl<<endl;
                }
                Student *temp = queue[i].getfront();
                while (temp != nullptr)
                {
                    cout<<"Name: "<<temp->name<<"\t"<<"Merit: "<<temp->merit<<endl;
                    temp = temp->next;
                }
            }
        }
        else if (choose == 4)
        {

            cout<<"Enter the Queue number: ";
            cin>>number;
            Student *nextStudent = queue[number-1].peek_value();

            cout<<endl<<"Next Student in the Selected Queue"<<endl<<endl;
            if (nextStudent != nullptr)
            {
                cout<<"Student Name: "<<nextStudent->name<<endl;
                cout<<"Student Merit: "<<nextStudent->merit<<endl;
            }
            else 
            {
                cout<<"No more student left in the queue"<<endl;
            }
        }
        else if (choose == 5)
        {
            cout<<endl<<"Closing the Program"<<endl<<endl;
            break;
        }
    }
}