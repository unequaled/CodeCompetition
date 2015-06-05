#!179646VO

import sys

dataIn = sys.stdin.read()
data = dataIn.split()
N = int(data[0])
K = int(data[1])


def checkKBase(K,N):
    if N == 0:
        return 1
    elif N == 1:
        return K - 1
    else:
        return (K-1)*(checkKBase(K,N-1)+checkKBase(K,N-2))
        # The answer is the most significant digit (from 1 to K) * (last answer where the significant digit is from 1 to K and plus the answer of the digit is 0 value )
print checkKBase(K,N)