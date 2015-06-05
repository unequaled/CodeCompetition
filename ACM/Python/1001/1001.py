#!/usr/bin/env python
import math
import sys

inputData = sys.stdin.read()
data = inputData.split()
num = len(data) -1

while num >= 0:
    print "%.4f" %math.sqrt(int(data[num]))
    num = num - 1
