//Queue using arrays
#include <iostream>

using namespace std;

class Queue{
    private:
    int front,rear,*queue,SIZE;
    public:
    Queue(int size){
        SIZE = size;
        front = rear = -1;
        queue = new int[SIZE];
        for(int i=0;i<SIZE;i++)
            queue[i]=-1;
    }
    bool isEmpty(){
        if(front==-1 && rear==-1)
            return true;
        return false;
    }
    bool isFull(){
        if(rear==SIZE-1)
            return true;
        return false;
    }
    void enqueue(int value){
        if(isFull()){
            cout<<"Queue is Full\n";
            return;
        }
        else if(isEmpty())
            front = rear = 0;
        else
            rear++;
        queue[rear]=value;
    }
    int dequeue(){
        int temp=-1;
        if(isEmpty()){
            cout<<"Queue is empty\n";
            return temp;
        }
        else if(front == rear){
            temp=queue[front];
            queue[front]=-1;
            front=rear=-1;
            return temp;
        }
        else{
            temp=queue[front];
            queue[front++]=-1;
            return temp;
        }
    }
    int count(){
        if(isEmpty())
            return 0;
        return rear-front+1;
    }
    void display(){
        for(int i=0;i<SIZE;i++)
            cout<<queue[i]<<" ";
    }
};

int main() {
    
    int size;
    
    cout<<"Enter size of Queue : ";
    cin>>size;
    
    Queue q(size);
    int value,option;
    
    do{
        cout<<"\nEnter your choice. Press 0 to exit\n";
        cout<<"1.Enqueue()\n";
        cout<<"2.Dequeue()\n";
        cout<<"3.isEmpty()\n";
        cout<<"4.isFull()\n";
        cout<<"5.count()\n";
        cout<<"6.display()\n";
        cin>>option;
        
        switch(option){
            case 0: break;
            case 1:
                cout<<"Enter value to be added to queue : ";
                cin>>value;
                q.enqueue(value);
                break;
            case 2:
                value = q.dequeue();
                if(value!=-1)
                    cout<<value<<" has been removed out\n";
                break;
            case 3:
                if(q.isEmpty())
                    cout<<"Queue is Empty\n";
                else
                    cout<<"Queue is not Empty\n";
                break;
            case 4:
                if(q.isFull())
                    cout<<"Queue is Full\n";
                else
                    cout<<"Queue is not full\n";
                break;
            case 5:
                cout<<"Number of values present in queue are : "<<q.count()<<endl;
                break;
            case 6:
                cout<<"Values stored in queue are : \n";
                q.display();
                break;
            default:
                cout<<"Invalid Option!! Try again.\n";
        }
    }while(option!=0);
    
    return 0;
}
