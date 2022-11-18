#include <iostream>
using namespace std;

class node {
        public:
        int data;
        node *link;

        node(int val){
            data = val;
            link = NULL;
        }

        void insertBeginning(node* &head , int val){
            node* newNode = new node(val);
            newNode->link = head;
            head = newNode;
        }

        void insertAtEnd(int val){
            node* temp = this;
            while(temp->link != NULL){
                temp = temp->link;
            }
            node* newNode = new node(val);
            temp->link = newNode;
        }

        void printElements(){
            cout << this->data << ">>";
            node* temp = this;
            while(temp->link != NULL){
                temp = temp->link;
                cout << temp->data << ">>";
            }
            cout << endl;   
        }

        void deleteHead(node* &head){
            node * toDel = head;
            head = head->link;
            delete toDel;
        }
        void deleteVal(int val){
            node* temp = this;
            while(temp->link->data != val){
                temp=temp->link;
            }
            node* toDel = temp->link;
            temp->link = temp ->link -> link;
            delete toDel;
        }

        void reverseIter(node* &head){
            node* prev = NULL;
            node* curr = head;
            node* next = head->link;
            while(next->link != NULL){
                curr->link = prev;
                prev = curr;
                curr = next;
                next = next->link;
            }
            head = next;
            curr->link = prev;
            head->link = curr;
        }

        node* reverseKNodes(node* &head , int k){
            node* prev = NULL;
            node* curr = head;
            node* next;

            int count = 0;
            while(curr != NULL && count < k){
                next = curr->link;
                curr->link = prev;
                prev = curr;
                curr = next;
                count++;
            }
            if(next != NULL){
                head-> link = reverseKNodes(next , k);
            }
            return prev;
        }
    };

bool isCycle(node* head){
    node* slow = head;
    node* fast = head;
    while(fast->link != NULL && fast->link->link != NULL){
        slow = slow->link;
        fast = fast->link->link;
        if(fast == slow){
            return 1;
        }
    }
    return 0;
}

void removeCycle(node* head){
    node* slow = head;
    node* fast = head;
    do{
        slow = slow->link;
        fast = fast->link->link;
    }while(fast != slow);
    fast = head;
    while(slow->link != fast->link){
        fast = fast->link;
        slow = slow->link;
    }
    slow->link = NULL;
}

void makeCycle(node* head , int pos){
    int count = 0;
    node* temp = head;
    node* cycleStart;
    while(temp->link !=NULL){
        if(count == pos){
            cycleStart = temp;
        }
        temp = temp->link;
        count++;
    }
    temp->link = cycleStart;
    cout << cycleStart << endl;
}
int main(){

    node* linkedList = new node(1);
    linkedList->insertAtEnd(2);
    linkedList->insertAtEnd(3);
    linkedList->insertAtEnd(4);
    linkedList->insertAtEnd(5);
    linkedList->insertAtEnd(6);
    linkedList->printElements();
    makeCycle(linkedList , 3);
    cout << isCycle(linkedList) << endl;
    removeCycle(linkedList);
    cout << isCycle(linkedList);
    return 0;
}
