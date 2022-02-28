#include <bits/stdc++.h>
using namespace std;


class Stack {
	int top;

public:
	int arr[5]; 

	Stack() { top = -1; }
	void push(int x);
	void pop();
    void display();

};

void Stack::push(int x)
{
	if (top >= (4)) {
		cout << "Stack Overflow"<<endl;
	}
	else {
		arr[++top] = x;
        cout<<"Element "<<arr[top]<<" successfully pushed."<<endl;
	}
}

void Stack::pop()
{
	if (top < 0) {
		cout << "Stack Underflow"<<endl;
	}
	else {
		int x = arr[top--];
        cout<<"Element "<<x<<" successfully popped."<<endl;
	}
}

void Stack ::display(){
    if (top == -1)
    {
        cout << "Empty Stack!" << endl;
    }
    else
    {
        cout<<"Stack: "<<endl;
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i]<<" ";
        }
    }
}


int main()
{
	class Stack s;
	s.push(23);
	s.push(48);
	s.push(15);
    s.pop();
    s.display();
    return 0;
}
