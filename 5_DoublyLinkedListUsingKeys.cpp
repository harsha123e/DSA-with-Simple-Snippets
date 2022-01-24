#include <iostream>
using namespace std;

class Node
{
public:
    int key, data;
    Node *prev;
    Node *next;

    Node()
    {
        key = data = 0;
        prev = next = NULL;
    }
};

class DoublyLinkedList
{

public:
    Node *head;

    DoublyLinkedList()
    {
        head = NULL;
    }

    Node *nodeExists(int key)
    {
        Node *temp = NULL, *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == key)
            {
                temp = ptr;
                break;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    void prepand(Node *n)
    {
        Node *temp = nodeExists(n->key);
        if (temp != NULL)
            cout << "Node already exists\n";
        else
        {
            if (head == NULL)
                head = n;
            else
            {
                n->next = head;
                head->prev = n;
                head = n;
            }
            cout << "Node added successfully\n";
        }
    }

    void append(Node *n)
    {
        Node *temp = nodeExists(n->key);
        if (temp != NULL)
            cout << "Node already exists\n";
        else
        {
            if (head == NULL)
                head = n;
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                    ptr = ptr->next;
                n->prev = ptr;
                ptr->next = n;
            }
            cout << "Node added successfully\n";
        }
    }

    void insertAfter(int key, Node *n)
    {
        Node *temp = nodeExists(key);
        if (temp == NULL)
            cout << "Node doesn't exists\n";
        else
        {
            if (nodeExists(n->key) != NULL)
                cout << "Node with given key already exists\n";
            else
            {
                if (temp->next == NULL)
                    append(n);
                else
                {
                    n->prev = temp;
                    n->next = temp->next;
                    temp->next->prev = n;
                    temp->next = n;
                    cout << "Node added successfully\n";
                }
            }
        }
    }

    void deleteNode(int key)
    {
        Node *temp = nodeExists(key);
        if (temp == NULL)
            cout << "Node doesn't exist\n";
        else
        {
            if (temp == head)
            {
                if (head->next == NULL)
                    head = NULL;
                else{
                    head = head->next;
                    head->prev=NULL;
                }
            }
            else if (temp->next == NULL)
                temp->prev->next = NULL;
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            free(temp);
            cout << "Node deleted successfully\n";
        }
    }

    void updateNode(int key, int value)
    {
        Node *temp = nodeExists(key);
        if (temp == NULL)
            cout << "Node doesn't exist\n";
        else
        {
            temp->data = value;
            cout << "Node updated successfully";
        }
    }

    void display()
    {
        Node *ptr = head, *temp = NULL;
        cout << "Values in double linked list are : ";
        while (ptr != NULL)
        {
            cout << "(" << ptr->key << "," << ptr->data << ")<-->";
            if (ptr->next == NULL)
                temp = ptr;
            ptr = ptr->next;
        }

        cout << endl;

        cout << "Values in reverse order : ";
        while (temp != NULL)
        {
            cout << "(" << temp->key << "," << temp->data << ")<-->";
            temp = temp->prev;
        }
    }
};

int main()
{
    DoublyLinkedList l;
    int option, key, key1, data;

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
            l.prepand(n);
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