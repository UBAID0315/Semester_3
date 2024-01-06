class Hashtable {
private:
    int size;
    Node** arr;
    int length;

    int hash_function(const string& value) {
        // Simple hash function for demonstration purposes
        int sum = int(value[0] - 'A');
        return sum % size;
    }

    void resize() {
        int newsize = size * 2;
        Node** newArray = new Node*[newsize];

        for (int i = 0; i < newsize; i++) {
            newArray[i] = nullptr;
        }

        for (int i = 0; i < length; i++) {
            Node* curr = arr[i];

            while (curr != nullptr) {
                int index = hash_function(curr->data);

                Node* node = new Node(curr->data);
                node->next = newArray[index];
                newArray[index] = node;

                curr = curr->next;
            }
        }
        delete[] arr;
        arr = newArray;
        size = newsize;
    }

public:
    Hashtable(int size) {
        length = 0;
        this->size = size;
        arr = new Node*[size];
        for (int i = 0; i < size; i++) {
            arr[i] = nullptr;
        }
    }

    ~Hashtable() {
        for (int i = 0; i < size; i++) {
            Node* current = arr[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] arr;
    }

    void insert(const string& value) {
        int index = hash_function(value);

        Node* newNode = new Node(value);

        newNode->next = arr[index];
        arr[index] = newNode;
        length++;

        if (length > size * 0.75) {
            resize();
        }
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            cout << "Index " << i + 1 << ": ";
            Node* current = arr[i];
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    void getvalue(int position) {
        Node* curr = nullptr;
        for (int i = 0; i < size; i++) {
            if (i == position - 1) {
                curr = arr[i];
            }
        }
        if (curr == nullptr) {
            cout << "Current is null (no value)" << endl;
        } else {
            while (curr != nullptr) {
                cout << curr->data << " ";
                curr = curr->next;
            }
        }
    }
};

int main() {
    Hashtable table(7);
    int index;

    table.insert("Alice");
    table.insert("Bob");
    table.insert("Charlie");
    table.insert("David");
    table.insert("Eva");
    table.insert("Frank");
    table.insert("Grace");
    table.insert("Hank");
    table.insert("Ivy");
    table.insert("Danis");
    
    table.print();
    cout << "Enter Index: " << endl;
    cin >> index;
    table.getvalue(index);

    return 0;
}
