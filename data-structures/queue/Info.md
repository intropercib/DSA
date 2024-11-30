#### >> Link to

- [Front fixed and Rear varying Queue](code1.cpp)
- [Front and Rear varying Queue](code2.cpp)
- [Circular Queue](code3.cpp)

# Queue

A **queue** is a linear data structure following the **First In, First Out (FIFO)** principle. It manages elements using two primary pointers: **head** (front) and **tail** (rear), which track the first and last elements in the queue.

#### **Queue Pointer Variation Types**

Queues can be implemented with different pointer management strategies:

### 1. Front pointer fixed and Rear pointer varying

- Head pointer remains at a fixed position (typically the start of the array)
- Tail pointer moves as elements are added
- Elements are added at the tail and removed from the head
- Remember: Add elements to the rear, remove from the front and the position of front is not changed so swapping is done

```plaintext
Initial: [ ][ ][ ][ ][ ]  (Head at 0)
Add 1:   [1][ ][ ][ ][ ]
Add 2:   [1][2][ ][ ][ ]
Add 3:   [1][2][3][ ][ ]
Remove:  [ ][2][3][ ][ ]  (First element removed)
         [2][3][ ][ ][ ]  (Head moves to the right)
```

### 2. Both Head and Tail Pointers Varying

- Both head and tail pointers can move
- Provides more flexibility in managing queue space

```plaintext
Initial: [ ][ ][ ][ ][ ]  (Head at 0)
Add 1:   [1][ ][ ][ ][ ]
Add 2:   [1][2][ ][ ][ ]
Add 3:   [1][2][3][ ][ ]
Remove:  [ ][2][3][ ][ ]  (First element removed incrementing head)
```

### 3. Circular queue

- In circular queue, the rear can move to the front of the queue
- This allows for efficient use of space in a fixed-size array

## Workflow

### 1. Initial State

```
Array Size: 5
Initial Array: [ ][ ][ ][ ][ ]
Front Pointer: -1
Rear Pointer: -1
```

### 2. First Insertion (Enqueue)

```
Enqueue(10)
Array:    [10][ ][ ][ ][ ]
           ↑
      Front/Rear = 0
```

### 3. Subsequent Insertions

```
Enqueue(20): [10][20][ ][ ][ ]
               ↑   ↑
            Front Rear = 1

Enqueue(30): [10][20][30][ ][ ]
              ↑       ↑
           Front    Rear = 2

Enqueue(40): [10][20][30][40][ ]
              ↑           ↑
           Front        Rear = 3

Enqueue(50): [10][20][30][40][50]
              ↑               ↑
           Front            Rear = 4
```

### 4. First Dequeue Operation

```
Dequeue():
- Removes first element (10)
Array:    [ ][20][30][40][50]
              ↑            ↑
          Front            Rear
```

### 5. Circular Insertion (Wrapping Around)

```
Enqueue(60):
Array:    [60][20][30][40][50]
            ↑   ↑
          Rear Front
```

## Pointer Movement Rules

1. Enqueue:
   - `rear = (rear + 1) % size`
2. Dequeue:
   - `front = (front + 1) % size`

## Visualization of Circular Movement

```
Initial:    [ ][ ][ ][ ][ ]
            ↑
           Front/Rear

First Fill: [10][20][30][40][50]
             ↑               ↑
           Front            Rear

Wrap Around:[60][20][30][40][50]
             ↑   ↑
           Rear Front
```

### **Key Queue Operations in C++**

In C++, queues can be implemented using the **Standard Template Library (STL)** or through custom implementations.

#### 1. **Push (Enqueue)**

- **Description**: Adds an element to the rear of the queue
- **Syntax (STL)**:
  ```cpp
  queue<int> q;
  q.push(10); // Adds 10 to the queue
  ```

#### 2. **Pop (Dequeue)**

- **Description**: Removes the front element from the queue
- **Syntax (STL)**:
  ```cpp
  q.pop(); // Removes the front element
  ```

#### 3. **Front**

- **Description**: Returns the front element without removing it
- **Syntax (STL)**:
  ```cpp
  int frontElement = q.front(); // Access the front element
  ```

#### 4. **Back**

- **Description**: Returns the rear element without removing it
- **Syntax (STL)**:
  ```cpp
  int rearElement = q.back(); // Access the rear element
  ```

#### 5. **Empty**

- **Description**: Checks if the queue is empty
- **Syntax (STL)**:
  ```cpp
  if (q.empty()) {
      cout << "Queue is empty\n";
  }
  ```

#### 6. **Size**

- **Description**: Returns the number of elements in the queue
- **Syntax (STL)**:
  ```cpp
  int size = q.size(); // Get the size of the queue
  ```
