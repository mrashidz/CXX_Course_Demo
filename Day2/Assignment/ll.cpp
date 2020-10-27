#include "ll.h"

element *genLL(const int &val) {
    element *head = new element;
    head->Next = nullptr;
    head->Value = val;
    return head;
}

void deleteLL(element *head) {
    element *temp = head,*temp2;

    while (temp != nullptr) { 
        temp2 = temp->Next;
        delete temp;
        temp = temp2;
    } 
}

element *removeFromHead(element *head) {
    element *newHead = nullptr;
    if (head != nullptr) {
        newHead = head->Next;
        delete head;
    }
    return newHead;   
}

void printMeList(element *head ) {
    element *temp = head;
    while (temp != nullptr) {
        std::cout << "Value is: " << temp->Value << std::endl;    
        temp = temp->Next;
    } 
}

element *findtail(element *head) {
    element *temp = head;
    while (temp->Next != nullptr) {
        temp = temp->Next;
    }
    return temp;
}


void add2list(element *head, const int &val) {
    element *tail = findtail(head);
    element *ne3 = new element;
    tail->Next = ne3;    
    ne3->Next = nullptr;
    ne3->Value = val;
    /*
    1) find the tail
    2) create an element 
    3) put the new element as the next of my tail
    4) nullify tail with Value=val
    */

   
}


