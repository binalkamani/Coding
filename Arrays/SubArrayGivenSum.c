/*
Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case is N and S, where N is the size of array and S is the sum. The second line of each test case contains N space separated integers denoting the array elements.

Output:
For each testcase, in a new line, print the starting and ending positions(1 indexing) of first such occuring subarray from the left if sum equals to subarray, else print -1.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1010

Example:
Input:
2
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10
Output:
2 4
1 5

Explanation :
Testcase1: sum of elements from 2nd position to 4th position is 12
Testcase2: sum of elements from 1st position to 5th position is 15
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
 {
    int T;
    scanf("%d", &T);
    int index_arr[2];
    bool flag = false;
    while(T--)
    {
      int N;
      long int S;

      scanf("%d", &N);
      scanf("%ld", &S);
      printf("N=%d, S=%ld\n", N, S);
      int arr[N];

      int i=0;
      int j=0;
      unsigned long long  sum=0;

      for(int i=0;i<N;i++)
      {
        scanf("%d", &arr[i]);
      }
      for(int i=0;i<N;i++)
      {
        sum = sum + arr[i];
        if (sum > S)
        {
          j++;
          i = j;
          sum = 0;
        }
        else if (sum == S)
        {
          index_arr[0] = j;
          index_arr[1] = i;
          flag = true;
          break;
        }
        else
        {
          // nothing
        }
      }


      if (flag)
      {
          printf("<%d, %d>\n", index_arr[0], index_arr[1]);
          //Clean up array
          memset(arr, 0, N-1);
      }
      else
      {
          printf("%d", -1);
      }
  }
  return 0;
}
