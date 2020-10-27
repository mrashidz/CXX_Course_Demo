//#ifdef _LL_H
//#define _LL_H
#include <iostream>
struct element {
    int      Value;
    element *Next;
};


element *genLL(const int &val);
element *findtail(element *head);
element *removeFromHead(element *head);



void deleteLL(element *head);
void printMeList(element *head);
void removeFromTail(element *head);/* {
    /*
    1) find the tail
    2) delete tail smartly
    3) nullify the one before tail (new tail)

    
}*/
void add2list(element *head, const int &val);


//#endif //_LL_H