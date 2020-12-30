// Stock Span Problem
// Given a list of prices of a stock for N number of days, find stock span for each day. 

#include<stdio.h>
#define MAXSIZE 50

int stack[MAXSIZE];
int top = -1;

int isempty() {
	if (top == -1)
		return 1;
	else
		return 0;
}

int isfull() {
	if (top == MAXSIZE)
		return 1;
	else
		return 0;
}

int peek() {
	return stack[top];
}

int pop() {
	int data;
	if (!isempty()) {
		data = stack[top];
		top = top - 1;
		return data;
	} else {
		printf("Stack is empty.\n");
	}
}

void push(int data) {
	if (!isfull()) {
		top = top + 1;
		stack[top] = data;
	} else {
		printf("Stack is full.\n");
	}
}

void calcSpan(int arr[], int days) {
	int i, span[days];

	if (days == 0)
		return;
	// initialization
	span[0] = 1;
	push(0);
	for (i = 1; i < days; i++) {
		// checking if previous stock prize is less
		while (!isempty() && arr[i] > arr[peek()])
			pop();
		// updating the span value
		if (isempty()) {
			span[i] = i + 1;
		} else {
			span[i] = i - peek();
		}
		push(i);
	}
	// printing the span
	for (i = 0; i < days; i++)
		printf("%d  ", span[i]);

	printf("\n");
}

int main() {
	int n;
	printf("Enter the no. of days: \n");
	scanf("%d", &n);
	printf("Enter the stock prizes: \n");
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	calcSpan(arr, n);
	return 0;
}
/*
 INput:
 Enter the no. of days: 
 5
 Enter the stock prizes: 
 30 20 40 50 60

 Output:
 1  1  3  4  5  
 Time complexity: O(n)
 Space complexity: O(n)
 */
