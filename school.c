#include "school.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define NEW 1
#define DELETE 2
#define PRINT 3
#define EDIT 4
#define RANK 5
#define SCORE 6

void CLRATE (List *l){ //Done
    l->head=NULL;
    l->tail=NULL;
}
bool ISEMPTY (List *l){//Done
return (l->head==NULL);
}
void MAIN_MENU (List *l){//Done
int choice,again;

do{
printf("=================================\n");
printf("Welcome to school\n");
printf("=================================\n");
printf("Choices\n1-New student\n2-Delete student\n3-Print students list\n4-Edit student\n5-Print rank list\n6-Score\n");
printf("=================================\n");
printf("Enter your choice\n");
scanf("%d",&choice);
printf("=================================\n");
switch(choice)
{
case NEW:
    NEW_STUDENT(l);
    printf("Enter 1 to see the menu again 0-To exit\n");
    scanf("%d",&again);
    break;
case DELETE:
    DELETE_STUDENT(l);
    printf("Enter 1 to see the menu again 0-To exit\n");
    scanf("%d",&again);
    break;
case PRINT:
    STUDENT_LIST(l);
    printf("Enter 1 to see the menu again 0-To exit\n");
    scanf("%d",&again);
    break;
case EDIT:
    STUDENT_EDIT(l);
    printf("Enter 1 to see the menu again 0-To exit\n");
    scanf("%d",&again);
    break;
case RANK:
    RANK_STUDENT(l);
    printf("Enter 1 to see the menu again 0-To exit\n");
    scanf("%d",&again);
    break;
case SCORE:
    STUDENT_SCORE(l);
    printf("Enter 1 to see the menu again 0-To exit\n");
    scanf("%d",&again);
    break;
default:
    printf("wrong choise\n");
    break;
}
}while(again);
}
void NEW_STUDENT(List *l){//Done

    int id;
    int phone;
    int score;
    char* name[15];
    char* date[10];
    char* address[20];
    printf("Enter id ,phone number ,score ,name ,date and address\n ");
    scanf("%d",&id);
    scanf("%d",&phone);
    scanf("%d",&score);
    scanf("%s",name);
    scanf("%s",date);
    scanf("%s",address);
//step 1: Create place to hold data
student*pn =(student*)malloc(sizeof(student));
if(pn == NULL)
 {
     printf("Heap is Full\n");
     return;
 }
 //step 2: Initialize Node
 pn->id=id;
 pn->phone=phone;
 pn->score=score;
 strcpy(pn->name,name);
 //pn->name=&name;
 strcpy(pn->date,date);
 //pn->date=&date;
 strcpy(pn->address,address);
 //pn->address=&address;

 pn->prev=NULL;
 pn->next= NULL;

 //step 3 : Insert Node in List
// pl->listSize++;
 if(ISEMPTY(l)) // List is Empty
 {
     l->head = pn;
     l->tail = pn;
 }
 else // List is Not Empty
 {
     // e = 5 , temp->data =  10
    student * temp = l->head;//init
     while(temp != NULL && strcmp(pn->name,temp->name)<0)// condition
     {
        temp = temp->next;
     }
     if(temp == l->head )// Insert at head
     {
         pn->next = l->head; //step 1 : assign old head as new node next
         l->head->prev = pn; // step 2: assign new node as old head prev
         l->head = pn;       //step 3: updat head
     }
     else if(temp == NULL)//Insert at tail
     {
         pn->prev = l->tail;//step 1
         l->tail->next = pn;//step 2
         l->tail = pn; //step 3

     }
     else //insert at any where else ( at middle )
     {
       pn->next = temp; //step 1
       pn->prev = temp->prev;// step 2
       temp->prev->next= pn;//step 3 // pn->pPrev->pNext = pn
       temp ->prev = pn;//step 4

     }

 }
 #if(ENABLE_DEBUGGING == ENABLE)
    printf("\nStudent is inserted\n");
 #endif

}
void DELETE_STUDENT(List *l){//Done
int id;
printf("Enter the id\n");
scanf("%d",&id);
  //step 1:  search for data(ID)
  if(ISEMPTY(l))
  {
      printf("List is Empty\n");
      return;
  }
  student*temp =  SEARCH(l,id);
  if(temp == NULL)
  {
      printf("ID not found\n");
  }
  else // Found
  {
      if( l->head == l->tail) //only node
      {
           free(l->head);
           l->head = NULL;
           l->tail = NULL;

      }
      else if(temp == l->head)
      {
          //step 1: assign NULL to prev of old head next
          l->head->next->prev = NULL;
          //step 2: assign new head to be its next
          l->head = l->head->next;
          //step 3: free old head using copy (temp)
          free(temp);
      }
      else if(temp == l->tail)
      {
        //step 1: assign Null to next of old tail prev
        l->tail->prev->next = NULL;
        //step 2: assign new tail to be its prev
        l->tail = l->tail->prev;
        //step 3: free old tail using copy (temp)
        free(temp);
      }
      else
      {
          //step 1:
          temp ->prev->next = temp->next;
          //step 2:
          temp->next->prev = temp->prev;
          //step 3: free temp
          free(temp);
      }
#if(ENABLE_DEBUGGING == ENABLE)
    printf("\nStudent is deleted\n\n");
 #endif
   //pl->listSize--;
  }//else Not Empty
}
void STUDENT_LIST(List *l){//Done
if(ISEMPTY(l))
    {
        printf("List is Empty\n");
        return;
    }
    student *temp;
    for(temp = l->tail;temp!= NULL;temp = temp->prev)
    {
        printf("ID = %d \nName = %s \nDate = %s \nPhone = %d \nAdress = %s \nScore = %d \n=============\n",
               temp->id,temp->name,temp->date,temp->phone,temp->address,temp->score);
    }
}
void STUDENT_EDIT(List *l){//Done
    int id;
    int phone;
    int score;
    char* address[20];
    printf("Enter the id\n");
    scanf("%d",&id);
    printf("Enter the new address,score and phone\n");
    scanf("%s",address);
    scanf("%d",score);
    scanf("%s",phone);
    student * temp;
    if(ISEMPTY(l))
    {
        printf("List is Empty\n");
        return NULL;
    }
    else
    {
        temp =l->head;
       while(temp!= NULL && temp->id != id)
       {
           temp = temp->next;
       }
         temp;
    }
if(temp!=NULL)
{
    //strcpy(temp->name,name);
    //strcpy(temp->date,date);
    temp->phone=phone;
    strcpy(temp->address,address);
    temp->score=score;
}
}
void RANK_STUDENT(List *l){

TreeNodePtr rootPtr = NULL;
if(ISEMPTY(l))
    {
        printf("List is Empty\n");
        return;
    }
    student *temp;
    for(temp = l->tail;temp!= NULL;temp = temp->prev)
    {
       insertNode(&rootPtr,temp);
    }
    inOrder(rootPtr);


/*
    student *current = NULL, *index = NULL;
    student temp;
    //Check whether list is empty
    if(l->head == NULL) {
        return;
    }
    else {
        //Current will point to head
        for(current = l->head; current->next != NULL; current = current->next) {
            //Index will point to node next to current
            for(index = current->next; index != NULL; index = index->next) {
                //If current's data is greater than index's data, swap the data of current and index
                if(current->score > index->score) {

                    temp.score = current->score;
                    temp.id=current->id;
                    temp.phone=current->phone;
                    strcpy(temp.name,current->name);
                    strcpy(temp.date,current->date);
                    strcpy(temp.address,current->address);

                    current->score = index->score;
                    current->id = index->id;
                    current->phone = index->phone;
                    strcpy(current->name,index->name);
                    strcpy(current->date,index->date);
                    strcpy(current->address,index->address);


                    index->score = temp.score;
                    index->id = temp.id;
                    index->phone = temp.phone;
                    strcpy(index->name,temp.name);
                    strcpy(index->date,temp.date);
                    strcpy(index->address,temp.address);

                }
            }
        }
    }
    student *temp1;
    for(temp1 = l->tail;temp1!= NULL;temp1 = temp1->prev)
    {
        printf("ID = %d \nName = %s \nDate = %s \nPhone = %d \nAdress = %s \nScore = %d \n=============\n",
               temp1->id,temp1->name,temp1->date,temp1->phone,temp1->address,temp1->score);

    }
    */

}
void STUDENT_SCORE(List *l){
    int i=0;
    int score;
  if(ISEMPTY(l))
    {
        printf("List is Empty\n");
        return;
    }
    student *temp;
    for(temp = l->tail;temp!= NULL;temp = temp->prev)
    {
        printf("Enter score for student no %d\n",++i);
        scanf("%d",&score);
        temp->score=score;

    }
}
student* SEARCH(List*l,int id){//Done


    if(ISEMPTY(l))
    {
        printf("List is Empty\n");
        return NULL;
    }
    else
    {
       student * temp =l->head;
       while(temp!= NULL && temp->id != id)
       {
           temp = temp->next;
       }
        return temp;
    }

}
void insertNode( TreeNodePtr *treePtr, student*value  ){
    /* if tree is empty */
	 if ( *treePtr == NULL ) {
		 *treePtr =(TreeNode*) malloc( sizeof( TreeNode ) );

		 /* if memory was allocated then assign data */
		 if ( *treePtr != NULL ) {
			 ( *treePtr )->id = value->id;
			 ( *treePtr )->phone = value->phone;
			 ( *treePtr )->score = value->score;
			 strcpy(( *treePtr )->name , value->name);
			 strcpy(( *treePtr )->address , value->address);
			 strcpy(( *treePtr )->date , value->date);
			 ( *treePtr )->leftPtr = NULL;
			 ( *treePtr )->rightPtr = NULL;
		 } /* end if */
		 else {
		     printf( "value  not inserted. No memory available.\n");
		 } /* end else */
	 } /* end if */
	 else { /* tree is not empty */

		/* data to insert is less than data in current node */
		if ( value->score > ( *treePtr )->score ) {
			insertNode( &( ( *treePtr )->leftPtr ), value );
		} /* end if */
		/* data to insert is greater than data in current node */
		else if ( value->score < ( *treePtr )->score ) {
			insertNode( &( ( *treePtr )->rightPtr ), value );
		} /* end else if */
		else { /* duplicate data value ignored */
 			printf( "dup" );
 		} /* end else */
 	} /* end else */

}
void inOrder( TreeNodePtr treePtr ){
    /* if tree is not empty then traverse */
	if ( treePtr != NULL ) {
	inOrder( treePtr->leftPtr );


	printf( "id = %d\n", treePtr->id );
	printf( "name = %s\n", treePtr->name );
	printf( "date = %s\n", treePtr->date );
	printf( "%d\n", treePtr->phone );
	printf( "%s\n", treePtr->address );
	printf( "%d\n=============\n", treePtr->score );
	inOrder( treePtr->rightPtr );
	} /* end if */
}
