#include<stdio.h>
int main (void){
	int size,total=0,sum[2];
	sum[0]=0, sum[1]=0;
	bool state=false, sum1 = false;
	int start;
	
	printf("input size: ");
	scanf("%d", &size);
	int num[size];

	printf("input num:");
	for(int i=0 ; i<size ; i++){
		scanf("%d",&num[i]);
	}
	
	//find the first of positive numbers
	for(start=0 ; start<size && num[start]<=0 ; start++);
	
	for(int i=start ; i<size ; i++){ 	
		total += num[i];
		
		if(!i)
			continue;
		// (from negative to positive / from positive to negative)	
		if(i!=start && num[i-1]<0 && num[i]>=0)
			sum1=true;
		else if(num[i-1]>=0 && num[i]<0)
			state=true;
  
		if(state){	//max{sum[0],total,sum[1]}
			//printf("result: %d, total: %d, sum[1]: %d\n",sum[0],total-num[i],sum[1]);
			if(total-num[i] >= sum[0]){	//only if (sum[0]>total && sum[0]>sum[1]) would not reset sum[1]=0
				sum[0] = total-num[i];
				if(sum[1]>=sum[0]){
					total = sum[1]+num[i];
					sum[0] = sum[1];
				}
				sum[1] = 0;
				sum1 = false;
			}
			state = false;
		}
		
		if(sum1){
			sum[1] += num[i];
		}
	}
	//to check if postive number is the end of numbers
	if(total > sum[0])
		sum[0] = total;
	if(sum[1] > sum[0])
		sum[0] = sum[1];
		
	printf("result: %d\n",sum[0]);
	//printf("result: %d, total: %d, sum[1]: %d\n",sum[0],total,sum[1]);
	return 0;
} 
