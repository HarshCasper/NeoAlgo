/*Progrm for AVL Tree*/

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

void inorder(struct node *ptr);
struct node *RotateLeft(struct node *pptr);
struct node *RotateRight(struct node *pptr);

struct node *insert(struct node *pptr, int ikey);
struct node *insert_left_check(struct node *pptr, int *ptaller);
struct node *insert_right_check(struct node *pptr, int *ptaller);
struct node *insert_LeftBalance(struct node *pptr);
struct node *insert_RightBalance(struct node *pptr);

struct node *del(struct node *pptr, int dkey);
struct node *del_left_check(struct node *pptr, int *pshorter);
struct node *del_right_check(struct node *pptr, int *pshorter);
struct node *del_LeftBalance(struct node *pptr,int *pshorter);
struct node *del_RightBalance(struct node *pptr,int *pshorter);

main()
{
	int choice,key;
	struct node *root = NULL;

	while(1)
	{
		printf("\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Inorder Traversal\n");
		printf("4.Quit\n");
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
			break;
		 case 4:
			exit(1);
		 default:
			printf("Wrong choice\n");
		}
	}
}

struct node *insert(struct node *pptr, int ikey)
{
	static int taller;
	if(pptr==NULL)	/*Base case*/
	{
		pptr = (struct node *) malloc(sizeof(struct node));
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
	else  /*Base Case*/
	{
		printf("Duplicate key\n");
		taller = FALSE;
	}
	return pptr;
}

struct node *insert_left_check(struct node *pptr, int *ptaller )
{
	switch(pptr->balance)
	{
	 case 0: /* Case L_A : was balanced */  
		pptr->balance = 1;	/* now left heavy */
		break;
	 case -1: /* Case L_B: was right heavy */ 
		pptr->balance = 0;	/* now balanced */
		*ptaller = FALSE;
			break;
	 case 1: /* Case L_C: was left heavy */   
		pptr = insert_LeftBalance(pptr);	/* Left Balancing */
		*ptaller = FALSE;
	}
	return pptr;
}

struct node *insert_right_check(struct node *pptr, int *ptaller )
{
	switch(pptr->balance)
	{
	 case 0: /* Case R_A : was balanced */	
		pptr->balance = -1;	/* now right heavy */
		break;
	 case 1: /* Case R_B : was left heavy */  
		pptr->balance = 0;	/* now balanced */ 
		*ptaller = FALSE;
		break;
	 case -1: /* Case R_C: Right heavy */   
		pptr = insert_RightBalance(pptr);	/* Right Balancing */
		*ptaller = FALSE;
	}
	return pptr;
}

struct node *insert_LeftBalance(struct node *pptr)
{
	struct node *aptr, *bptr;

	aptr = pptr->lchild;
	if(aptr->balance == 1)  /* Case L_C1 : Insertion in AL */ 
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateRight(pptr);
	}
	else		/* Case L_C2 : Insertion in AR */
	{
		bptr = aptr->rchild;
		switch(bptr->balance)
		{
		case -1:			/* Case L_C2a : Insertion in BR */   
			pptr->balance = 0;
			aptr->balance = 1;
			break;
		case 1:					/* Case L_C2b : Insertion in BL */
			pptr->balance = -1;
			aptr->balance = 0;
			break;
		case 0:					/* Case L_C2c : B is the newly inserted node */ 
			pptr->balance = 0;
			aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->lchild = RotateLeft(aptr);
		pptr = RotateRight(pptr);
	}
	return pptr;
}

struct node *insert_RightBalance(struct node *pptr)
{
	struct node *aptr, *bptr;

	aptr = pptr->rchild;
	if(aptr->balance == -1) /* Case R_C1 : Insertion in AR */ 
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateLeft(pptr);
	}
	else		/* Case R_C2 : Insertion in AL */
	{
		bptr = aptr->lchild;
		switch(bptr->balance)
		{
		case -1:	/* Case R_C2a : Insertion in BR */
			pptr->balance = 1;  
			aptr->balance = 0;
			break;
		case 1:		/* Case R_C2b : Insertion in BL */
			pptr->balance = 0;
			aptr->balance = -1;
			break;
		case 0:		/* Case R_C2c : B is the newly inserted node */
			pptr->balance = 0;
			aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->rchild = RotateRight(aptr);
		pptr = RotateLeft(pptr);
	}
	return pptr;
}

struct node *RotateLeft(struct node *pptr)
{
	struct node *aptr;
	aptr = pptr->rchild;	/*A is right child of P*/
	pptr->rchild = aptr->lchild; /*Left child of A becomes right child of P */
	aptr->lchild = pptr;  /*P becomes left child of A*/ 
	return aptr;  /*A is the new root of the subtree initially rooted at P*/
}

struct node *RotateRight(struct node *pptr)
{
	struct node *aptr;
	aptr = pptr->lchild;	/*A is left child of P */
	pptr->lchild = aptr->rchild; /*Right child of A becomes left child of P*/  
	aptr->rchild = pptr;			/*P becomes right child of A*/
	return aptr; /*A is the new root of the subtree initially rooted at P*/
}

struct node *del(struct node *pptr, int dkey)
{
	struct node *tmp, *succ;
	static int shorter;

	if( pptr == NULL) /*Base Case*/
	{
		printf("Key not present \n");
		shorter = FALSE;
		return(pptr);
	}
	if( dkey < pptr->info )
	{
		pptr->lchild = del(pptr->lchild, dkey);
		if(shorter == TRUE)
			pptr = del_left_check(pptr, &shorter);
	}
	else if( dkey > pptr->info )
	{
		pptr->rchild = del(pptr->rchild, dkey);
		if(shorter==TRUE)
			pptr = del_right_check(pptr, &shorter);
	}
	else /* dkey == pptr->info, Base Case*/
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

struct node *del_left_check(struct node *pptr, int *pshorter)
{
	switch(pptr->balance)
	{
		case 0: /* Case L_A : was balanced */       
			pptr->balance = -1;	/* now right heavy */ 
			*pshorter = FALSE;
			break;
		case 1: /* Case L_B : was left heavy */	 
			pptr->balance = 0;	/* now balanced */
			break;            
		case -1: /* Case L_C : was right heavy */   
			pptr = del_RightBalance(pptr, pshorter); /*Right Balancing*/
	}
	return pptr;
}

struct node *del_right_check(struct node *pptr, int *pshorter)
{
	switch(pptr->balance)
	{
		case 0:		/* Case R_A : was balanced */		
			pptr->balance = 1;	/* now left heavy */
			*pshorter = FALSE;
			break;
		case -1: /* Case R_B : was right heavy */	
			pptr->balance = 0;	/* now balanced */
			break;
		case 1: /* Case R_C : was left heavy */	
			pptr = del_LeftBalance(pptr, pshorter );  /*Left Balancing*/
	}
	return pptr;
}

struct node *del_LeftBalance(struct node *pptr,int *pshorter)
{
	struct node *aptr, *bptr;
	aptr = pptr->lchild;
	if( aptr->balance == 0)  /* Case R_C1 */
	{
		pptr->balance = 1;
		aptr->balance = -1;
		*pshorter = FALSE;
		pptr = RotateRight(pptr);
	}
	else if(aptr->balance == 1 ) /* Case R_C2 */
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateRight(pptr);
	}
	else						/* Case R_C3 */
	{
		bptr = aptr->rchild;
		switch(bptr->balance)
		{
			case 0:					/* Case R_C3a */
				pptr->balance = 0;
				aptr->balance = 0;
				break;
			case 1:					/* Case R_C3b */
				pptr->balance = -1;		
				aptr->balance = 0;
				break;
			case -1:			/* Case R_C3c */
				pptr->balance = 0;	
				aptr->balance = 1;
		}
		bptr->balance = 0;			
		pptr->lchild = RotateLeft(aptr);
		pptr = RotateRight(pptr);
	}
	return pptr;
}

struct node *del_RightBalance(struct node *pptr,int *pshorter)
{
	struct node *aptr, *bptr;

	aptr = pptr->rchild;
	if (aptr->balance == 0)	/* Case L_C1 */ 
	{
		pptr->balance = -1;
		aptr->balance = 1;
		*pshorter = FALSE;
		pptr = RotateLeft(pptr);			
	}
	else if(aptr->balance == -1 )	/* Case L_C2 */ 
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateLeft(pptr);			
	}
	else							/* Case L_C3 */
	{
		bptr = aptr->lchild;
		switch(bptr->balance)
		{
			case 0:					/* Case L_C3a */
				pptr->balance = 0;
				aptr->balance = 0;
				break;
			case 1:					/* Case L_C3b */ 
				pptr->balance = 0;
				aptr->balance = -1;
				break;
			case -1:				/* Case L_C3c */
				pptr->balance = 1;
				aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->rchild = RotateRight(aptr);
		pptr = RotateLeft(pptr);
	}
	return pptr;
}

void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("%d  ",ptr->info);
		inorder(ptr->rchild);
	}
}

