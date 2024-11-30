/*
 * Queue Implementation in C++ (Circular Queue)
 * ------------------------------------------------------------------------
 * Provides a menu-driven interface to interact with the queue and perform
 * various operations.
 * This implementation uses a circular array to handle the wrap-around case.
 * For the display function, it shows all elements in the queue, including empty slots.
 * Remove the block where comments have '***' this code are written just to visualize the circular queue implementation.
 * NOTE: This code is for demonstration purposes only. So make sure to give user input is +ve integer.
 */

#include <iostream>
using namespace std;

class Queue
{
    int *arr;     // Pointer to the dynamically allocated array for the queue
    int FRONT;    // Fixed index for the front of the queue
    int REAR;     // Varying index for the rear of the queue
    int MAX_SIZE; // Maximum allowable size of the queue

public:
    // Constructor to initialize the circular queue
    Queue(int size)
    {
        FRONT = REAR = -1;       // Initially, the queue is empty
        MAX_SIZE = size;         // Set the maximum size of the queue
        arr = new int[MAX_SIZE]; // Dynamically allocate memory for the queue

        // *** Initialize all elements of the array to -1 *** //
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            arr[i] = -1; // Mark all slots as empty
        }
    }

    // Destructor to release allocated memory
    ~Queue()
    {
        delete[] arr;
    }

    // Enqueue: Adds an element to the rear of the queue
    void enqueue(int x)
    {
        if ((FRONT == 0 && REAR == MAX_SIZE - 1) || (REAR + 1) % MAX_SIZE == FRONT) // Check if full
        {
            cout << "Overflow: Queue is full. Cannot add more elements." << endl;
            return;
        }

        if (FRONT == -1) // First insertion
        {
            FRONT = REAR = 0;
        }
        else
        {
            REAR = (REAR + 1) % MAX_SIZE; // Circular increment
        }

        arr[REAR] = x; // Add element
        display();
    }

    // Dequeue: Removes and returns the front element from the queue
    int dequeue()
    {
        if (FRONT == -1) // Check if empty
        {
            cout << "Underflow: Queue is empty. Cannot dequeue." << endl;
            return -1;
        }

        int poppedValue = arr[FRONT];

        // *** Initialize all removed elements of the array to -1 *** //
        arr[FRONT] = -1; // Mark as empty

        if (FRONT == REAR) // Queue becomes empty
        {
            FRONT = REAR = -1;
        }
        else
        {
            FRONT = (FRONT + 1) % MAX_SIZE; // Circular increment
        }

        display(); // Show current state of the queue
        return poppedValue;
    }
    // Front: Returns the front element of the queue without removing it
    int front()
    {
        if (FRONT == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[FRONT];
    }

    // Back: Returns the rear element of the queue without removing it
    int back()
    {
        if (REAR == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[REAR];
    }

    // Size: Returns the current number of elements in the queue
    int size()
    {
        if (FRONT == -1)
        {
            return 0; // Queue is empty
        }
        if (REAR >= FRONT)
        {
            return REAR - FRONT + 1;
        }
        return MAX_SIZE - FRONT + REAR + 1; // Wrap around case
    }

    // isEmpty: Checks if the queue is empty
    bool isEmpty()
    {
        return FRONT == -1;
    }

    // Display: Outputs the current state of the queue
    void display()
    {
        if (FRONT == -1)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: [";
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            // *** Represent the element -1 as "-" *** //
            if (arr[i] == -1)
                cout << "- ";
            else
                cout << arr[i] << " ";
        }
        cout << "]" << endl;
    }
};

// Main function to test the Queue class
int main()
{
    Queue q(5);
    int choice, value;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Back\n";
        cout << "5. Size\n";
        cout << "6. Check if Empty\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            cout << "Dequeued value: " << q.dequeue() << endl;
            break;

        case 3:
            cout << "Front element: " << q.front() << endl;
            break;

        case 4:
            cout << "Back element: " << q.back() << endl;
            break;

        case 5:
            cout << "Queue size: " << q.size() << endl;
            break;

        case 6:
            cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
            break;

        case 7:
            q.display();
            break;

        case 8:
            cout << "Exiting the program..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }

    return 0;
}
