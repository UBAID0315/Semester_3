#include<iostream>
using namespace std;

struct Trunk 
{
    Trunk* prev;
    string str;

    Trunk(Trunk* prev, string str) {
        this->prev = prev;
        this->str = str;
    }
};

class Node
{
    public:
        int data;
        string G_name;
        Node *left;
        Node *right;

        Node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};

class Binary_Tree
{
    private:
        Node *root;
        int value;
        int bag_capacity;
    public:
        Binary_Tree()
        {
            root = NULL;
            value = 0;
            bag_capacity = 0;
        }
        ~Binary_Tree()
        {
            deletetree(root);
            cout<<"Tree deleted successfully"<<endl;
        }
        void deletetree(Node *root)
        {
            if (root == NULL)
            {
                cout<<"Nothing in the tree to delete"<<endl;
            }
            if(root->left != NULL)
            {
                deletetree(root->left);
            }
            if (root->right != NULL)
            {
                deletetree(root->right);
            }
            
            delete root;
            cout<<endl;
        }
        void Insert(string gem_name,int val)
        {
            root = insert(root,val,gem_name);
        }
        void PrintInOrder()
        {
            InOrder(root);
        }
        void PrintPostOrder()
        {
            PostOrder(root);
        }
        void PrintPreOrder()
        {
            PreOrder(root);
        }
        void Find_Gem()
        {
            Node *Maximum = find_highest_gem(root);
            
            cout<<"Gem of Highest power: "<<Maximum->G_name<<": "<<Maximum->data<<endl;
        }
        void PrintTree()
        {
            printTree(root, nullptr, false);
        }
        void Delete_Node()
        {
            int capacity_filled;

            cout<<"Enter Value you want to DELETE: ";
            cin>>value;

            capacity_filled += value;
            
            if (bag_capacity >= capacity_filled)
            {
                Node *node = deletenode(root,value);
                delete node;
                cout<<"Node "<<value<<" has been deleted successfully"<<endl;
            }
            else
            {
                cout<<"Bag brust and run to safe yourself from the witch"<<endl;
            }
        }
        void Welcome()
        {
            cout<<"Welcome! to the magical forest."<<endl;
            cout<<"How much magical power your bag hold?"<<endl;
            cin>>bag_capacity;
        }
// ----------------------------------------------------------------------------------------
        void Search_Name_byValue()
        {
            int val;
            cout<<"Enter value you want to search: ";
            cin>>value;
            string gemName = search_name_by_value(root,value);
            if (gemName == "Gem not found")
            {
                cout<<endl;
                cout<<value<<" not found"<<endl;
            }
            else
            {
                cout<<endl;
                cout<<"Gem with power "<<value<<" found: "<<gemName<<endl<<endl;
            }
        }
        Node *Search_Node(Node* root,int value)
        {
            if (root == NULL)
            {
                return NULL;
            }
            if (root->data == value)
            {
                return root;
            }

            if (root->data > value)
            {
                if (root->left != NULL)
                {
                    Node *leftNode = Search_Node(root->left,value);
                }
            }
            Node *rightNode = Search_Node(root->right,value);
            return rightNode;
        }
        Node* findparent(Node *root, int value)
        {
            if (root == NULL)
            {
                return NULL;
            }
            if ((root->left != NULL && root->left->data == value) ||
               (root->right != NULL && root->right->data == value))
            {
                return root;
            }

            Node *leftParent = findparent(root->left,value);
            if (leftParent != NULL)
            {
                return leftParent;
            }
            Node* rightparent = findparent(root->right,value);
            return rightparent;
        }
        Node *FindPreDeccessor(Node *root)
        {
            if (root == NULL)
            {
                return NULL;
            }
            
            if (root->right != NULL)
            {
                FindPreDeccessor(root->right);
            }
            return root;
        }
        Node* deletenode(Node* root,int value)
        {
            if (root == NULL)
            {
                return NULL;
            }
            
            if (value > root->data)
            {
                root->right = deletenode(root->right ,value);
            }
            else if (value < root->data)
            {
                root->left = deletenode(root->left ,value);
            }
            else
            {
                if (root->left != NULL && root->right != NULL)
                {
                    Node *predecessor = FindPreDeccessor(root->left);

                    root->data = predecessor->data;
                    root->G_name = predecessor->G_name;
                    return predecessor;
                }
                else if (root->right != NULL && root->left == NULL)
                {
                    Node *parent = findparent(root,value);
                    if (parent->right->data == value)
                    {
                        parent->right = root->right;
                    }
                    return root;
                }
                else if (root->left != NULL && root->right == NULL)
                {
                    Node *parent = findparent(root,value);
                    if (parent->left->data == value)
                    {
                        parent->left = root->left;
                    }
                    return root;
                }
                else if (root->right == NULL && root->left == NULL)
                {
                    return root;
                }
                else 
                {
                    cout<<"Node is not in the Tree"<<endl;
                }
            }
            return root;
        }
        Node *Maximum_Node(Node *root)
        {
            if (root->left != NULL)
            {
                Node *left_node = Maximum_Node(root->left);
                return left_node;
            }
            if (root->right != NULL)
            {
                Node *right_node = Maximum_Node(root->right);
                return right_node;
            }
        }
        void printTree(Node* root, Trunk* prev, bool isRight) 
        {
            if (root == NULL)
                return;

            string prev_str = "    ";
            Trunk* trunk = new Trunk(prev, prev_str);

            printTree(root->right, trunk, true);

            if (!prev)
                trunk->str = "---";
            else if (isRight) {
                trunk->str = ".---";
                prev_str = "   |";
            } else {
                trunk->str = "`---";
                prev->str = prev_str;
            }

            showTrunks(trunk);
            cout << root->G_name << ": " << root->data << endl;

            if (prev)
                prev->str = prev_str;
            trunk->str = "   |";

            printTree(root->left, trunk, false);
            delete trunk;
        }    
        void showTrunks(Trunk* p) 
        {
            if (p == NULL)
                return;

            showTrunks(p->prev);

            cout << p->str;
        }    
        Node* find_highest_gem(Node *root)
        {
            if (root == NULL)
            {
                return NULL;
            }

            Node* Max_value = root;

            Node *leftParent = find_highest_gem(root->left);
            if (leftParent != NULL && leftParent->data > Max_value->data)
            {
                Max_value = leftParent;
                return Max_value;
            }

            Node* rightParent = find_highest_gem(root->right);
            if (rightParent != NULL && rightParent->data > Max_value->data)
            {
                Max_value = rightParent;
            }
            return Max_value;
        }
        string search_name_by_value(Node* root, int val)
        {
            if (root == NULL)
            {
                return "Gem not Found";
            }
            if (root->data == val)
            {
                return root->G_name;
            }
            string rootleft = search_name_by_value(root->left,val);
            if (rootleft != "Gem not found")
            {
                return rootleft;
            }
            string rootright = search_name_by_value(root->right,val);
            return rootright;
        }
        Node* insert(Node *root, int val,string gem_name)
        {
            if (root == NULL)
            {
                root = new Node (val);
                root->G_name = gem_name;
                root->left = NULL;
                root->right = NULL;
            }
            else if(root != NULL)
            {
                if (val > root->data)
                {
                    root->right = insert(root->right,val,gem_name);
                }
                else if(val < root->data)
                {
                    root->left = insert(root->left,val,gem_name);
                }
                else if (val == root->data)
                {
                    cout<<"Duplication not ALLOWED!"<<endl;
                    return NULL;
                }
            }
            return root;
        }

        void InOrder(Node *root)
        {
            if (root != NULL)
            {
                InOrder(root->left);
                cout << root->G_name <<": "<<root->data << " "<<endl;
                InOrder(root->right);
            }
        }
        void PostOrder(Node *root)
        {
            if (root != NULL)
            {
                PostOrder(root->left);
                PostOrder(root->right);
                cout << root->G_name <<": "<<root->data << " "<<endl;
            }
        }
        void PreOrder(Node *root)
        {
            if (root != NULL)
            {
                cout << root->G_name <<": "<<root->data << " "<<endl;
                PreOrder(root->left);
                PreOrder(root->right);
            }
        }
};

int main()
{
    Node *root = NULL;
    Binary_Tree T;
    int choose,val,choice;

    T.Welcome();

    T.Insert("Diamond",50);
    T.Insert("Ruby",30);
    T.Insert("Sapphire",70);
    T.Insert("Pearl",40);
    T.Insert("Opal",10);
    T.Insert("Garnet",60);
    T.Insert("Zircon",20);
    T.Insert("Jade",5);

    while (choose != 6)
    {
        cout<<"Select the Option:"<<endl;
        cout<<"1. Display the magical power."<<endl;
        cout<<"2. Search for the gem by specifying its power."<<endl;
        cout<<"3. Find the gem with highest magical power"<<endl;
        cout<<"4. Pluck a gem from the tree."<<endl;
        cout<<"5. Print Tree"<<endl;
        cin>>choose;
        if (choose == 1)
        {
            cout<<"Which format you want to traverse: "<<endl;
            cout<<"1. PreOrder"<<endl;
            cout<<"2. PostOrder"<<endl;
            cout<<"3. InOrder"<<endl;
            cin>>choice;
            if (choice == 1)
            {
                cout<<endl;
                T.PrintPreOrder();
                cout<<endl;
            }
            else if (choice == 2)
            {
                cout<<endl;
                T.PrintPostOrder();
                cout<<endl;
            }
            else if (choice == 3)
            {
                cout<<endl;
                T.PrintInOrder();
                cout<<endl;
            }
            else
            {
                cout<<"Invalid"<<endl;
            }
        }
        else if (choose == 2)
        {
            T.Search_Name_byValue();
        }
        else if (choose == 3)
        {
            T.Find_Gem();
        }
        else if (choose == 5)
        {
            T.PrintTree();
        }
        else if (choose == 4)
        {
            T.Delete_Node();
        }
        else
        {
            break;
        }
    }    
}