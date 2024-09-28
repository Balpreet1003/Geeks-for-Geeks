//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/


class Solution {
    Node* reverseList(Node* head) {
        Node *nextNode, *prevNode = NULL;
        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }
  public:
    Node* addOne(Node* head) {
        if(!head->next){
            int r=(head->data+1)/10;
            head->data=(head->data+1)%10;
            if(r!=0){
                head->next=new Node(r);
            }
            head=reverseList(head);
            return head;
        }
        head=reverseList(head);
        int r=(head->data+1)/10;
        head->data=(head->data+1)%10;
        Node*t=head->next;
        while(t->next){
            int x=t->data+r;
            r=x/10;
            t->data=x%10;
            t=t->next;
        }
        int x=t->data+r;
        r=x/10;
        t->data=x%10;
        if(r!=0){
            t->next=new Node(r);
        }
        head=reverseList(head);
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends