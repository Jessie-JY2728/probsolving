# Question:
# given int[] arr, int thres, find an int x,
# such that when each elem of arr takes ceiling division with x
# the resulting array sums up to less than or equal to thres
# if impossible, return -1
import math

def minDivisor(arr, thres):
  ans = floor(sum(arr) / thres)
  n = len(arr)
  for x in range(ans, ans + n):
    newsum = sum([ceil(i / x) for i in arr])
    if newsum <= thres:
      return newsum
  return -1
  
