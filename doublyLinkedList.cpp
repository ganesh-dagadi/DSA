#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev = NULL;
    node* next = NULL;
    node(int val){
        data = val;
    }
    void insertAtTail(int val){
        node* temp = this;
        while(temp->next != NULL){
            temp = temp->next;
        }
        node* newNode = new node(val);
        temp->next = newNode;
        newNode->prev = temp;
    }
    void printElements(node* head){
            cout << head->data << ">>";
            node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
                cout << temp->data << ">>";
            }
            cout << endl;   
    }

    void insertAtHead(node* &head , int val){
        node* newNode = new node(val);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void deleteNode(int val){
        node* temp = this;
        while(temp->data != val){
            if(temp->next == NULL) break;
            temp = temp->next;
        }
        if(temp->next == NULL){
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
};

int main(){
    node* linkedL = new node(0);
    linkedL->insertAtTail(1);
    linkedL->insertAtTail(2);
    linkedL->insertAtTail(3);
    linkedL->insertAtTail(4);
    linkedL->insertAtTail(5);
    linkedL->insertAtTail(6);
    linkedL->insertAtTail(7);
    linkedL->printElements(linkedL);
    return 0;
}