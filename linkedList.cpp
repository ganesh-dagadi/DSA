#include <iostream>
using namespace std;
int main(){

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
    };

    node* linkedList = new node(5);
    linkedList->insertAtEnd(10);
    linkedList->insertAtEnd(20);
    linkedList->insertAtEnd(20);
    linkedList->insertAtEnd(30);
    linkedList->insertBeginning(linkedList , 40);
    linkedList->printElements();
    // linkedList->deleteHead(linkedList);
    // cout << "After delete" << endl;
    // linkedList->printElements();
    linkedList->reverseIter(linkedList);
    cout << "After reverse \n" << endl;
    linkedList->printElements();
    return 0;
}
