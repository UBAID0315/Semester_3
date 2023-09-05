#include<iostream>
using namespace std;

class list
{
    private:
        int *arr;
        int *curr;
        int length;
        int capacity;
    public:
        list();
         ~list();

        void tail();                         // jump pointer directly to end of list
        void head();                    // jump pointer diretly to start of list
        void back();                // one step pointer back
        void next();            // one step pointer forward

        void Clear();
        void SortedInsert(int val);
        void Insert(int val, int pos);          // val is for taking value && pos is for the position taken
        void Remove(int pos);
        int Get(int pos);
        void Update(int val,int pos);
        int Find(int val);
        int Length();
        void CreateList();
        void Print();
        void Copy();

};
// -------------------------------------------------
list::list()
{
    length = 0;
}
list::~list()
{
	delete []arr;
}
// -------------------------------------------------
void list::tail()
{
    curr = arr + length - 1;
}
void list::back()
{
    curr--;
}
void list::next()
{
    curr++;
}
void list::head()
{
    curr = arr;
}
// -------------------------------------------------
void list::Copy()
{
    int *second;

    second = new int[capacity];
    for (int i = 0; i <= length; i++)
    {
        second[i] = arr[i];
    }
    for (int i = 0; i <= length; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
void list::CreateList()
{
    cout<<"Enter the capacity of list: ";
    cin>>capacity;

    arr = new int[capacity];
    for (int i = 1; i <= capacity; i++)
    {
        arr[i] = 0;
    }
    
    curr = arr;
}
void list::SortedInsert(int val)
{
    for (int i = 0; i < capacity - 1; ++i) 
    {
        for (int j = 0; j < capacity - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                // Swap the elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int i;
    if(capacity == length)
    {
        cout<<"Full"<<endl;
    }
    head();
    for(i=1 ; i<=length-1 ; i++ )
    {
        next();
    }
    if (*curr > val)
    {
        *(curr+1) = *curr;
        back();// Insert(val,i);
        *(curr+1)= val;
    }
}
void list::Clear()
{
    length = 0;
}
void list::Insert(int val, int pos)
{
	
    if (length == capacity)
    {
        cout<<"The list size is already FULL"<<endl;   
    }
    if (pos < 1 || pos > length+1)
    {
        cout<<"Invalid position entered"<<endl;
    }
    if (pos >= 1 || pos <= length)
    {
        tail();
        for (int i = length; i >= pos; i--)
        {
            *(curr+1) = *curr;
            back();
        }
        *(curr+1) = val;
        length++;
    }
}
void list::Remove(int pos)
{
    if (length == 0)
    {
        cout<<"Nothing is in list to remove"<<endl;
    }
    if (pos < 1 || pos > length + 1)
    {
        cout<<"Invalid position"<<endl;
    }
    if (pos >= 1 || pos <= length)
    {
        curr = arr + pos - 1;

        for (int i = pos; i <= length; i++)
        {
            *curr = *(curr + 1);
            next();        
        }        
        length--;
    }
}
int list::Get(int pos)
{
    curr = arr + pos - 1;
    return *curr;
}
int list::Find(int val)
{
    if (length == 0)
    {
        cout<<"Nothing is in list to find(empty)"<<endl;
    }
    head();
    for (int i = 1; i < length; i++)
    {
        if (val == *curr)
        {
            return i;
        }
        next();
    }
}
void list::Update(int val,int pos)
{
    if (length == 0)
    {
        cout<<"Nothing is in list to remove"<<endl;
    }
    if (pos < 1 || pos > length + 1)
    {
        cout<<"Invalid position"<<endl;
    }
    if (pos >= 1 || pos <= length)
    {
        *curr = Get(pos);
        *curr = val;
    }
}
int list::Length()
{
    return length;
}
void list::Print()
{
	head();
	for(int i=1 ; i <= length ; i++)
	{
		cout<<*curr<<" ";
		curr++;
	}
}

int main()
{
    list List;
    int val,get_value;

    List.CreateList();

    List.Insert(4,1);
    List.Insert(1,2);
    List.Insert(11,3);
    List.Insert(6,4);

    List.SortedInsert(8);
    
    List.Copy();
}
