#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/* Globale variable */
int size;
int capacity;
int *weight,*profit,*selected;


int readFile(char*);
int printResult(int);
int greedy1(); 
int greedy2(); 
int greedy3(); 
int greedy4(); 




int main(int argc, char ** argv){
	char *input;
	int i,totalProfit=0,totalWeight=0;
	if(argc!=2) {
		printf("\nError: Invalid number of arguments!\n\n");
		return 0;
	}
	input = argv[1];
	readFile(input);

	totalProfit = greedy1();
	printf("\nGreedy1 Approach(Max Benefit First):\n");
	printResult(totalProfit);

	totalProfit = greedy2();
	printf("\nGreedy2 Approach(Min Weight First):\n");
	printResult(totalProfit);

	totalProfit = greedy3();
	printf("\nGreedy3 Approach:(Max weight First):\n");
	printResult(totalProfit);

	totalProfit = greedy4();
	printf("\nGreedy4 Approach(Max weight/unit):\n");
	printResult(totalProfit);

	/*Free the allocated memory*/
	free(selected);
	free(weight);
	free(profit);
	return 0;
}

/*
* @brief: Reads the knapsack.txt input file
*/
int readFile(char * filename) {
	FILE *fp;
	char num[255];
	int i=0,j=0;

	fp = fopen(filename,"r");
	if(fp == NULL) {
		printf("\nERROR in opening the file!\n\n");
		return 0;
	}
	char ch;
	ch=fgetc(fp);
	while(ch!='\n' && ch!=EOF) {
		//Read size;
		while(ch!='\n'){
			num[j++]=ch;
			ch=fgetc(fp);
		}
		num[j]='\n';
		size = atoi(num);
		// create weight and profit array
		weight = (int*) malloc(sizeof(int)*size);
		profit = (int*) malloc(sizeof(int)*size);
		selected = (int*) malloc(sizeof(int)*size);
		
		ch=fgetc(fp);
		//Read the weights.
		for(i=0;i<size;i++){
			j=0;
			while(ch!=',' && ch!='\n'){
				num[j++]=ch;
				ch=fgetc(fp);
			}
			num[j]='\n';
			weight[i]=atoi(num);
			if(ch=='\n')
				break;
			ch=fgetc(fp);
		}
		
		ch=fgetc(fp);
		//Read the profit.
		for(i=0;i<size;i++){
			j=0;
			while(ch!=',' && ch!='\n'){
				num[j++]=ch;
				ch=fgetc(fp);
			}
			num[j]='\n';
			profit[i]=atoi(num);
			if(ch=='\n')
				break;
			ch=fgetc(fp);
		}
		//Read capacity
		ch=fgetc(fp);
		j=0;
		while(ch!='\n' && ch!=EOF){
			num[j++]=ch;
			ch=fgetc(fp);
		}
		num[j]='\n';
		capacity = atoi(num);		
	}	
	fclose(fp);
	return 0;
}

int greedy1() {
	int i,j,temp;
	int result=0,greedyCap=capacity;
	int tempArr[size],tempWt[size],tempProfit[size];
	for(i=0;i<size;i++) {
		tempArr[i]=i;
		tempWt[i]=weight[i];
		tempProfit[i]=profit[i];
		selected[i]=0;
	}

	for(i=0;i<size;i++) {
		for(j=0;j<size - i-1;j++) {
			if(tempProfit[j] < tempProfit[j+1]){
				//swap profit
				temp=tempProfit[j];
				tempProfit[j]=tempProfit[j+1];
				tempProfit[j+1]=temp;
				//swap weights
				temp=tempWt[j];
				tempWt[j]=tempWt[j+1];
				tempWt[j+1]=temp;
				//swap item number as well
				temp=tempArr[j];
				tempArr[j]=tempArr[j+1];
				tempArr[j+1]=temp;
			}
		}
	}
	
	for(i=0;i<size;i++) {
		if(tempWt[i] <= greedyCap && greedyCap > 0) {
			result+=tempProfit[i];
			greedyCap -=tempWt[i];
			selected[tempArr[i]]=1;
		}	
	}	
	
	return result;
	
}
  
int greedy2() {
	int i,j,temp;
	int result=0,greedyCap=capacity;
	int tempArr[size],tempWt[size],tempProfit[size];
	for(i=0;i<size;i++) {
		tempArr[i]=i;
		tempWt[i]=weight[i];
		tempProfit[i]=profit[i];
		selected[i]=0;
	}

	for(i=0;i<size;i++) {
		for(j=0;j<size - i-1;j++) {
			if(tempWt[j] > tempWt[j+1]){
				//swap profit
				temp=tempProfit[j];
				tempProfit[j]=tempProfit[j+1];
				tempProfit[j+1]=temp;
				//swap weights
				temp=tempWt[j];
				tempWt[j]=tempWt[j+1];
				tempWt[j+1]=temp;
				//swap item number as well
				temp=tempArr[j];
				tempArr[j]=tempArr[j+1];
				tempArr[j+1]=temp;
			}
		}
	}
	
	for(i=0;i<size;i++) {
		if(tempWt[i] <= greedyCap && greedyCap > 0) {
			result+=tempProfit[i];
			greedyCap -=tempWt[i];
			selected[tempArr[i]]=1;
		}	
	}	
	
	return result;
}  

/*
* @brief: 0-1 Greedy Approach-Max weight first 
*/
int greedy3() {
	int i,j,temp;
	int result=0,greedyCap=capacity;
	int tempArr[size],tempWt[size],tempProfit[size];
	for(i=0;i<size;i++) {
		tempArr[i]=i;
		tempWt[i]=weight[i];
		tempProfit[i]=profit[i];
		selected[i]=0;
	}

	for(i=0;i<size;i++) {
		for(j=0;j<size - i-1;j++) {
			if(tempWt[j] < tempWt[j+1]){
				//swap profit
				temp=tempProfit[j];
				tempProfit[j]=tempProfit[j+1];
				tempProfit[j+1]=temp;
				//swap weights
				temp=tempWt[j];
				tempWt[j]=tempWt[j+1];
				tempWt[j+1]=temp;
				//swap item number as well
				temp=tempArr[j];
				tempArr[j]=tempArr[j+1];
				tempArr[j+1]=temp;
			}
		}
	}
	
	for(i=0;i<size;i++) {
		if(tempWt[i] <= greedyCap && greedyCap > 0) {
			result+=tempProfit[i];
			greedyCap -=tempWt[i];
			selected[tempArr[i]]=1;
		}	
	}	
	
	return result;

} 

/*
* @brief: 0-1 Greedy Approach-maxprofit/unit first
*/
int greedy4() {
	int i,j,temp;
	int result=0,greedyCap=capacity;
	int tempArr[size],tempWt[size],tempProfit[size];
	float val1,val2;
	
	for(i=0;i<size;i++) {
		tempArr[i]=i;
		tempWt[i]=weight[i];
		tempProfit[i]=profit[i];
		selected[i]=0;
	}

	for(i=0;i<size;i++) {
		for(j=0;j<size - i-1;j++) {
			val1 = ((float)tempProfit[j]/ (float)tempWt[j]);
			val2 = ((float)tempProfit[j+1]/(float) tempWt[j+1]);
			if( val1 < val2 ){
				//swap profit
				temp=tempProfit[j];
				tempProfit[j]=tempProfit[j+1];
				tempProfit[j+1]=temp;
				//swap weights
				temp=tempWt[j];
				tempWt[j]=tempWt[j+1];
				tempWt[j+1]=temp;
				//swap item number as well
				temp=tempArr[j];
				tempArr[j]=tempArr[j+1];
				tempArr[j+1]=temp;
			}
		}
	}
	
	for(i=0;i<size;i++) {
		if(tempWt[i] <= greedyCap && greedyCap > 0) {
			result+=tempProfit[i];
			greedyCap -=tempWt[i];
			selected[tempArr[i]]=1;
		}	
	}	
	
	return result;

}

int printResult(int totalProfit) {
	int i,totalWeight=0;
	
	printf("\nSelected Items: {");
	for(i=0;i<size;i++) {
		if(selected[i]==1) {
			totalWeight+=weight[i];
			printf(" (Item%d, %d, %d),",i+1,weight[i],profit[i]);
		}
	}
	printf(" }\n");
	printf("Total Profit = %d\n",totalProfit);
	printf("Total Weight = %d\n\n",totalWeight);

	return 0;		
}
