#!179646VO

import sys
from operator import itemgetter

def numOfShortPath(shortcut):
    count = 0
    for x in shortcut:        
        for y in shortcut:
            if x[2] < y[2] - 1:
                break;
            elif x[0] > y[0] and x[1] > y[1]:
                if x[3] < y[3]:
                    x[3] = y[3]
        x[3]+=1
        if x[3] > count:
            count = x[3]
    #print shortcut
    return count

data = sys.stdin.read().split()
matro = [int(data[0]), int(data[1])]
shortcut = []

x = 1
while x < int(data[2])*2:
    shortcut.append([int(data[x+2]),int(data[x+3]), int(data[x+2]) + int(data[x+3]) , 0])
    x += 2;

print int(round(sum(matro)*100 - numOfShortPath(sorted(shortcut, key=itemgetter(2)))*58.57864376269,0))