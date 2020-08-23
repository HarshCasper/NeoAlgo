/*Program for AVL Tree*/

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

struct node 	/*Node of the tree*/
{
	struct  node *lchild;
	int info;
	struct  node *rchild;
	int balance;
};

typedef struct node Node;

void inorder(Node *ptr);
void preorder(Node *ptr);
void postorder(Node *ptr);
Node *RotateLeft(Node *pptr);
Node *RotateRight(Node *pptr);

Node *insert(Node *pptr, int ikey);
Node *insert_left_check(Node *pptr, int *ptaller);
Node *insert_right_check(Node *pptr, int *ptaller);
Node *insert_LeftBalance(Node *pptr);
Node *insert_RightBalance(Node *pptr);

Node *del(Node *pptr, int dkey);
Node *del_left_check(Node *pptr, int *pshorter);
Node *del_right_check(Node *pptr, int *pshorter);
Node *del_LeftBalance(Node *pptr,int *pshorter);
Node *del_RightBalance(Node *pptr,int *pshorter);

/* Sample Input/Output */

	/*Insertion
	
	root = insert(root,50);
	root = insert(root,40);
	root = insert(root,35);
	root = insert(root,58);
	root = insert(root,48);
	root = insert(root,42);
	root = insert(root,60);
	root = insert(root,30);
	root = insert(root,33);
	root = insert(root,25);
	
	Constructed AVL tree would be
			 48
		    /  \
	      33    58
	     /  \   / \
	    30  40 50 60
	   /    / \
	  25   35  42
------------------------------------------------*/	  

	/*Deletion

	root = del(root,60);
	Modified AVL tree would be
			 48
		    /  \
	      33    58
	     /  \   / 
	    30  40 50 
	   /    / \
	  25   35  42

	root = del(root,48);
	Modified AVL tree would be
			 42
		    /  \
	      33    58
	     /  \   / 
	    30  40 50 
	   /    / 
	  25   35  

	root = del(root,25); 
	root = del(root,30); 
	Modified AVL tree would be
			 42
		    /  \
	      35    58
	     /  \   / 
	    33  40 50 
	        
	root = del(root,35); 
	root = del(root,33); 
	root = del(root,58); 
	Modified AVL tree would be
			 42
		    /  \
	      40    50
------------------------------------------------*/

int main()
{
	int choice,key;
	Node *root = NULL;

	while(1)
	{
		printf("\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Inorder Traversal\n");
		printf("4.Preorder Traversal\n");
		printf("5.Postorder Traversal\n");
		printf("6.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter the key to be inserted : ");
			scanf("%d",&key);
			root = insert(root,key);
			break;
		 case 2:
			printf("Enter the key to be deleted : ");
			scanf("%d",&key);
			root = del(root,key);
			break;
		 case 3:
			inorder(root);
		 case 3:
			preorder(root);
		 case 3:
			postorder(root);
			break;
		 case 4:
			exit(1);
		 default:
			printf("Wrong choice\n");
		}
	}
	return 0;
}

Node *insert(Node *pptr, int ikey)
{
	static int taller;
	if(pptr==NULL)	/*Base case*/
	{
		pptr = (Node *) malloc(sizeof(Node));
		pptr->info = ikey;
		pptr->lchild = NULL;
		pptr->rchild = NULL;
		pptr->balance = 0;
		taller = TRUE;
	}
	else if(ikey < pptr->info)	/*Insertion in left subtree*/
	{
		pptr->lchild = insert(pptr->lchild, ikey);
		if(taller==TRUE)
			pptr = insert_left_check( pptr, &taller );
	}
	else if(ikey > pptr->info)	/*Insertion in right subtree */
	{
		pptr->rchild = insert(pptr->rchild, ikey);  
		if(taller==TRUE)
			pptr = insert_right_check(pptr, &taller);
	}
	else  /*Base Case : Duplicate keys not allowed*/
	{
		printf("Duplicate key\n");
		taller = FALSE;
	}
	return pptr;
}

Node *insert_left_check(Node *pptr, int *ptaller )
{
	switch(pptr->balance)
	{
	 case 0: 				/* was balanced */  
		pptr->balance = 1;	/* now left heavy */
		break;
	 case -1: 				/* was right heavy */ 
		pptr->balance = 0;	/* now balanced */
		*ptaller = FALSE;
			break;
	 case 1: 								/* was left heavy */   
		pptr = insert_LeftBalance(pptr);	/* Left Balancing */
		*ptaller = FALSE;
	}
	return pptr;
}

Node *insert_right_check(Node *pptr, int *ptaller )
{
	switch(pptr->balance)
	{
	 case 0: 				/* was balanced */	
		pptr->balance = -1;	/* now right heavy */
		break;
	 case 1: 				/* was left heavy */  
		pptr->balance = 0;	/* now balanced */ 
		*ptaller = FALSE;
		break;
	 case -1: 								/* was right heavy */   
		pptr = insert_RightBalance(pptr);	/* Right Balancing */
		*ptaller = FALSE;
	}
	return pptr;
}

Node *insert_LeftBalance(Node *pptr)
{
	Node *aptr, *bptr;			/* pointer to Node A and Node B respectively */

	aptr = pptr->lchild;
	if(aptr->balance == 1)  	/* Single Right Rotate */ 
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateRight(pptr);
	}
	else						/* Left-Right Rotate */
	{
		bptr = aptr->rchild;
		switch(bptr->balance)	/* Adjust balance factor */
		{
		case -1:			 
			pptr->balance = 0;
			aptr->balance = 1;
			break;
		case 1:					
			pptr->balance = -1;
			aptr->balance = 0;
			break;
		case 0:				
			pptr->balance = 0;
			aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->lchild = RotateLeft(aptr);
		pptr = RotateRight(pptr);
	}
	return pptr;
}

Node *insert_RightBalance(Node *pptr)
{
	Node *aptr, *bptr;			/* pointer to Node A and Node B respectively */

	aptr = pptr->rchild;
	if(aptr->balance == -1) 	/* Single Left Rotate */ 
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateLeft(pptr);
	}
	else						/* Right-Left Rotate */
	{
		bptr = aptr->lchild;
		switch(bptr->balance)	/* Adjust balance factor */
		{
		case -1:	
			pptr->balance = 1;  
			aptr->balance = 0;
			break;
		case 1:		
			pptr->balance = 0;
			aptr->balance = -1;
			break;
		case 0:		
			pptr->balance = 0;
			aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->rchild = RotateRight(aptr);
		pptr = RotateLeft(pptr);
	}
	return pptr;
}

Node *RotateLeft(Node *pptr) 	/* Rotate left about P */
{
	/* pptr is pointer to Node P */
	Node *aptr;		/* pointer to Node A */
	aptr = pptr->rchild;	/*A is right child of P*/
	pptr->rchild = aptr->lchild; /*Left child of A becomes right child of P */
	aptr->lchild = pptr;  /*P becomes left child of A*/ 
	return aptr;  /*A is the new root of the subtree initially rooted at P*/
}

Node *RotateRight(Node *pptr)	/* Rotate right about P */
{
	/* pptr is pointer to Node P */
	Node *aptr;		/* Pointer to Node A */
	aptr = pptr->lchild;	/*A is left child of P */
	pptr->lchild = aptr->rchild; /*Right child of A becomes left child of P*/  
	aptr->rchild = pptr;			/*P becomes right child of A*/
	return aptr; /*A is the new root of the subtree initially rooted at P*/
}

Node *del(Node *pptr, int dkey)
{
	Node *tmp, *succ;
	static int shorter;

	if( pptr == NULL) /*Base Case : Key not present*/
	{
		printf("Key not present \n");
		shorter = FALSE;
		return(pptr);
	}
	if( dkey < pptr->info ) /*Deletion in left subtree*/
	{
		pptr->lchild = del(pptr->lchild, dkey);
		if(shorter == TRUE)
			pptr = del_left_check(pptr, &shorter);
	}
	else if( dkey > pptr->info ) /*Deletion in right subtree*/
	{
		pptr->rchild = del(pptr->rchild, dkey);
		if(shorter==TRUE)
			pptr = del_right_check(pptr, &shorter);
	}
	else /* Base Case : dkey == pptr->info */
	{
		/*pptr has 2 children*/
		if( pptr->lchild!=NULL  &&  pptr->rchild!=NULL )  
		{
			succ = pptr->rchild;
			while(succ->lchild)
				succ = succ->lchild;
			pptr->info = succ->info;
			pptr->rchild = del(pptr->rchild, succ->info);
			if( shorter == TRUE )
				pptr = del_right_check(pptr, &shorter);
		}
		else	
		{
			tmp = pptr;
			if( pptr->lchild != NULL ) /*only left child*/
				pptr = pptr->lchild;
			else if( pptr->rchild != NULL) /*only right child*/
				pptr = pptr->rchild;
			else	/* no children */
				pptr = NULL;
			free(tmp);
			shorter = TRUE;
		}						
	}
	return pptr; 
}

Node *del_left_check(Node *pptr, int *pshorter)
{
	switch(pptr->balance)
	{
		case 0: 				/* was balanced */       
			pptr->balance = -1;	/* now right heavy */ 
			*pshorter = FALSE;
			break;
		case 1: 				/* was left heavy */	 
			pptr->balance = 0;	/* now balanced */
			break;            
		case -1: 										/* was right heavy */   
			pptr = del_RightBalance(pptr, pshorter); 	/*Right Balancing*/
	}
	return pptr;
}

Node *del_right_check(Node *pptr, int *pshorter)
{
	switch(pptr->balance)
	{
		case 0:					/* was balanced */		
			pptr->balance = 1;	/* now left heavy */
			*pshorter = FALSE;
			break;
		case -1: 				/* was right heavy */	
			pptr->balance = 0;	/* now balanced */
			break;
		case 1: 										/* was left heavy */	
			pptr = del_LeftBalance(pptr, pshorter );  	/*Left Balancing*/
	}
	return pptr;
}

Node *del_LeftBalance(Node *pptr,int *pshorter)
{
	Node *aptr, *bptr;
	aptr = pptr->lchild;
	if( aptr->balance == 0)  		/* Single Right Rotate */
	{
		pptr->balance = 1;
		aptr->balance = -1;
		*pshorter = FALSE;
		pptr = RotateRight(pptr);
	}
	else if(aptr->balance == 1 ) 	/* Single Right Rotate */
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateRight(pptr);
	}
	else							/* Left-Right Rotate */
	{
		bptr = aptr->rchild;
		switch(bptr->balance)		/* Adjust balance factor */
		{
			case 0:					
				pptr->balance = 0;
				aptr->balance = 0;
				break;
			case 1:					
				pptr->balance = -1;		
				aptr->balance = 0;
				break;
			case -1:			
				pptr->balance = 0;	
				aptr->balance = 1;
		}
		bptr->balance = 0;			
		pptr->lchild = RotateLeft(aptr);
		pptr = RotateRight(pptr);
	}
	return pptr;
}

Node *del_RightBalance(Node *pptr,int *pshorter)
{
	Node *aptr, *bptr;

	aptr = pptr->rchild;
	if (aptr->balance == 0)			/* Single Left Rotate */
	{
		pptr->balance = -1;
		aptr->balance = 1;
		*pshorter = FALSE;
		pptr = RotateLeft(pptr);			
	}
	else if(aptr->balance == -1 )	/* Single Left Rotate */ 
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateLeft(pptr);			
	}
	else							/* Right-Left Rotate */
	{
		bptr = aptr->lchild;
		switch(bptr->balance)		/* Adjust balance factor */
		{
			case 0:					
				pptr->balance = 0;
				aptr->balance = 0;
				break;
			case 1:					
				pptr->balance = 0;
				aptr->balance = -1;
				break;
			case -1:				
				pptr->balance = 1;
				aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->rchild = RotateRight(aptr);
		pptr = RotateLeft(pptr);
	}
	return pptr;
}

void inorder(Node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("%d  ",ptr->info);
		inorder(ptr->rchild);
	}
}

void preorder(Node *ptr)
{
	if(ptr!=NULL)
	{
		printf("%d  ",ptr->info);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}

void postorder(Node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d  ",ptr->info);
	}
}
