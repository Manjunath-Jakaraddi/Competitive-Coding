arr = [1,2,3,4,5,6]
max any number of elements which are not adjacent

1 3 6
2 4 6

a 1 + 3 + {4,5,6}
a 1 + 4 + { 5,6}


b 2 + 4 + {6}
b
1 + 3 or 4
2 + 4 or 5

1 + {3,4,5,6} => 1 + 3 + {5,6} => 1+3+5 + {6} =>

                              => 1+3 + {6}
              => 1 + {4,5,6} => 1 + 4 + {5,6}

                            => 1 + 4 + {6}


{2,3,4,5,6} => 2 + {3,4,5,6} =>
                {3, 4, 5,6}

if(dp[i]!=-1) return dp[i];
if(i>n) {return 0}
if(i==n-1) {arr[i]}
return max(arr[i] + solve(i+2), solve(i+1))

max_sum_1 = arr[0]

max_curr_sum = -1
for i 1:n
  max_sum_1 = max(max_sum_1+arr[i], max_sum_1)


  max_curr_sum = max(max_sum_1, max_curr_sum)

  1 core -> 1 2 3 4

incl = arr[0]
excl = INT_MIN
for i 1:n
  incl = excl + arr[i]
  excl = incl
  max_sum = max()
