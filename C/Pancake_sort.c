#include <stdio.h>
#include <stdlib.h>

// print array function to output the stack of pancakes after each flip
void print_array(int *stack, int h) {
    for (int i=0; i<h; i++) {
		printf("%d ", stack[i]);
	}
	printf("\n");
}

//function that flips the pancakes
void flip(int stack[], int n) {
	int temp = 0;
	int m = n;
	
	//swap the positions of the pancakes from top to n, where n is the index
	//of the largest unsorted pancake
	for(int i=0; i<n; i++) {
		temp = stack[i];
		stack[i] = stack[n];
		stack[n] = temp;
		n--;
	}
	
	//change which side of the flipped pancakes is burnt
	for(int i=0; i<m+1; i++) {
		stack[i] = stack[i]*-1;
	}
}

//find the largest pancake in the stack
int is_max(int stack[], int n) {
	int max, i;
	//take the absolute value to account for the burnt side up (negative) pancakes
	for (max=0, i=0; i<n; i++) {
		if (abs(stack[max]) <= abs(stack[i])) {
			max = i;
		}
	}
	return max;
}

//the core of the program that sorts the stack
int pancake_sort(int *stack, int height) {
	int moves = 0;
	
	//search the stack for the largest unsorted pancake
	//and flips it to the top of the stack
	for (int h=height; h>1; h--) {
		int max = is_max(stack, h);
		if (max != h-1) {
			if(max != 0) {
				flip(stack, max);
				moves++;
				print_array(stack, height);
			}
			
			//if the pancake that is now on the top is burnt side up
			//flip the pancake again
			if(stack[0] > 0) {
				stack[0] = stack[0]*-1;
				moves++;
				print_array(stack, height);
			}	
			
			//finally flip the whole unsorted stack
			flip(stack, h-1);
			moves++;
			print_array(stack, height);
		}
	}
	
	//check for any burnt side up pancakes in the stack and flip them
	for(int i=height-1;i>0;i--) {
		if(stack[i] < 0) {
			flip(stack, i);
			moves++;
			print_array(stack, height);
			
			stack[0] = stack[0]*-1;
			moves++;
			print_array(stack, height);
			
			flip(stack, i);
			moves++;
			print_array(stack, height);
		}
	}
	
	//check that after the last flip the top pancake is burnt side down
	if(stack[0] < 0) {
		stack[0] = stack[0]*-1;
		moves++;
		print_array(stack, height);
	}
	return moves;
}

int main(void){
	int h;
	int j;
	
	//allocate memory to the stack to fit size to user input
	printf("How many pancakes in your stack? ");
	scanf("%d", &h);
	int *stack = malloc(sizeof(int) * h);
	
	//fill stack with user input
	for(int i=0; i<h; i++) {
		if (i<1) {
			printf("How big is the first pancake? ");
			scanf("%d", &j);
			stack[i] = j;
		} else {
			printf("How big is the next pancake? ");
			scanf("%d", &j);
			stack[i] = j;
		}
	}	
	
	//do the sort
	print_array(stack, h);
	int moves = pancake_sort(stack, h);
	printf("Moves: %d\n", moves);
	free(stack);
	return 0;
}
