#include <iostream>

using namespace std;

class CircularQueue{
  
  private:
    int front,rear,*a,size;
  
  public:
    CircularQueue(int size){
        front=rear=-1;
        this->size=size;
        a=new int[this->size];
        for(int i=0;i<this->size;i++)
            a[i]=-1;
    }
    
    bool isEmpty(){
        if(front==-1 && rear==-1)
            return true;
        return false;
    }
    
    bool isFull(){
        if((rear+1)%size==front)
            return true;
        return false;
    }
    
    void enqueue(int value){
        if(isFull()){
            cout << "Queue is Full\n";
            return;
        }
        else if(isEmpty())
            front=rear=0;
        else
            rear=(rear+1)%size;
        a[rear]=value;
        cout<<"Inserted "<<value<<" into queue at "<<rear<<endl;
    }
    
    int dequeue(){
        int temp=-1;
        if(isEmpty())
            cout<<"Queue is Empty\n";
        else if(front==rear){
            temp=a[front];
            a[front]=-1;
            front = rear = -1;
        }
        else{
            temp=a[front];
            a[front]=-1;
            front=(front+1)%size;
        }
        return temp;
    }  
    void display(){
        for(int i=0;i<size;i++)
            cout<<a[i]<<" ";
    }
};

int main(){
    
    int size;
    cout << "Enter size of queue : ";
    cin >> size;
    
    CircularQueue q(size); 
    int value, option;
    
    do{
        cout<<"Select a option. Press 0 to exit\n";
        cout<<"1.Enqueue()\n";
        cout<<"2.Dequeue()\n";
        cout<<"3.isEmpty()\n";
        cout<<"4.isFull()\n";
        cout<<"5.Display()\n";
        cin>>option;
        
        switch(option){
            case 0 : break;
            case 1 : cout<<"Enter the value to be inserted : ";
                     cin>>value;
                     q.enqueue(value);
                     break;
            case 2 : cout<<q.dequeue()<<" has been removed from queue\n";
                     break;
            case 3 : if(q.isEmpty())
                        cout<<"Queue is Empty\n";
                     else
                        cout<<"Queue is Not Empty\n";
                     break;
            case 4 : if(q.isFull())
                        cout<<"Queue is Full\n";
                     else
                        cout<<"Queue is Not Full\n";
                     break;
            case 5 : cout << "Queue : ";
                     q.display();
                     cout << endl;
                     break;
            default : cout << "Invalid Option\n";
        }
    }while(option!=0);
    
  return 0;
}
