# MaximunSubarray Problem
## input: a set of number
## output: maximun sum of subarray
## example:
### input: {7,-4,-4,2,3,-2}
### output: 7
### input: {-3,-5 2 8 -11 14 -3 1}
### output: 14
#### array[7]: max{(2+8),(2+8-11+14),14} = max{sum[0],total,sum[1]}
#### array[8]: max{14,(14-3+1),1} = max{sum[0],total,sum[1]}
