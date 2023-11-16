#include<stdio.h>
int main (void){
	int size,state=-1,total=0,sum[2];
	sum[0]=0, sum[1]=0;
	bool start=false;
	printf("input size: ");
	scanf("%d", &size);
	int num[size];

	printf("input num:");
	for(int i=0 ; i<size ; i++){
		scanf("%d",&num[i]);
	}
	
	for(int i=0 ; i<size ; i++){
		//find the first positive number
		if(num[i] > 0){
			start = true;
		}
		if(!start)
			continue;
			
		total += num[i];
		
		if(!i)
			continue;
		//from (positive to negative / negative to positive)	
		if(num[i-1]<0 && num[i]>=0)
			state=1;
		else if(num[i-1]>=0 && num[i]<0)
			state=0;
 
		if(state==1)
			sum[1] += num[i]; 
		else if(!state){	//max{sum[0],total,sum[1]}
			printf("total: %d, result: %d, sum[1]: %d\n",total,sum[0],sum[1]);
			if(total-num[i] >= sum[0])
				sum[0] = total-num[i];
			if(sum[1] >= sum[0]){
				total = sum[1]+num[i];
				sum[0] = sum[1];
			}
			sum[1] = 0;
			state = -1;
		}
	}
	if(total > sum[0])
		sum[0] = total;
	if(sum[1] > sum[0])
		sum[0] = sum[1];
		
	printf("result: %d\n",sum[0]);
	printf("total: %d, result: %d, sum[1]: %d",total,sum[0],sum[1]);
	return 0;
} 
