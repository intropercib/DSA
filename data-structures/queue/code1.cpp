/*
 * Queue Implementation in C++ (Front Pointer Fixed, Rear Pointer Varying)
 * ------------------------------------------------------------------------
 * Provides a menu-driven interface to interact with the queue and perform
 * various operations.
 */

#include <iostream>
using namespace std;

class Queue
{
    int *arr;     // Pointer to the dynamically allocated array for the queue
    int FRONT;    // Fixed index for the front of the queue
    int REAR;     // Varying index for the rear of the queue
    int MAXSIZE;  // Maximum allowable size of the queue

public:
    // Constructor: Initializes the queue with a specified size
    Queue(int size)
    {
        arr = new int[size];  // Dynamically allocate memory for the queue
        MAXSIZE = size;       // Set the maximum capacity of the queue
        FRONT = 0;            // Initialize the front index to 0 (fixed position)
        REAR = -1;            // Initialize the rear index to -1 (queue is empty)
    }

    // Destructor: Frees the dynamically allocated memory for the queue
    ~Queue()
    {
        delete[] arr;
    }

    // Enqueue: Adds an element to the rear of the queue
    void enqueue(int x)
    {
        if (REAR == MAXSIZE - 1)
        {
            cout << "Overflow: Queue is full. Cannot add more elements." << endl;
            return;
        }
        else
        {
            arr[++REAR] = x;
            display();       
        }
    }

    // Dequeue: Removes and returns the front element from the queue
    int dequeue()
    {
        if (REAR == -1) 
        {
            cout << "Underflow: Queue is empty. No element to dequeue." << endl;
            return -1;
        }
        else
        {
            int poppedValue = arr[FRONT];
            for (int i = 0; i < REAR; i++)
            {
                arr[i] = arr[i + 1];
            }
            REAR--;      
            display();   
            return poppedValue;
        }
    }

    // Display: Outputs the current state of the queue
    void display()
    {
        cout << "Queue :: ";
        cout << "[";
        // Loop through the array to display the elements
        for (int i = 0; i < MAXSIZE; i++)
        {
            if (i <= REAR) // Display valid elements up to the rear index
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

// Main function to test the Queue class and its operations
int main()
{
    Queue q(5); // Create a queue with a capacity of 5
    int choice, value;

    // Infinite loop to continually display the menu and perform operations
    while (true)
    {
        // Display the menu with available operations
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Switch case to execute the corresponding operation based on user's choice
        switch (choice)
        {
        case 1: // Enqueue operation
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2: // Dequeue operation
            cout << "Dequeued value: " << q.dequeue() << endl;
            break;

        case 3: // Display operation
            q.display();
            break;

        case 4: // Exit operation
            cout << "Exiting the program..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }

    return 0;
}