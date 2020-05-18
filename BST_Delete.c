//https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/ Used this link as reference
//Modify Fig. 12.19 to use delete function 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
/* self-referential structure */                            
struct treeNode {                                           
  struct treeNode *leftPtr;  /* pointer to left subtree */ 
  int data; /* node value */                               
  struct treeNode *rightPtr; /* pointer to right subtree */  
}; /* end structure treeNode */                             

typedef struct treeNode TreeNode; /* synonym for struct treeNode */
typedef TreeNode *TreeNodePtr; /* synonym for TreeNode* */

/* prototypes */
void insertNode( TreeNodePtr *treePtr, int value);
void deleteNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

   /* function main begins program execution */
int main(void) {

  //headline 
  printf("BINARY TREE DELETE");
  printf("\n");
  printf("------------------");
  printf("\n");

  int i; /* counter to loop from 1-10 */
  int item; /* variable to hold random values */
  int del; 
  TreeNodePtr rootPtr = NULL; /* tree initially empty */

  srand( time( NULL ) );
  printf( "The numbers being placed in the tree are:\n" );

  /* insert random values between 0 and 14 in the tree */
  for ( i = 1; i <= 10; i++ ) {
      item = rand() % 15;
      printf( "%3d", item );
      insertNode( &rootPtr, item );
  } /* end for */

  /* traverse the tree preOrder */
  printf( "\n\nThe preOrder traversal is:\n" );
  preOrder( rootPtr );

  /* traverse the tree inOrder */
  printf( "\n\nThe inOrder traversal is:\n" );
  inOrder( rootPtr );

  /* traverse the tree postOrder */
  printf( "\n\nThe postOrder traversal is:\n" );
  postOrder( rootPtr );
  printf("\n");

  //input
  printf("\nChoose the node to delete: "); 
	scanf("%d", &del);                      
	deleteNode(&rootPtr, del);               

  //traversing the trees after the deletion of a node 
  printf("\nTraversal of tree after deletion of chosen node\n");
  printf("-----------------------------------------------\n");

  // traverse the tree preOrder again 
  printf("\nThe preOrder traversal is:\n");
	preOrder(rootPtr );

  //traverse the tree inOrder again
	printf("\n\nThe inOrder traversal is:\n");
	inOrder(rootPtr);

  //traverse the tree postOrder again
	printf("\n\nThe postOrder traversal is:\n");
	postOrder(rootPtr);

  return 0; /* indicates successful termination */
} /* end main */

/* insert node into tree */
void insertNode( TreeNodePtr *treePtr, int value )
{
  /* if tree is empty */
  if ( *treePtr == NULL ) {
    *treePtr = malloc( sizeof( TreeNode ) );

    /* if memory was allocated then assign data */
    if ( *treePtr != NULL ) {
      ( *treePtr )->data = value;
      ( *treePtr )->leftPtr = NULL;
      ( *treePtr )->rightPtr = NULL;
    } /* end if */
    else {
      printf( "%d not inserted. No memory available.\n", value );
    } /* end else */
  } /* end if */
  else {/* tree is not empty */
    /* data to insert is less than data in current node */
    if ( value < ( *treePtr )->data ) {                   
      insertNode( &( ( *treePtr )->leftPtr ), value );   
    } /* end if */                                        

    /* data to insert is greater than data in current node */
    else if ( value > ( *treePtr )->data ) {                 
      insertNode( &( ( *treePtr )->rightPtr ), value );     
    } /* end else if */                                      
    else {/* duplicate data value ignored */
      printf( "dup" );
    } /* end else */
  } /* end else */
} /* end function insertNode */

//created/modified delete function 
//delete node from tree, have to consider four cases: 0 child, 1 child(left), 1 child(right), and 2 children
void deleteNode(TreeNodePtr *treePtr, int value) {

  //current pointer 
	TreeNodePtr currentPtr = *treePtr;
  //parent pointer 
  TreeNodePtr *parentPtr = treePtr;      
        
  //iterates long as currentPtr is not NULL 
  while(currentPtr != NULL) {

    //value in left tree  
    if(currentPtr->data > value) {
			parentPtr = &(currentPtr->leftPtr);   
			currentPtr = currentPtr->leftPtr;
    }
      
    //value in right tree 
    else if(currentPtr->data < value) {
		  parentPtr = &(currentPtr->rightPtr);  
			currentPtr = currentPtr->rightPtr; 
    }

    //breaks if found    
	  else {
			break;  
		}
	}

  //returns NULL if not found 
	if(currentPtr == NULL) {
		printf("NULL\n");
        return;
  }

  //in case tree is empty 
	TreeNodePtr deleteNode = NULL;

	deleteNode = currentPtr;  

  //handles case where no child 
  if(currentPtr->rightPtr == NULL && currentPtr->leftPtr == NULL) {
    
    //one child(left)
    //if left is NOT null, parent to left
		if(currentPtr->rightPtr != NULL) {
      *parentPtr = currentPtr->rightPtr;    
    }

    //one child(right)
    //if right is NOT null, parent to right 
		else {
			*parentPtr = currentPtr->leftPtr;    
    }
	}

  //handles case where two children 
	else {
    //sets current pointer to right tree
		TreeNodePtr *temp = &(currentPtr->rightPtr);    
		currentPtr = currentPtr->rightPtr; 

    //while left NOT NULL, goes to left tree               
		while(currentPtr->leftPtr != NULL) {
			temp = &(currentPtr->leftPtr);  
			currentPtr = currentPtr->leftPtr;     
		}

    //while right NOT NULL, goes to right tree 
		if(currentPtr->rightPtr != NULL) {
			*temp = currentPtr->rightPtr;   
    }

    //else set temp to NULL 
		else {
			*temp = NULL;                
    }
    
    //parent to current 
	  *parentPtr = currentPtr; 
    //left tree of deleted node 
    currentPtr->leftPtr = deleteNode->leftPtr;   
    //right tree of deleted node                      
	  currentPtr->rightPtr = deleteNode->rightPtr;   
	}
}

/* begin inorder traversal of tree */
void inOrder( TreeNodePtr treePtr )
  {
  /* if tree is not empty then traverse */
  if ( treePtr != NULL ) {                
    inOrder( treePtr->leftPtr );         
    printf( "%3d", treePtr->data );      
    inOrder( treePtr->rightPtr );        
  } /* end if */                          
} /* end function inOrder */

/* begin preorder traversal of tree */
void preOrder( TreeNodePtr treePtr )
{
  /* if tree is not empty then traverse */
  if ( treePtr != NULL ) {                
    printf( "%3d", treePtr->data );      
    preOrder( treePtr->leftPtr );         
    preOrder( treePtr->rightPtr );       
  } /* end if */                          
} /* end function preOrder */

/* begin postorder traversal of tree */
void postOrder( TreeNodePtr treePtr )
{
  /* if tree is not empty then traverse */
  if ( treePtr != NULL ) {                
    postOrder( treePtr->leftPtr );       
    postOrder( treePtr->rightPtr );      
    printf( "%3d", treePtr->data );      
  } /* end if */                          
} /* end function postOrder */

/*
Test Case 1:

BINARY TREE DELETE
------------------
The numbers being placed in the tree are:
  3  8  1 12  6 13  3dup  2 14  5

The preOrder traversal is:
  3  1  2  8  6  5 12 13 14

The inOrder traversal is:
  1  2  3  5  6  8 12 13 14

The postOrder traversal is:
  2  1  5  6 14 13 12  8  3

Choose node to delete: 2

Traversal of tree after deletion of chosen node
-----------------------------------------------

The preOrder traversal is:
  3  1  8  6  5 12 13 14

The inOrder traversal is:
  1  3  5  6  8 12 13 14

The postOrder traversal is:
  1  5  6 14 13 12  8  3

Test Case 2:

BINARY TREE DELETE
------------------
The numbers being placed in the tree are:
  3  1  1dup  6  7  5  7dup 12  8  3dup

The preOrder traversal is:
  3  1  6  5  7 12  8

The inOrder traversal is:
  1  3  5  6  7  8 12

The postOrder traversal is:
  1  5  8 12  7  6  3

Choose node to delete: 3

Traversal of tree after deletion of chosen node
-----------------------------------------------

The preOrder traversal is:
  5  1  6  7 12  8

The inOrder traversal is:
  1  5  6  7  8 12

The postOrder traversal is:
  1  8 12  7  6  5

Test Case 3:

BINARY TREE DELETE
------------------
The numbers being placed in the tree are:
  5  5dup  4  5dup  2 10  6  2dup 13  6dup

The preOrder traversal is:
  5  4  2 10  6 13

The inOrder traversal is:
  2  4  5  6 10 13

The postOrder traversal is:
  2  4  6 13 10  5

Choose node to delete: 13

Traversal of tree after deletion of chosen node
-----------------------------------------------

The preOrder traversal is:
  5  4  2 10  6

The inOrder traversal is:
  2  4  5  6 10

The postOrder traversal is:
  2  4  6 10  5

Test Case 4:

BINARY TREE DELETE
------------------
The numbers being placed in the tree are:
 10  0  9  2 12  6 12dup 14  3  7

The preOrder traversal is:
 10  0  9  2  6  3  7 12 14

The inOrder traversal is:
  0  2  3  6  7  9 10 12 14

The postOrder traversal is:
  3  7  6  2  9  0 14 12 10

Choose node to delete: 7

Traversal of tree after deletion of chosen node
-----------------------------------------------

The preOrder traversal is:
 10  0  9  2  6  3 12 14

The inOrder traversal is:
  0  2  3  6  9 10 12 14

The postOrder traversal is:
  3  6  2  9  0 14 12 10

Test Case 5:

BINARY TREE DELETE
------------------
The numbers being placed in the tree are:
  9 14 10 14dup 11  3 14dup  3dup  1  1dup

The preOrder traversal is:
  9  3  1 14 10 11

The inOrder traversal is:
  1  3  9 10 11 14

The postOrder traversal is:
  1  3 11 10 14  9

Choose the node to delete: 100
NULL

Traversal of tree after deletion of chosen node
-----------------------------------------------

The preOrder traversal is:
  9  3  1 14 10 11

The inOrder traversal is:
  1  3  9 10 11 14

The postOrder traversal is:
  1  3 11 10 14  9

*/