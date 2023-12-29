#include <stdio.h>
#include <stdlib.h>

struct node_
{
    int val;
    struct node_ *next;
};

struct node_ *initializeFirstEle(int no, struct node_ *linkList)
{	 
	 linkList->val = no;
	 return linkList;
}

struct node_ *pushHead_(int no, struct node_ *linkList)
{
	 if(linkList->val == 0)
	 {
		  return initializeFirstEle(no, linkList);
	 }

	 struct node_ *new_ = malloc(sizeof(struct node_));
	 new_->val = no; // or (*new_).val de reference
	 new_->next = linkList;
	 linkList = new_;
	 return linkList;
}

struct node_ *pushTail_(int no, struct node_ *linkList)
{
	 if(linkList->val == 0)
	 {
		  return initializeFirstEle(no, linkList);
	 }

	 struct node_ *new_ = malloc(sizeof(struct node_));
	 new_->val = no;
	 // new_->next = NULL;

	 struct node_ *curr = linkList;
	 while (curr->next != NULL)
	 {
		  // printf("%d ", curr->val);
		  curr = curr->next;
		  /* code */
	 }

	 curr->next = new_;
	 // curr = new_;

	 // linkList->next = curr;
	 return linkList;
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

void menu(struct node_ *list) {
	 char input;
	 printf("\nPlease enter\n a for head\n z for tail\n p for print the list\n q for quit: ");
	 scanf("%c", &input);
	 int in;

	 switch(input) {
		  case 'q': return;
		  case 'a': 
				printf("\nEnter value = ");
				scanf("%d", &in);
				list = pushHead_(in, list);
				break;
		  case 'z': 
				printf("\nEnter value = ");
				scanf("%d", &in);
				pushTail_(in, list);
				break;
		  case 'p': 
				print_(list);
				break;
		  default: 
				printf("\nPlease enter a valid value a, z, p or q only!\n");
				// break;
	 }
	 menu(list);
}

int main() {

	 struct node_ *list = malloc(sizeof(struct node_));
	 menu(list);
	 /*
	    list = pushHead_(12, list);
	    list = pushHead_(16, list);
	    pushTail_(15, list);
	    pushTail_(19, list);
	    print_(list);
	    */
}

/*
	 int a;
	 char b;
	 if(b == NULL) {
	 printf("a = %d b = %c /n", a, b);
	 }
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
