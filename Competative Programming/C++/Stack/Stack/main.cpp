#include <iostream>

using namespace std;

class CustomStack
{
public:
    int s;
    int *arr;
    int top;
    CustomStack(int s)
    {
        this->s=s;
        arr=new int[s];
        top=-1;
    }
    //push
    void push(int value)
    {
        if(!isExceed())
        {
            top++;
            arr[top]=value;
            return;
        }
        cout<<"Stack overflow"<<endl;
        return;
    }
    //pop
    void pop()
    {
        if(!isEmpty())
        {
            top--;
            return;
        }
        top=-1;
        cout<<"Stack is underflow"<<endl;
        return;
    }
    //top
    int top_value()
    {
        if(!isEmpty())
        {
            return arr[top];
        }
        cout<<"Stack is underflow"<<endl;
        return -1;
    }
    //isempty
    bool isEmpty()
    {
        return top==-1?true:false;
    }
    bool isExceed()
    {
        return top==s-1?true:false;
    }
    void display(){
        if(top!=-1){
            for(int i=0;i<=top;i++){
                cout<<"stack value : "<<arr[i]<<" "<<endl;
            }
        }
        else{
            cout<<"stack is empty"<<endl;
        }
    }
};

int main()
{
    CustomStack st(5);
    st.push(1);
    cout<<"*******************************"<<endl;
    st.display();
    st.push(2);
    cout<<"*******************************"<<endl;
    st.display();
    st.push(3);
    cout<<"*******************************"<<endl;
    st.display();
    st.push(4);
    cout<<"*******************************"<<endl;
    st.display();
    st.push(5);
    cout<<"*******************************"<<endl;
    st.display();
    st.push(6);
    cout<<"*******************************"<<endl;
    st.display();
    cout<<"top value is : "<<st.top_value();

    st.pop();
    st.display();
    cout<<"*******************************"<<endl;
    st.pop();
    st.display();
    cout<<"*******************************"<<endl;
    st.pop();
    st.display();
    cout<<"*******************************"<<endl;
    st.pop();
    st.display();
    cout<<"*******************************"<<endl;
    st.pop();
    st.display();
    cout<<"*******************************"<<endl;
    st.pop();
    st.display();
    cout<<"*******************************"<<endl;
    st.pop();
    st.display();

}
