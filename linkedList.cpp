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

        int length(){
            node* head = this;
            int l = 0;
            while(head->link != NULL){
                l++;
                head = head->link;
            }
            return l;
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


void appendLastKnodes(node* &head , int k){
    int l = head->length();
    node* temp = head;
    node* newTail; node* newHead;
    int count = 0;
    while(count < l){
        if(count == (l-k)){
            newTail = temp;
            newHead = temp->link;
        }
        temp = temp->link;
        count++;
    }
    temp->link = head;
    newTail->link = NULL;
    head = newHead;
}

int intersectionDetect(node * &head1 , node* &head2){
    int l1 = head1->length();
    int l2 = head2->length();
    int d = 0;
    node* ptr1 ; node* ptr2;
    if(l1 > l2){
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }else{
        d = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d){
        ptr1 = ptr1->link;
        d--;
    }

    while(ptr1->link != NULL && ptr2->link != NULL){
        if(ptr1 == ptr2){
            return ptr1->data;
        }

        ptr1 = ptr1->link;
        ptr2 = ptr2->link;
    }

    return -1;
}
int main(){

    node* linkedL = new node(0);
    linkedL->insertAtEnd(1);
    linkedL->insertAtEnd(2);
    linkedL->insertAtEnd(3);
    linkedL->insertAtEnd(4);
    linkedL->insertAtEnd(5);
    linkedL->insertAtEnd(6);
    linkedL->insertAtEnd(7);
    linkedL->printElements();
    appendLastKnodes(linkedL , 3);
    linkedL->printElements();
    return 0;
}
