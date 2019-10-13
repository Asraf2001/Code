#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct stack
{
 int data;
 struct stack *next;
};
 struct stack *top=NULL;
 struct stack *push(struct stack*,int);
 struct stack *pop(struct stack*);
 struct stack *display(struct stack*);
 void main()
{
 int val,op;
 clrscr();
 do
 {
  printf("\n1.push\n2.pop\n3.display\n4.exit\n");
  printf("Enter your choice");
  scanf("%d",&op);
  switch(op)
  {
   case 1:
	  printf("To be pushed");
	  scanf("%d",&val);
	  top=push(top,val);
	  break;

   case 2:
	  top=pop(top);
	  break;

   case 3:
	  top=display(top);
	  break;

   case 4:
	  exit(0);
	  break;
   }
  }
  while(op!=5);
  getch();
}
  struct stack *push(struct stack*top,int val)
  {
   struct stack *ptr;
   ptr=(struct stack*)malloc(sizeof(struct stack));
   ptr->data=val;
   if(top==NULL)
{
  ptr->next=NULL;
  top=ptr;
}
 else
{
 ptr->next=top;
 top=ptr;
 }
 return top;
 }
 struct stack *pop(struct stack *top)
 {
  struct stack *ptr;
  ptr=top;
  if(top==NULL)
  printf("Under flow");
  else
  top=top->next;
  printf("The delete value is %d",ptr->data);
  free(ptr);
 return top;
 }
  struct stack *display(struct stack *top)
 {
  struct stack *ptr;
  ptr=top;
  if(top==NULL)
  printf("Stact is empty");
  else
  {
   while(ptr!=NULL)
  {
   printf("\n%d",ptr->data);
   ptr=ptr->next;
  }
  }
  return 0;
 }