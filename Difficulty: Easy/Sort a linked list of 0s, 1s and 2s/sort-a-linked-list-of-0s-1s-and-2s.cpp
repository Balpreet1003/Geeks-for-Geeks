//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        if (!head || !head->next) return head; 
        
        Node *z = NULL, *o = NULL, *t = NULL;     
        Node *zh = NULL, *oh = NULL, *th = NULL;   
        
        Node *h = head;
        while (h) {
            if (h->data == 0) {
                if (!zh) {
                    zh = h;
                    z = h;
                } else {
                    z->next = h;
                    z = z->next;
                }
            } else if (h->data == 1) {
                if (!oh) {
                    oh = h;
                    o = h;
                } else {
                    o->next = h;
                    o = o->next;
                }
            } else { 
                if (!th) {
                    th = h;
                    t = h;
                } else {
                    t->next = h;
                    t = t->next;
                }
            }
            h = h->next;
        }
        if (z) z->next = oh;     
        else zh = oh;             
        
        if (o) o->next = th;      
        else if (zh) z->next = th; 
        
        if (t) t->next = NULL;  
        
        return zh ? zh : (oh ? oh : th);
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends