#include <iostream>
using namespace std;

class Stack
{
    int *arr;    // Pointer to the dynamically allocated array to store stack elements
    int top;     // Index of the top element in the stack
    int MAXSIZE; // Maximum allowable size of the stack

public:
    // Constructor: Initializes the stack with the specified size
    Stack(int size)
    {
        arr = new int[size]; // Dynamically allocate memory for the stack
        MAXSIZE = size;      // Set the maximum capacity of the stack
        top = -1;            // Initialize the top index to -1 indicating the stack is empty
    }

    // Destructor: Frees the dynamically allocated memory for the stack
    ~Stack()
    {
        delete[] arr; // Release the dynamically allocated memory
    }

    // Push: Adds an element to the top of the stack
    void push(int x)
    {
        // Check for stack overflow condition
        if (top == MAXSIZE - 1)
        {
            cout << "Overflow: Stack is full. Cannot add more elements." << endl; // Overflow error
        }
        else
        {
            arr[++top] = x; // Increment the top index and insert the new element at the top
        }
        display(); // Display the stack after the push operation
    }

    // Pop: Removes and returns the top element from the stack
    int pop()
    {
        // Check for stack underflow condition
        if (top == -1)
        {
            cout << "Underflow: Stack is empty. No element to pop." << endl; // Underflow error
            return -1;                                                       // Return a sentinel value indicating an error
        }
        else
        {
            int poppedValue = arr[top--]; // Retrieve and remove the top element, then decrement the top index
            display();                    // Display the stack after the pop operation
            return poppedValue;           // Return the removed element
        }
    }

    // Peek: Returns the top element without removing it from the stack
    int peek()
    {
        // Check if the stack is empty
        if (top == -1)
        {
            cout << "Stack is empty: No top element to view." << endl; // Inform the user the stack is empty
            return -1;                                                 // Return a sentinel value indicating an error
        }
        return arr[top]; // Return the element at the top of the stack
    }

    // Empty: Checks if the stack is empty
    bool empty()
    {
        return top == -1; // If top is -1, the stack is empty
    }

    // Size: Returns the number of elements currently in the stack
    int size()
    {
        return top + 1; // The number of elements in the stack is top + 1
    }

    // Display: Outputs the current state of the stack to the console
    void display()
    {
        cout << "Current stack state: [ ";
        // Loop through the stack array and display its contents
        for (int i = MAXSIZE - 1; i >= 0; i--)
        {
            if (i <= top) // If the index is less than or equal to top, the position holds a valid element
            {
                cout << arr[i] << " "; // Print the element at the current index
            }
            else
            {
                cout << "- "; // Print a dash for empty positions in the stack
            }
        }
        cout << "]" << endl; // End the display output
    }
};

// Main function to test the Stack class and its operations
int main()
{
    Stack s(5);        // Create a stack of size 5
    int choice, value; // Variables to store menu selection and input value

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
        cin >> choice; // Take user input for menu choice

        // Switch case to execute the corresponding operation based on user's choice
        switch (choice)
        {
        case 1: // Push operation
            cout << "Enter value to push: ";
            cin >> value;  // Take the value to push onto the stack
            s.push(value); // Call the push method to add the element
            break;

        case 2:                                          // Pop operation
            cout << "Popped value: " << s.pop() << endl; // Call pop method to remove and display the top element
            break;

        case 3:                                          // Peek operation
            cout << "Top element: " << s.peek() << endl; // Call peek method to view the top element
            break;

        case 4:                                         // Size operation
            cout << "Stack size: " << s.size() << endl; // Display the current size of the stack
            break;

        case 5:          // Display operation
            s.display(); // Call display method to show the current state of the stack
            break;

        case 6:                                       // Exit operation
            cout << "Exiting the program..." << endl; // Print exit message and terminate the program
            return 0;                                 // Exit the main function and end the program

        default:
            cout << "Invalid choice! Please enter a valid option." << endl; // Handle invalid menu choices
        }
    }

    return 0; // Program will never reach this line due to the infinite loop
}
