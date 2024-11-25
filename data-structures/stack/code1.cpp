/*
 * Stack Implementation in C++ (Top-Varying Stack)
 * ----------------------------------------------
 * Provides a menu-driven interface to interact with the stack and perform various operations.
 */

#include <iostream>
using namespace std;

class Stack
{
    int *arr;    // Pointer to the dynamically allocated array to store stack elements
    int TOP;     // Index of the top element in the stack
    int MAXSIZE; // Maximum allowable size of the stack

public:
    // Constructor: Initializes the stack with the specified size
    Stack(int size)
    {
        arr = new int[size]; // Dynamically allocate memory for the stack
        MAXSIZE = size;      // Set the maximum capacity of the stack
        TOP = -1;            // Initialize the top index to -1 indicating the stack is empty
    }

    // Destructor: Frees the dynamically allocated memory for the stack
    ~Stack()
    {
        delete[] arr;
    }

    // Push: Adds an element to the top of the stack
    void push(int x)
    {
        if (TOP == MAXSIZE - 1)
        {
            cout << "Overflow: Stack is full. Cannot add more elements." << endl;
            display();
            return;
        }
        else
        {
            arr[++TOP] = x;
            display();
        }
    }

    // Pop: Removes and returns the top element from the stack
    int pop()
    {
        if (TOP == -1)
        {
            cout << "Underflow: Stack is empty. No element to pop." << endl;
            display();
            return -1;
        }
        else
        {
            int poppedValue = arr[TOP--];
            display();
            return poppedValue;
        }
    }

    // Peek: Returns the top element without removing it from the stack
    int peek()
    {
        if (TOP == -1)
        {
            cout << "Stack is empty: No top element to view." << endl;
            return -1;
        }
        return arr[TOP];
    }

    // Empty: Checks if the stack is empty
    bool empty()
    {
        return TOP == -1;
    }

    // Size: Returns the number of elements currently in the stack
    int size()
    {
        return TOP + 1;
    }

    // Display: Outputs the current state of the stack to the console
    void display()
    {
        cout << "Current stack state: [ ";
        // Loop through the stack array and display its contents
        for (int i = MAXSIZE - 1; i >= 0; i--)
        {
            if (i <= TOP) // If the index is less than or equal to top, the position holds a valid element
            {
                cout << arr[i] << " ";
            }
            else
            {
                cout << "- "; // Dash for empty positions
            }
        }
        cout << "]" << endl;
    }
};

// Main function to test the Stack class and its operations
int main()
{
    Stack s(5); // Create a stack of size 5
    int choice, value;

    // Infinite loop to continually display the menu and perform operations
    while (true)
    {
        // Display the menu with available operations
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Size\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Switch case to execute the corresponding operation based on user's choice
        switch (choice)
        {
        case 1: // Push operation
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2: // Pop operation
            cout << "Popped value: " << s.pop() << endl;
            break;

        case 3: // Peek operation
            cout << "Top element: " << s.peek() << endl;
            break;

        case 4: // Size operation
            cout << "Stack size: " << s.size() << endl;
            break;

        case 5: // Display operation
            s.display();
            break;

        case 6: // Exit operation
            cout << "Exiting the program..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }

    return 0;
}
