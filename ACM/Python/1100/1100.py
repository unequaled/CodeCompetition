#!179646VO

import sys

dataIn = sys.stdin.read()
data = dataIn.split()
del dataIn

num = int(data[0])
x = num*2
itemList = []
print len(data) 

while x > 0:    
    print x
    itemList.insert(0,[int(data[x-1]), int(data[x])])
    del data[x-1],data[x]
    x -= 2
    
del data
print itemList
    

while 0 < num - 1:
    for j in range(num -1):
        if itemList[j][1] < itemList[j+1][1] :
            itemList[j] , itemList[j+1] = itemList[j+1] ,itemList[j]
    num -=1

for item in itemList:
    print ("%s %s") %(item[0], item[1])
