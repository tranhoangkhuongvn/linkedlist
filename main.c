//
//  main.c
//  linkedlist1
//
//  Created by Khuong Tran on 8/13/17.
//  Copyright © 2017 Khuong Tran. All rights reserved.
//

#include <stdio.h>
#include "linkedlist.h"
#include <stdlib.h>
#include <assert.h>

//Linked list functions
int length(node* list);
node* BuildList3(void);
void Push(node** list, int data);
void DeleteList(node** list);
int Pop(node** list);
int GetNth(node** list, int index);
void InsertNth(node** list, int index, int data);

int main(int argc, const char * argv[])
{
    // insert code here...
    printf("This program demonstrates how to work with list\n");
    
    node* start = BuildList3();
    printf("The first node: %d\n", start->data);
    printf("The length of list: %d\n", length(start));
    
    Push(&start, 9);
    printf("Adding in...\n");
    printf("The new first node: %d\n", start->data);
    printf("The length of new list: %d\n", length(start));
    printf("The second node is: %d\n", GetNth(&start, 1));
    printf("The third node is: %d\n", GetNth(&start, 2));
    
    printf("Inserting...\n");
    InsertNth(&start,0,8);
    InsertNth(&start,2,7);
    printf("The length of new list: %d\n", length(start));
    printf("The second node is: %d\n", GetNth(&start, 1));
    printf("The third node is: %d\n", GetNth(&start, 2));
    
    
    //DeleteList(&start);
    //printf("The list length is: %d\n", length(start));
    //printf("The first element is: %d\n", Pop(&start));
    //printf("The second element is: %d\n", Pop(&start));
    //printf("The third element is: %d\n", Pop(&start));
    //printf("The next element is: %d\n", Pop(&start));
    //printf("Hey have we reached the end? %d\n", Pop(&start));
    //printf("The list length now is: %d\n", length(start));
    return 0;
}

void InsertNth(node** list, int index, int data)
{
    node* current = *list;
    int count = 0;
    while(current != NULL)
    {
        if(index == 0)
        {
            Push(&(*list),data);
            return;
        }
        else if(count == index-1)
        {
            node* newNode = malloc(sizeof(node));
            newNode->data = data;
            newNode->next = current->next;
            (*current).next = newNode;
        }
        count++;
        current = current->next;
    }
}

int GetNth(node** list, int index)
{
    int count = 0;
    node* current = *list;
    while(current != NULL)
    {
        if(count == index)
        {
            return current->data;
        }
        count++;
        current = current->next;
    }
    printf("Out of range\n");
    return -1;
}

int Pop(node** list)
{
    int data;
    node* current = *list;
    assert(current != NULL);
    *list = current->next;
    data = current->data;
    free(&(*current));
    return data;
}
void DeleteList(node** list)
{
    node* current = *list;
    while(current!=NULL)
    {
        printf("Deleting node: %d\n", current->data);
        free(&(*current));
        current = current->next;
    }
    *list = NULL;
}
void Push(node** list, int data)
{
    //node* current = *list;
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = *list;
    *list = newNode;
}
int length(node* list)
{
    int len = 0;
    node* current = list;
    while(current != NULL)
    {
        current = current->next;
        len++;
    }
    return len;
}

node* BuildList3()
{
    node* first;
    node* second;
    node* third;
    
    first = malloc(sizeof(node));
    second = malloc(sizeof(node));
    third = malloc(sizeof(node));
    
    first->data = 1;
    first->next = second;
    
    second->data = 2;
    second->next = third;
    
    third->data = 3;
    third->next = NULL;
    
    return first;
}
