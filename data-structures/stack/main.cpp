#include <iostream>
using namespace std;

class TopVaryStack
{
    int top;
    int *arr;
    int MAXSIZE;

public:
    TopVaryStack(int size)
    {
        MAXSIZE = size;
        arr = new int[MAXSIZE];
        top = -1;
    }
    ~TopVaryStack()
    {
        delete[] arr;
    }
    void push(int x)
    {
        if (top == MAXSIZE - 1)
        {
            cout << "Overflow" << endl;
        }
        arr[++top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Empty" << endl;
            return;
        }
        top--;
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "Empty" << endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty()
    {
        return top == -1;
    }
    int display()
    {
        if (!isEmpty())
        {
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Empty" << endl;
        }
    }
};

class BottomVaryStack
{
    int *arr;
    int BOS;
    int MAXSIZE;
    int currentSize;

public:
    BottomVaryStack(int size)
    {
        MAXSIZE = size;
        arr = new int(MAXSIZE);
        BOS = MAXSIZE;
        currentSize = 0;
        for (int i = 0; i < MAXSIZE; i++)
        {
            arr[i] = 0;
        }
    }
    ~BottomVaryStack()
    {
        delete[] arr;
    }
    void push(int x)
    {
        // Check for stack overflow
        if (currentSize == MAXSIZE)
        {
            cout << "Stack Full" << endl;
            return;
        }

        // Shift elements to make space at the bottom
        for (int i = currentSize; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }

        // Insert new element at the bottom
        arr[0] = x;

        // Adjust tracking variables
        currentSize++;
    }
    void pop()
    {
        // Check for empty stack
        if (currentSize == 0)
        {
            cout << "Stack Empty" << endl;
            return;
        }

        // Shift elements towards the bottom
        for (int i = 0; i < currentSize - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        // Reset last element and adjust tracking variables
        arr[currentSize - 1] = 0;
        currentSize--;
    }

    void display()
    {
        if (currentSize == 0)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack elements: ";
        for (int i = 0; i < currentSize; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int peek()
    {
        if (currentSize == 0)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[0];
    }
    bool isEmpty()
    {
        return currentSize == 0;
    }
};

void exeBottomFixed()
{
    TopVaryStack s(5);
    // Push elements
    s.push(1);
    s.push(2);
    s.push(3);
    // Display all elements
    s.display();
    // Peek and pop demonstrations
    cout << "Top element: " << s.peek() << endl;
    s.pop();
    // Display elements after pop
    s.display();
    s.pop();
    // Display elements after second pop
    s.display();
    s.pop();
}
void exeTopFixed()
{
    BottomVaryStack s(5);

    // Push elements
    s.push(1);
    s.push(2);
    s.push(3);

    // Display all elements
    s.display();

    // Peek and pop demonstrations
    cout << "Top element: " << s.peek() << endl;
    s.pop();

    // Display elements after pop
    s.display();

    s.pop();

    // Display elements after second pop
    s.display();

    s.pop();
}
int main()
{
    // exeBottomFixed();
    exeTopFixed();
    return 0;
}