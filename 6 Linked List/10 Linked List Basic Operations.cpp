#include <bits/stdc++.h>
using namespace std;

/* Approach: Linked List 
*/

struct Node
{
    int data;
    Node *next;
};

// Insert at any position, Positions start from 1
void insertAtPosition(Node* &head, int value, int position)
{
    // Create new node
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
                                                     //    newNode
    // Case 1: Insert at beginning (position = 1)    //   ________
    if (position == 1)                               //  |___|____|                                                 //            
    {                                                //          _________       _________
        newNode->next = head;                        //         |____|____| ->  |____|____|
        head = newNode;                              //             head
        return;
    }

    // Case 2: Else Traverse to the (position-1) node to add at position
    // (temp != nullptr) condition is added for corner case when position is greater that length of list
    // Always traverse using temp, so that head still points the 1st node
    Node *temp = head; 
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    // If position is invalid
    if (temp == nullptr)
    {
        cout << "Invalid position" << endl;
        delete newNode;                      //              newNode
        return;                              //             _________
    }                                        //  ________  |____|____|  _________
    else // Insert node                      // |___|____|/           \|____|____| 
    {                                        //  temp
        newNode->next = temp->next;           
        temp->next = newNode;
    }
}

/*========================
  Delete at any position
========================*/
void deleteAtPosition(Node* &head, int position)
{

    // Base case: Empty list
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    // Case 1: Delete first node
    if (position == 1)
    {
        Node *temp = head;    // store current head in temp for later deletion
        head = head->next;
        delete temp;
        return;
    }

    // Case 2: Else Traverse to the (position-1) node to delete at position
    // (temp->next != nullptr) condition is added for corner case when position is greater that length of list
    // Always traverse using temp, so that head still points the 1st node
    Node *temp = head;
    for (int i = 1; i < position - 1 && temp->next != nullptr; i++)
    {
        temp = temp->next;
    }

   // NOTE: for DELETE condition is temp->next != nullptr unlike temp != nullptr in INSERT
   // Insertion only needs a valid current node, but deletion needs both a valid current node 
   // and a valid next node to delete.

    // Invalid position
    if (temp->next == nullptr)
    {
        cout << "Invalid position" << endl;
        return;                               //                                  (position)
    }                                         //     _________      _________      _________
    else // Delete node                       //    |____|____| -> |____|____| -> |____|____|
    {                                         //                    temp 
                    
        Node* nodeToDelete = temp->next;     // store node in nodeToDelete for later deletion   
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
}

/*========================
  Search an element
========================*/
bool searchElement(Node *head, int key)
{
    // Always traverse using temp, so that head still points the 1st node
    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == key)
            return true;
        else    
            temp = temp->next;
    }

    return false;
}

/*========================
  Find length of list
========================*/
int findLength(Node *head)
{
    int count = 0;
    // Always traverse using temp, so that head still points the 1st node
    Node *temp = head;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

/*========================
  Print the list
========================*/
void printList(Node *head)
{
    // Always traverse using temp, so that head still points the 1st node
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

/*========================
  Main function
========================*/
int main()
{
    Node *head = nullptr; // Empty list

    insertAtPosition(head, 10, 1); // 10
    insertAtPosition(head, 20, 2); // 10 -> 20
    insertAtPosition(head, 30, 3); // 10 -> 20 -> 30
    insertAtPosition(head, 15, 2); // 10 -> 15 -> 20 -> 30

    cout << "Linked List: ";
    printList(head);

    // Length of list
    cout << "Length of list: " << findLength(head) << endl;

    // Search element
    int key = 20;
    if (searchElement(head, key))
        cout << key << " found in list\n";
    else
        cout << key << " not found in list\n";

    // Delete at position
    deleteAtPosition(head, 2); // Delete 15

    cout << "After deletion: ";
    printList(head);

    return 0;
}

/**************************************************************************
 * Time Complexity :                                                      *
 * Space Complexity:                                                      *
 **************************************************************************/

/* Remarks:

    1. Here the node position starts from 1

    2. Always pass the 'head pointer' to all the functions

    3. In only insert and delete functions, use "reference of a pointer variable" for head (i.e,) "Node* &head"
*/

/* Question:

*/
