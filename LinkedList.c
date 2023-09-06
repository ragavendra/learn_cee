#include <stdio.h>
#include <stdlib.h>

struct node_
{
    int val;
    struct node_ *next;
};

struct node_ *pushHead_(int no, struct node_ *linkList)
{
    struct node_ *new_ = malloc(sizeof(struct node_));
    new_->val = no; // or (*new_).val de reference
    new_->next = linkList;
    linkList = new_;
    return linkList;
}

struct node_ *pushTail_(int no, struct node_ *linkList)
{
    struct node_ *new_ = malloc(sizeof(struct node_));
    new_->val = no;
    // new_->next = NULL;

    struct node_ *curr = linkList;
    while (curr != NULL)
    {
        printf("%d ", curr->val);
        curr = curr->next;
        /* code */
    }

    // curr->next = new_;
    curr = new_;

    return linkList = curr;
}

void print_(struct node_ *list)
{
    struct node_ *curr = list;
    while (curr != NULL)
    {
        printf("%d ", curr->val);
        curr = curr->next;
        /* code */
    }
    
}

int main() {
   struct node_ *list = malloc(sizeof(struct node_));
   struct node_ *ls;
   
   // list->val = 1;
   // list->next = NULL;
   list = pushHead_(12, list);
   list = pushHead_(16, list);
   list = pushTail_(15, list);
   list = pushTail_(19, list);
   print_(list);
}
/*
// Initialize nodes
struct node *head;
struct node *one = NULL;
struct node *two = NULL;
struct node *three = NULL;

// Allocate memory
one = malloc(sizeof(struct node));
two = malloc(sizeof(struct node));
three = malloc(sizeof(struct node));

// Assign data values
one->data = 1;
two->data = 2;
three->data=3;

// Connect nodes
one->next = two;
two->next = three;
three->next = NULL;

// Save address of first node in head 
head = one; */