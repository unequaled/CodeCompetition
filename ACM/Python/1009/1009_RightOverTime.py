#!179646VO

import sys
import math

data = sys.stdin.read()
data = data.split()
N = int(data[0])
K = int(data[1])

def checkKBase(K,num):
    count = 0
    while num != 0:
        if num % K == 0:            
            if count == 1:
                return True
            else:
                count = 1
        else:
            count = 0
        num = int(num/K)                
    return False 

count = 0
x = math.pow(K,N-1)
end = math.pow(K,N)
while x < end:
    if not checkKBase(K,x):
        count = count + 1    
    x = x +1   

print count