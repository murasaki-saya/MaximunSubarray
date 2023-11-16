#include<stdio.h>
int main (void){
	int size,total=0,sum[2];
	sum[0]=0, sum[1]=0;
	bool start=false, state=false, sum1 = false;
	printf("input size: ");
	scanf("%d", &size);
	int num[size];

	printf("input num:");
	for(int i=0 ; i<size ; i++){
		scanf("%d",&num[i]);
	}
	
	for(int i=0 ; i<size ; i++){
		//尋找起始正數 
		if(num[i] > 0){
			start = true;
		}
		if(!start)
			continue;
			
		total += num[i];
		
		if(!i)
			continue;
		//由正轉負 或 由負轉正	
		if(num[i-1]<0 && num[i]>=0){
			sum1=true;
		}else if(num[i-1]>=0 && num[i]<0)
			state=true;
  
		if(state){	//由正轉負要保存目前最佳解 max{sum[0],total,sum[1]}
			printf("total: %d, result: %d, sum[1]: %d\n",total,sum[0],sum[1]);
			if(total-num[i] >= sum[0])
				sum[0] = total-num[i];
			if(sum[1]>=sum[0]){
				total = sum[1];
				sum[0] = sum[1];
				sum[1] = 0;
				sum1 = false;
			}
			state = false;
		}
		
		if(sum1)
			sum[1] += num[i];
	}
	if(total > sum[0])
		sum[0] = total;
	if(sum[1] > sum[0])
		sum[0] = sum[1];
		
	printf("result: %d\n",sum[0]);
	printf("total: %d, result: %d, sum[1]: %d",total,sum[0],sum[1]);
	return 0;
} 
