/*
 * Stack Implementation in C++ (Bottom-Varying Stack)
 * ----------------------------------------------
 * Provides a menu-driven interface to interact with the stack and perform various operations.
 */

#include <iostream>
using namespace std;

class Stack
{
    int *arr;    // Pointer to the dynamically allocated array to store stack elements
    int BOS;     // Index of the bottom element in the stack (0-based index)
    int MAXSIZE; // Maximum allowable size of the stack

public:
    // Constructor: Initializes the stack with the specified size
    Stack(int size)
    {
        arr = new int[size]; // Dynamically allocate memory for the stack
        MAXSIZE = size;      // Set the maximum capacity of the stack
        BOS = 0;             // Initialize the bottom index to 0 indicating the stack is empty
    }

    // Destructor: Frees the dynamically allocated memory for the stack
    ~Stack()
    {
        delete[] arr;
    }

    // Push: Adds an element to the bottom of the stack
    void push(int x)
    {
        if (BOS == MAXSIZE)
        {
            cout << "Overflow: Stack is full. Cannot add more elements." << endl; // Overflow error
        }
        else
        {
            // Shift elements upwards to make space at the bottom
            for (int i = BOS; i > 0; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[0] = x;
            BOS++;
        }
        display();
    }

    // Pop: Removes and returns the bottom element from the stack
    int pop()
    {
        if (BOS == 0)
        {
            cout << "Underflow: Stack is empty. No element to pop." << endl;
            return -1;
        }
        else
        {
            int poppedValue = arr[0];
            BOS--;
            // Shift elements down to fill the gap created by the popped element
            for (int i = 0; i < BOS; i++)
            {
                arr[i] = arr[i + 1];
            }
            display();
            return poppedValue;
        }
    }

    // Peek: Returns the bottom element without removing it from the stack
    int peek()
    {
        if (BOS == 0)
        {
            cout << "Stack is empty: No bottom element to view." << endl;
            return -1;
        }
        return arr[0];
    }

    // Empty: Checks if the stack is empty
    bool empty()
    {
        return BOS == 0;
    }

    // Size: Returns the number of elements currently in the stack
    int size()
    {
        return BOS;
    }

    // Display: Outputs the current state of the stack to the console
    void display()
    {
        cout << "Current stack state: [ ";
        // Loop through the stack array and display its contents
        for (int i = 0; i < BOS; i++)
        {
            cout << arr[i] << " ";
        }
        for (int i = BOS; i < MAXSIZE; i++)
        {
            cout << "- "; // Dash for empty positions
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
            cout << "Bottom element: " << s.peek() << endl;
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
