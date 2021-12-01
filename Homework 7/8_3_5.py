# a = [-3,-2,-1,1,2,3 ]
# p = 1
# n = len(a) - 1

# i  = 0
# j = n

# while (i < j):
#     while (i < j and a[i] < p):
#         print("z")
#         i = i + 1
#     while (i < j and a[j] >= p):
#         print("z")
#         j = j - 1
#     if (i < j):
#         temp = a[i]
#         a[i] = a[j]
#         a[j] = temp

#     print('y')
# print(a)

        

"""    
i := 1
j := n

While (i < j)
      While (i < j and ai < p)
            i := i + 1
      End-while
      While (i < j and aj ≥ p)
            j := j - 1
      End-while
      If (i < j), swap ai and aj
End-while

Return( a1, a2,...,an )
"""

import random
sum = 0
arr = [0,1,2,3,4,5,6,7,8,9]

for n in range (0, 10000000):    
    random.shuffle(arr)
    temp = 0
    for x in range (0, len(arr)):
        if (arr[x] == x):
            temp += 1
    sum += temp
print(sum/n)