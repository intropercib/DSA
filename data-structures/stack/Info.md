#### >> Link to

- [Top Varying Stack](code1.cpp)
- [Bottom Varying Stack](code2.cpp)

---

# Stack

A **stack** is a linear data structure following the **Last In, First Out (LIFO)** principle. It is managed using a pointer called **top**, which keeps track of the current position where the next element will be added or removed.

---

#### **Concept of Top-Varying and Bottom-Varying Stacks**

The **variation** refers to whether the `top` pointer (or index) moves towards the bottom or away from it as elements are pushed or popped:

1. **Top-Varying Stack || Bottom fixed**:

   - The **top** pointer starts at the **bottom** of the stack (index `-1` or `0`) and **grows upward** as elements are added.
     -The classic stack implementation where elements are added and removed from the top.
   - Remember :: fill from bottom and empty from top
   - Common in array-based implementations.
   - Example:

   ```plaintext
   Initial:  [ ][ ][ ][ ][ ]  (Bottom at 0)
   Add 1:    [ ][ ][ ][ ][1]
   Add 2:    [ ][ ][ ][2][1]
   Add 3:    [ ][ ][3][2][1]
   Pop:      [ ][ ][ ][2][1]  (Element removed)
   ```

2. **Bottom-Varying Stack || Top fixed**:
   - The **top** pointer starts at the **top-most position** (the maximum index, say `n-1`) and **grows downward** as elements are added.
   - Rarely used, but it might be useful when space needs to be shared with another stack in a single array.
   - Remember :: fill from top to bottom(swapping the element) and empty from top
   - Example:
   ```plaintext
    Initial: [ ][ ][ ][ ][ ] (Top at end)
    Add 1:   [1][ ][ ][ ][ ]
    Add 2:   [2][1][ ][ ][ ] (Existing elements shift)
    Add 3:   [3][2][1][ ][ ]
    Pop:     [2][1][ ][ ][ ] (Element removed)
   ```

#### **Key Operations in Stack**

In C++, the **stack** data structure is commonly implemented using the **Standard Template Library (STL)** or through custom implementations. The key operations of a stack are as follows:

---

### **Key Operations**

#### 1. **Push**

- **Description**: Adds an element to the **top** of the stack.
- **Syntax (STL)**:
  ```cpp
  stack<int> s;
  s.push(10); // Adds 10 to the stack
  ```

---

#### 2. **Pop**

- **Description**: Removes the **top** element from the stack.
- **Syntax (STL)**:
  ```cpp
  s.pop(); // Removes the top element
  ```

---

#### 3. **Top (Peek)**

- **Description**: Returns the **top** element of the stack without removing it.
- **Syntax (STL)**:
  ```cpp
  int topElement = s.top(); // Access the top element
  ```

---

#### 4. **Empty**

- **Description**: Checks if the stack is empty.
- **Syntax (STL)**:
  ```cpp
  if (s.empty()) {
      cout << "Stack is empty\n";
  }
  ```

---

#### 5. **Size**

- **Description**: Returns the number of elements in the stack.
- **Syntax (STL)**:
  ```cpp
  int size = s.size(); // Get the size of the stack
  ```

---
