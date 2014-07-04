//
//  LinkedList.c
//  kjhlj
//
//  Created by Ian Fox on 7/4/14.
//  Copyright (c) 2014 ianfox. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
//LinkedList structure
typedef struct Node {
    int value;
    struct Node *nextNode;
} Node;
// merging the Sorted List
Node*  mergeSortedLists(Node * list0, Node * list1)
{
    Node *result = NULL;
    //instantiate Node ref to smallest value
    if (list0 != NULL && list1 != NULL) {
        if (list0->value < list1->value) {
            result = list0;
            list0 = list0->nextNode;
            result->nextNode = mergeSortedLists(list0, list1);
        } else if (list0->value == list1->value){
            result = list0;
            list0 = list0->nextNode;
            result->nextNode = list1;
            list1 = list1 ->nextNode;
            result = result->nextNode;
            result->nextNode = mergeSortedLists(list0, list1);
        } else {
            result = list1;
            list1 = list1->nextNode;
            result->nextNode = mergeSortedLists(list0, list1);
        }
    } else if (list0 != NULL) {
        
        return list0;

    } else  if (list1 != NULL){
        return list1;
       
    }
    return result;
}
void splitLinkedList(Node *list, Node** firstHalf, Node** secondHalf)
{
   
    *firstHalf = list;
    if (list != NULL || list->nextNode != NULL) {
        Node * tortiose = list;
        Node * hare = list->nextNode;
        while (hare != NULL) {
            hare  = hare->nextNode;
            if (hare != NULL) {

                tortiose = tortiose->nextNode;
                hare = hare->nextNode;
            }
        }
        
        *secondHalf = tortiose->nextNode;
        tortiose->nextNode = NULL;
    } else {
        *secondHalf = NULL;
    }
        
}

// sorts the linked list by changing pointers
void MergeSort(Node** list)
{

    Node* head = *list;
    Node* sublist0;
    Node* sublist1;
    if (head == NULL || head->nextNode == NULL) {
        return;
    }
    //split head into sublists
    splitLinkedList(head, &sublist0, &sublist1);
    
    // recursive sort
    MergeSort(&sublist0);
    MergeSort(&sublist1);
    
    *list = mergeSortedLists(sublist0, sublist1);
}



int main ( int arc, char **argv ) {
    Node *result;
    Node *head0 = (Node *)malloc(sizeof(Node));
    Node *next0 = (Node *)malloc(sizeof(Node));
    Node *nextt0 = (Node *)malloc(sizeof(Node));

    
    Node *head1 = (Node *)malloc(sizeof(Node));
    Node *next1 = (Node *)malloc(sizeof(Node));
    Node *nextt1 = (Node *)malloc(sizeof(Node));

    
    head0->nextNode = next0;
    next0->nextNode = nextt0;
    nextt0->nextNode = NULL;
    
    head1->nextNode = next1;
    next1->nextNode = nextt1;
    nextt1->nextNode = NULL;
    
    head0->value = 0;
    next0->value = 2;
    nextt0->value = 4;
    
    head1->value = 1;
    next1->value = 3;
    nextt1->value = 5;
    
    
    result =  mergeSortedLists(head0, head1);
    while (result != NULL) {
        result = result->nextNode;
    }
//    
    head0->nextNode = next0;
    next0->nextNode = nextt0;
    nextt0->nextNode = head1;
    
    head1->nextNode = next1;
    next1->nextNode = nextt1;
    nextt1->nextNode = NULL;
    
    MergeSort(&head0);
    Node * s = head0;
    while (s != NULL) {
        printf("%d", s->value);
        s = s->nextNode;
    }

    
    return 0; // Indicates that everything vent well.
}
