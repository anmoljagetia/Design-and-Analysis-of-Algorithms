Approach 1:

1) Sort the first array O(nLogn)

2) Sort the second array O(nLogn)

3) Use the intersection approach discussed @http://geeksforgeeks.org/?p=6873 to find if there is anything in intersection of the sorted arrays. If there is nothing then sets are disjoint. O(m+n)

Time Complexity: O(mLogm + nLogn)

Approach 2:

1) Build a Hash table using elements of first set. O(m)

2) Now traverse the second array and check if there is any key that already exists in Hash. If exists, then sets are not disjoint. O(n) on average.

Time Complexity: O(m+n) on average. 