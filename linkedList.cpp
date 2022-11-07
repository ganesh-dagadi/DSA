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
            cout << this->data << endl;
            node* temp = this;
            while(temp->link != NULL){
                temp = temp->link;
                cout << temp->data << endl;
            }       
        }
    };

    node* linkedList = new node(5);
    linkedList->insertAtEnd(10);
    linkedList->insertAtEnd(20);
    linkedList->insertBeginning(linkedList , 40);
    linkedList->printElements();
    return 0;
}
