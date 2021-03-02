#include <stdio.h>
#include <string.h>
#define MAX 10

void decode(char *code, char *ans, int i, int j) {
	// i is index of code array
	// j is index of ans array
	if (i >= strlen(code)) {
		printf("%s ", ans);
		return;
	}
	// getting all possible sequences recursives
	if (code[i + 1] != '0') {
		ans[j] = (code[i] - '0' + 96);
		decode(code, ans, i + 1, j + 1);
	}
	// converting a num to char
	if (code[i + 1]) {
		int result = (code[i] - '0') * 10 + (code[i + 1] - '0') - 1;
		if (result <= 25) {
			ans[j] = result + 97;
			ans[j + 1] = '\0';
			decode(code, ans, i + 2, j + 1);
		}
	}
}
int main() {
	// creating a null string
	char ans[50] = { '\0' };
	// input string
	char code[MAX];
	printf("Enter the code: ");
	scanf("%s", code);
	decode(code, ans, 0, 0);
}

/*
OUTPUT:
Enter the code: 1123
aabc aaw alc kbc kw
Time Complexity : O(n)
Space complexity : O(n)
*/
