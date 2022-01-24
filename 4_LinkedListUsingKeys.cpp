#include <iostream>

using namespace std;

class Node
{

public:
    int key, data;
    Node *next;
    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int key, int data)
    {
        this->key = key;
        this->data = data;
        next = NULL;
    }
};

class SinglyLinkedList
{

public:
    Node *head;

    SinglyLinkedList()
    {
        head = NULL;
    }

    SinglyLinkedList(Node *n)
    {
        head = n;
    }

    // Node Exists or Not
    Node *nodeExists(int key)
    {
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == key)
                temp = ptr;
            ptr = ptr->next;
        }
        return temp;
    }

    //Insert in Beginning
    void prepend(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists\n";
            return;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Node Inserted Successfully\n";
        }
    }

    //Insert at End
    void append(Node *n)
    {

        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists\n";
            return;
        }
        else
        {

            if (head == NULL)
            {
                prepend(n);
                return;
            }
            else
            {
                Node *ptr = head;

                while (ptr->next != NULL)
                    ptr = ptr->next;

                ptr->next = n;

                cout << "Node Inserted Successfully\n";
            }
        }
    }

    //insert after given key
    void insertAfter(int key, Node *n)
    {
        Node *temp = nodeExists(key);
        if (temp == NULL)
        {
            cout << "No such node found\n";
            return;
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node already exists\n";
                return;
            }
            else
            {
                n->next = temp->next;
                temp->next = n;
                cout << "Node inserted successfully\n";
            }
        }
    }

    void deleteNode(int key)
    {
        Node *temp = nodeExists(key);
        if (temp == NULL)
        {
            cout << "No such Node found\n";
            return;
        }
        else if (temp == head)
        {
            if (head->next == NULL)
            {
                head = NULL;
                free(temp);
                cout << "Node deleted. List is empty\n";
            }
            else
            {
                head = head->next;
                free(temp);
                cout << "Node deleted successfully\n";
            }
        }
        else
        {
            Node *previous = head;
            while (previous->next != temp)
                previous = previous->next;
            if (temp->next == NULL)
            {
                previous->next = NULL;
                free(temp);
                cout << "Node deleted successfully\n";
            }
            else
            {
                previous->next = temp->next;
                free(temp);
                cout << "Node deleted successfully\n";
            }
        }
    }

    //update value
    void updateNode(int key, int value)
    {
        Node *temp = nodeExists(key);
        if (temp == NULL)
        {
            cout << "No such Node found\n";
            return;
        }
        else
        {
            temp->data = value;
            cout << "Value has been updated\n";
        }
    }

    //Display Linked List
    void display()
    {
        Node *ptr = head;
        cout << "Values in Linked list are : ";
        while (ptr != NULL)
        {
            cout << "(" << ptr->key << "," << ptr->data << ")-->";
            ptr = ptr->next;
        }
    }
};

int main()
{

    SinglyLinkedList l;
    int option, key, data, key1;

    do
    {

        cout << "\nSelect your option. Press 0 to Exit\n";
        cout << "1.Insert Node at Beginning\n";
        cout << "2.Insert Node at End\n";
        cout << "3.Insert Node after a key value\n";
        cout << "4.Delete Node using key\n";
        cout << "5.Update value using key\n";
        cout << "6.Display Linked List\n";
        cin >> option;

        Node *n = new Node();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter key and data values : ";
            cin >> key >> data;
            n->key = key;
            n->data = data;
            l.prepend(n);
            break;
        case 2:
            cout << "Enter key and data values : ";
            cin >> key >> data;
            n->key = key;
            n->data = data;
            l.append(n);
            break;
        case 3:
            cout << "Enter key value after which the node to be inserted : ";
            cin >> key1;
            cout << "Enter key and data values : ";
            cin >> key >> data;
            n->key = key;
            n->data = data;
            l.insertAfter(key1, n);
            break;
        case 4:
            cout << "Enter key to delete the node : ";
            cin >> key;
            l.deleteNode(key);
            break;
        case 5:
            cout << "Enter key and new value to be updated : ";
            cin >> key >> data;
            l.updateNode(key, data);
            break;
        case 6:
            l.display();
            break;
        default:
            cout << "Invalid Option. Try Again\n";
        }
    } while (option != 0);

    return 0;
}