#include <bits/stdc++.h>
using namespace std;

/* Approach: Stack 
*/

class MyQueue {
public:

    // Stack is LIFO, Queue is FIFO
    // Hint: If you reverse a STACK, then it behaves like a QUEUE ONLY for pop/peeking

    stack<int> s1;   // s1 stack used for pushing elements
    stack<int> s2;   // s2 stack used for popping / peeking

    MyQueue() {
        // Constructor 
    }
    
    // We simply push to s1, coz order reversal only needed (during pop/peek)
    void push(int x) {
        s1.push(x);  
    }
    
    // Get the front element and remove it
    int pop() {
        // If s2 is empty, 1st transfer(cut not copy) all items from s1 → s2
        if (s2.empty())  
        {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();         // cut
            }
        }
        
        int front = s2.top();  // Now top is the front element
        s2.pop();
        return front;
    }
    
    // Get the front element without removing it
    int peek() {
        // If s2 is empty, 1st transfer(cut not copy) all items from s1 → s2
        if (s2.empty()) {
            while (!s1.empty()) 
            {
                s2.push(s1.top());
                s1.pop();       // cut
            }
        }
        return s2.top();    // Now top is the front element
    }
    
    // Returns whether the queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/***************************************************
 * Time Complexity : O(1)                          *
 * Space Complexity: O(n)                          *
 ***************************************************/

/* Remarks: 
    If you reverse a STACK, then it behaves like a QUEUE ONLY for pop/peeking
*/

/* Question:
    Implement a first in first out (FIFO) queue using only two stacks. The implemented queue 
    should support all the functions of a normal queue (push, peek, pop, and empty).

    Implement the MyQueue class:

    - void push(int x) Pushes element x to the back of the queue.
    - int pop() Removes the element from the front of the queue and returns it.
    - int peek() Returns the element at the front of the queue.
    - boolean empty() Returns true if the queue is empty, false otherwise.

    Notes:

    - You must use only standard operations of a stack, which means only push to top,
      peek/pop from top, size, and is empty operations are valid.

    - Depending on your language, the stack may not be supported natively. You may simulate
      a stack using a list or deque (double-ended queue) as long as you use only a stack's 
      standard operations.
    
    Example 1:

    Input
    ["MyQueue", "push", "push", "peek", "pop", "empty"]
    [[], [1], [2], [], [], []]
    Output
    [null, null, null, 1, 1, false]

    Explanation:
    MyQueue myQueue = new MyQueue();
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.peek(); // return 1
    myQueue.pop(); // return 1, queue is [2]
    myQueue.empty(); // return false
*/