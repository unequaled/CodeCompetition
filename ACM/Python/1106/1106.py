#!179646VO

import sys

dataIn = sys.stdin.read()
data = dataIn.split()
del dataIn

relationshipList = []
tempList = []
num = data[0]

for x in range(1,len(data[1:])+ 1):
    if data[x] != '0':
        tempList.append(int(data[x]))
    else:
        relationshipList.append(tempList)
        tempList = []
del data

print relationshipList
