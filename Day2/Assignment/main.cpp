#include "ll.h"


int main () {   
    element *head = genLL(3);
    
    add2list(head,5);

    printMeList(head);

    head = removeFromHead(head);

    std::cout << "----------------- " << std::endl;

    printMeList(head);

    deleteLL(head);


    return 0;
}