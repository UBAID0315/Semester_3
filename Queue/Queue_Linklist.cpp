#include<iostream>
using namespace std;

class Node
{
    public:
        Node *next;
        int data;

        Node(int val)
        {
            data = val;
            next = NULL;
        }
};
class Queue
{
    public:

        Queue(int size)
        {
            length = 0;
            head = NULL;
            front = NULL;
            rear = NULL;
            capacity = size;
        }
        void push(int val)
        {
            Node *newNode = new Node(val);

            if (length == 0)
            {
                rear = newNode;
                head = rear;
                front = head;
            }
            else
            {
                rear->next = newNode;
                rear = rear->next;
            }
            length++;
        }
        int pop()
        {
            int val = front->data;

            Node *temp = front;

            front = front->next;
            temp->next = NULL;
            delete temp;
            
            length--;
            return val;
        }

    private:

        int length;
        Node *head;
        Node *front;
        Node *rear;
        int capacity;

};

int main()
{
    Queue Q(6);

    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);
    Q.push(6);

    cout<<"pop value: "<<Q.pop();
}