#include<iostream>
using namespace std;

class Node
{
    public:
        char data;
        Node *next;

        Node(char value)
        {
            data = value;
            next = nullptr;
        }
};

class Stack
{
    private:
        Node *top;
        int length;
    public:
        Stack()
        {
            length = 0;
            top = nullptr;
        }
        bool isEmpty()
        {
            return top == nullptr;
        }    
        char peek_value()
        {
            if (!isEmpty())
            {
                return top->data;
            }
            else
            {
                cout<<"Nothing in the disk"<<endl;
                return ' ';
            }
        }
        void push(char value)
        {
            Node *newNode = new Node(value);
            if (length == 0)
            {
                top = newNode;
            }
            else
            {
                newNode->next = top;
                top = newNode;
            }
            length++;
        }
        char pop()
        {
            if (isEmpty())
            {
                cout<<"Stack Underflow"<<endl;
                return ' ';
            }
            Node *temp = top;
            char value = top->data;
            top = top->next;
            delete temp;
            length--;
            return value;
        }
};

class Tower
{
    private:
        Stack pegs[3];
        int total_disk;
        int no_of_steps;
    public:
        Tower(int disks)
        {
            total_disk = disks;
            no_of_steps = 0;

            for (char i = ('A' + disks - 1); i >= 'A'; i--)
            {
                pegs[0].push(i);
            }
        }
        void moveDisks(int Disk_number,int start_rod,int between_rod,int end_rod)
        {
            if (Disk_number > 0)
            {
                moveDisks(Disk_number-1, start_rod, end_rod, between_rod);
                
                if (!pegs[start_rod].isEmpty() && pegs[end_rod].isEmpty() || pegs[start_rod].peek_value() < pegs[end_rod].peek_value())
                {
                    int disk = pegs[start_rod].pop();
                    pegs[end_rod].push(disk);
                    no_of_steps++;
                    cout<<"Move the Disk from "<< static_cast<char>('A'+start_rod)<<" to "<<static_cast<char>('A'+end_rod)<<endl;
                }
                
                moveDisks(Disk_number-1,between_rod,start_rod,end_rod);
            }
        }
        int getSteps()
        {
            return no_of_steps;
        }
};

int main()
{
    int numberdisk;

    cout<<"Enter the disks: ";
    cin>>numberdisk;

    Tower tower(numberdisk);
    tower.moveDisks(numberdisk,0,1,2);
    cout<<"Total number of steps: "<<tower.getSteps();
}