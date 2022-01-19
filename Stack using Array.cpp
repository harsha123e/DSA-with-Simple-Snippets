//Stack using Arrays
#include <iostream>

#define SIZE 5

using namespace std;

class Stack{
  private :
    int stack[SIZE];
    int top;
  public:
    Stack(){
        top=-1;
        for(int i=0;i<SIZE;i++)
            stack[i]=-1;
    }
    
    bool isEmpty(){
        if(top==-1)
            return true;
        return false;
    }
    
    bool isFull(){
        if(top==SIZE-1)
            return true;
        return false;
    }
    
    void push(int value){
        if(isFull())
            cout<<"Stack overflow\n";
        else{
            top++;
            stack[top]=value;
        }
    }
    
    int pop(){
        if(isEmpty()){
            cout<<"Stack Underflow\n";
            return -1;
        }
        else{
            int popedValue=stack[top];
            stack[top--]=-1;
            return popedValue;
        }
    }
    
    int peek(int position){
        if(position<0 || position > SIZE-1){
            return -1;
        }
        return stack[position];
    }
    
    int count(){
        return top+1;
    }
    
    void change(int position, int value){
        if(position<0 || position > SIZE-1)
            cout<<"Invalid Position\n";
        else{
            stack[position]=value;
            cout<<"Value has been updated\n";
        }
    }
    
    void display(){
        for(int i=SIZE-1;i>=0;i--)
            cout<<stack[i]<<endl;
    }
};

int main() {
    
    Stack s1;
    int value,position,option;
    
    do{
        cout<<"Enter your choice. Press 0 to exit\n";
        cout<<"1.Push()\n";
        cout<<"2.Pop()\n";
        cout<<"3.isEmpty()\n";
        cout<<"4.isFull()\n";
        cout<<"5.peek()\n";
        cout<<"6.change()\n";
        cout<<"7.count()\n";
        cout<<"8.display()\n";
        cin>>option;
        
        switch(option){
            case 0: break;
            case 1:
                cout<<"Enter value to be pushed : ";
                cin>>value;
                s1.push(value);
                break;
            case 2:
                value = s1.pop();
                if(value!=-1)
                    cout<<value<<" has been poped out\n";
                break;
            case 3:
                if(s1.isEmpty())
                    cout<<"Stack is Empty\n";
                else
                    cout<<"Stack is not Empty\n";
                break;
            case 4:
                if(s1.isFull())
                    cout<<"Stack is Full\n";
                else
                    cout<<"Stack is not full\n";
                break;
            case 5:
                cout<<"Enter position to peek : ";
                cin>>position;
                cout<<"Value at "<<position<<" is "<<s1.peek(position)<<endl;
                break;
            case 6:
                cout<<"Enter the position to change : ";
                cin>>position;
                cout<<"Enter the value : ";
                cin>>value;
                s1.change(position,value);
                break;
            case 7:
                cout<<"Number of values present in stack are : "<<s1.count()<<endl;
                break;
            case 8:
                cout<<"Values stored in stack are : \n";
                s1.display();
                break;
            default:
                cout<<"Invalid Option!! Try again.\n";
        }
    }while(option!=0);
    
    return 0;
}
