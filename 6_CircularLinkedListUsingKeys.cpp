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
};

class CircularLinkedList
{
public:
    Node *head;

    CircularLinkedList()
    {
        head = NULL;
    }

    Node *nodeExists(int key)
    {
        Node *temp = NULL;
        Node *ptr = head;
        if (ptr != NULL)
        {
            do
            {
                if (ptr->key == key)
                    temp = ptr;
                ptr = ptr->next;
            } while (ptr != head);
        }
        return temp;
    }

    void append(Node *n)
    {
        if (nodeExists(n->key) != NULL)
            cout << "Node already exists\n";
        else
        {
            if (head == NULL)
            {
                head = n;
                n->next = head;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                    ptr = ptr->next;
                ptr->next = n;
                n->next = head;
            }
            cout << "Node appended successfully\n";
        }
    }

    void prepand(Node *n)
    {
        if (nodeExists(n->key) != NULL)
            cout << "Node already exists\n";
        else
        {
            if (head == NULL)
            {
                head = n;
                n->next = head;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                    ptr = ptr->next;
                n->next = head;
                head = n;
                ptr->next = head;
            }
            cout << "Node prepanded successfully\n";
        }
    }

    void insertAfter(int key, Node *n)
    {
        Node *temp = nodeExists(key);
        if (temp == NULL)
            cout << "Node with " << key << " doesn't exist\n";
        else
        {
            if (nodeExists(n->key))
                cout << "Node with " << n->key << " already exists\n";
            else
            {
                if (temp->next == head)
                {
                    Node *ptr = head;
                    while (ptr->next != head)
                        ptr = ptr->next;
                    ptr->next = n;
                    n->next = head;
                }
                else
                {
                    Node *prev = head;
                    while (prev->next != temp)
                        prev = prev->next;
                    n->next = prev->next;
                    prev->next = n;
                }
                cout << "Node inserted successfully\n";
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
                if (temp->next == head)
                {
                    head = NULL;
                    free(temp);
                }
                else
                {
                    Node *ptr = head;
                    while (ptr->next != head)
                        ptr = ptr->next;

                    head = head->next;
                    ptr->next = head;

                    free(temp);
                }
            }
            else if (temp->next == head)
            {
                Node *ptr = head;
                while (ptr->next != temp)
                    ptr = ptr->next;
                ptr->next = head;

                free(temp);
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != temp)
                    ptr = ptr->next;
                ptr->next = temp->next;
                free(temp);
            }
            cout << "Node deleted Successfully\n";
        }
    }

    void updateNode(int key, int data)
    {
        Node *temp = nodeExists(key);
        if (temp == NULL)
            cout << "Node doesn't exist\n";
        else
        {
            temp->data = data;
            cout << "Node data updated successfully\n";
        }
    }

    void display()
    {
        Node *ptr = head;
        if (head == NULL)
            cout << "List is empty\n";
        else
        {
            cout << "\nHead : " << head << endl;
            cout << "Circular Linked list : ";
            do
            {
                cout << "(" << ptr->key << "," << ptr->data << "," << ptr->next << ")-->";
                ptr = ptr->next;
            } while (ptr != head);
        }
    }
};

int main()
{
    CircularLinkedList l;
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