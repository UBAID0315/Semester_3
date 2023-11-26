#include<iostream>
// #include<ctime>
using namespace std;

class Puzzle
{
    private:
        char *arr;
        char *curr = NULL;          
        int length;      // means number of data enter

    public:
        // void setarray(string name)
        // {
        //     srand(time(NULL));
        //     for (int i = 0; i < 6; i++)
        //     {
        //         arr[i] = name[i];
        //     }
        //     for (int i = 0; i < 6; i++)
        //     {
        //         name[i] = arr[rand() % 6];
        //     }
        // }
        Puzzle()
        {
            arr = new char[6];
            length = 0;
            curr = arr;
        }
        ~Puzzle()
        {
            delete []arr;
        }
        void head()
        {
            curr = arr;
        }
        void tail()
        {
            curr = arr + length - 1;
        }
        void next()
        {
            curr++;
        }
        void back()
        {
            curr--;
        }
        void insert(int pos,char val)
        {
            if (length == 6)
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
        void remove(int pos)
        {
            if (length == 0)
            {
                cout<<"Nothing is in list to remove"<<endl;
            }
            if (pos < 1 || pos > length)
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
        int getlength()
        {
            return length;
        }
        void print()
        {
            head();
            for (int i = 1; i <= length; i++)
            {
                cout<<*(curr)<<" ";
                next();
            }
        }
        void check()
        {
            int choose,pos;
            char val;
            string name = "";

            for (int i = 0; i < 5; i++) 
            {
                name = name + arr[i];
            }
            while(name == "ubaid")
            {

                print();    
                cout<<endl;
                cout<<"Choose your option: "<<endl;
                cout<<"1. Insert"<<endl;
                cout<<"2. Remove"<<endl;
                cin>>choose;

                if (choose == 1)
                {
                    cout<<"Enter value you want to put";
                    cin>>val;
                    cout<<"Enter position where you want to put ";
                    cin>>pos;

                    insert(pos,val);
                }
                else if(choose == 2)
                {
                    cout<<"Enter position where you want to put ";
                    cin>>pos;

                    remove(pos);            
                }
            }
        }
};

int main()
{
    Puzzle P;

    // cout<<"Enter your name: ";
    // cin>>name;
    // P.setarray(name);

    P.insert(1,'u');
    P.insert(2,'b');
    P.insert(3,'a');
    P.insert(4,'i');
    P.insert(5,'d');

    P.check();
}
