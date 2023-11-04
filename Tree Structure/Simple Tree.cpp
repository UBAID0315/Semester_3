#include <iostream>
#include <iomanip>
using namespace std;

                                // <------- ( NODE TREE ) -------->
class Node 
{
    public:
        Node* left;
        Node* right;
        int data;

        Node(int val) 
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};
                                // <------- ( TRUNK TREE ) -------->
struct Trunk 
{
    Trunk* prev;
    string str;

    Trunk(Trunk* prev, string str) {
        this->prev = prev;
        this->str = str;
    }
};

void showTrunks(Trunk* p) {
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}

                                // <------- ( BINARY TREE ) -------->

class Binary_Tree {
private:
    Node* root;

public:
    Binary_Tree() 
    {
        root = NULL;
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
    void Insert() 
    {
        int val;
        bool condition;

        cout << "Enter the value: ";
        cin >> val;
        
        condition = Search_Node(root,val);
        if (condition == true)
        {
            cout<<"Duplication not allowed"<<endl;
        }
        else
        {
            root = insert_Node(root, val);
        }
    }
    void Search(int val) 
    {
        bool search = Search_Node(root, val);
        if (search == true)
        {
            cout<<val<<" is found in the tree"<<endl;
        }
        else if (search == false)
        {
            cout<<val<<" is not found in the tree"<<endl;
        }        
    }
    void Traverse()
    {
        int choose;
        cout<<"Select from the option below: "<<endl;
        cout<<"1. Pre-Order"<<endl;
        cout<<"2. In-Order"<<endl;
        cout<<"3. Post-Order"<<endl;
        cin>>choose;
        if (choose == 1)
        {
            pre_order(root);
        }
        else if (choose == 2)
        {
            in_order(root);
        }
        else if (choose == 3)
        {
            post_order(root);
        }
        else
        {
            cout<<"Invalid option select"<<endl;
        }
    }
    void Level_of_Node(int val,int level)
    {
        int node_level = getLevel(root,val,level);

        if (node_level >= 0)
        {
            cout<<"Level of Node: "<<node_level<<endl;
        }
        else
        {
            cout<<"Node is not in the tree"<<endl;
        }
    }
    int getLevel(Node *root,int value,int level) 
    {
        if (root == NULL)
        {
            return -1;
        }
        if (root->data == value)
        {
            return level;
        }

        int left_level = getLevel(root->left, value, level+1); 
        int right_level = getLevel(root->right, value, level+1);

        if (left_level != -1)
        {
            return left_level;
        }
        else 
        {
            return right_level;
        }
    }
    void pre_order(Node *root)
    {
        if (root != NULL)
        {
            cout<<root->data<<"\t";
            pre_order(root->left);
            pre_order(root->right);
        }
    }
    void in_order(Node *root)
    {
        if (root != NULL)
        {
            pre_order(root->left);
            cout<<root->data<<"\t";
            pre_order(root->right);
        }
    }
    void post_order(Node *root)
    {
        if (root != NULL)
        {
            pre_order(root->left);
            pre_order(root->right);
            cout<<root->data<<"\t";
        }
    }
    Node* insert_Node(Node* root, int val) 
    {
        if (root == NULL) 
        {
            root = new Node(val);
        } 
        else if (root != NULL) 
        {
            char position;
            cout << "Enter position: ";
            cin >> position;
            if (position == 'l' || position == 'L') 
            {
                root->left = insert_Node(root->left, val);
            } 
            else if (position == 'r' || position == 'R') 
            {
                root->right = insert_Node(root->right, val);
            } 
            else 
            {
                cout << "invalid" << endl;
            }
        }
        return root;
    }
    void printTree() 
    {
        printTree(root, nullptr, false);
    }
    void Depth_Of_Tree()
    {
        cout<<"Depth of Tree: "<<tree_depth(root)<<endl;
    }
    int tree_depth(Node* root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left_depth = tree_depth(root->left);
        int right_depth = tree_depth(root->right);

        return max(left_depth,right_depth)+1;
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
        cout << root->data << endl;

        if (prev)
            prev->str = prev_str;
        trunk->str = "   |";

        printTree(root->left, trunk, false);
    }
    bool Search_Node(Node* root, int val) 
    {
        if (root != NULL) {
            if (root->data == val) 
            {
                return true;
            }
        } 
        else 
        {
            return false;
        }

        bool leftsearch = Search_Node(root->left, val);
        bool rightsearch = Search_Node(root->right, val);
        return leftsearch || rightsearch;
    }
    void Delete_Tree()
    {
        delete_tree(root);
    }
    void delete_tree(Node* root)
    {
        if (root == NULL)
        {
            cout<<"Tree Successfully Deleted"<<endl;
        }

        delete_tree(root->left);
        delete_tree(root->right);

        delete root;
    }
};

int main() 
{
    Binary_Tree Tree;
    int choose = 0,value;

    while (choose != 8) 
    {
        cout<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"| Select option from the menu: "<<endl;
        cout<<"| 1. Insert"<<endl;
        cout<<"| 2. Print Tree"<<endl;
        cout<<"| 3. Traverse"<<endl;
        cout<<"| 4. Search a value"<<endl;
        cout<<"| 5. Depth of Tree"<<endl;
        cout<<"| 6. Level of Node"<<endl;
        cout<<"| 7. Delete Tree"<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"Option: ";
        cin>>choose;
        if (choose == 1) 
        {
            Tree.Insert();
        } else if (choose == 2) 
        {
            Tree.printTree();
        }
        else if (choose == 3)
        {
            Tree.Traverse();
        }
        else if (choose == 4)
        {
            cout<<"Enter the value of want to search: ";
            cin>>value;

            Tree.Search(value);
        }
        else if (choose == 5)
        {
            Tree.Depth_Of_Tree();
        }
        else if (choose == 6)
        {
            cout<<"Enter Node to find Level: ";
            cin>>value;

            Tree.Level_of_Node(value,0);
        }
        else if (choose == 7)
        {
            Tree.Delete_Tree();
        }
        else 
        {
            break;
        }
    }
    return 0;
}
