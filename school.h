#ifndef _SCHOOL_H
#define _SCHOOL_H
#include <stdbool.h>
// structs
typedef struct student
{
    int id;
    int phone;
    int score;
    char* name[15];
    char* date[10];
    char* address[20];
    struct student*next;
    struct student*prev;
}student;

typedef struct List
{
student*head;
student*tail;
}List;

struct treeNode {
    struct treeNode *leftPtr; /* pointer to left subtree */
    int id;
    int phone;
    int score;
    char* name[15];
    char* date[10];
    char* address[20]; /* node value */
    struct treeNode *rightPtr; /* pointer to right subtree */
}; /* end structure treeNode */


 typedef struct treeNode TreeNode; /* synonym for struct treeNode */
 typedef TreeNode* TreeNodePtr; /* synonym for TreeNode* */ /* TreeNodePtr <=> struct treeNode*  */

// functions

void CLRATE (List *l);
bool ISEMPTY (List *l);
void MAIN_MENU (List *l);
void NEW_STUDENT(List *l);
void DELETE_STUDENT(List *l);
void STUDENT_LIST(List *l);
void STUDENT_EDIT(List *l);
void RANK_STUDENT(List *l);
void STUDENT_SCORE(List *l);
student* SEARCH(List*l,int id);
void insertNode( TreeNodePtr *treePtr, student*value  ); // change
void inOrder( TreeNodePtr treePtr );
#endif // _SCHOOL_H
