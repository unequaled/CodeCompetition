#!179646VO

import sys

data = sys.stdin.read().split()
matro = [int(data[0]), int(data[1])]
shortcut = [[0,0]]

def minFloat(numList):
    numList.sort()
    return numList[0]


def shortpath(shortcut, pos, cost):    
    if pos[0] == 0 or pos[1] == 0:
        if pos[0] == 0:
            return pos[1]*100.0
        else:
            return pos[0]*100.0
    else:
        if pos not in shortcut:
            maxpoint = max(max(shortcut))
            diff = 0
            if maxpoint < max(pos):               
                diff +=  (pos[0] - maxpoint)*100
                pos[0] = maxpoint              
                diff +=  (pos[1] - maxpoint)*100
                pos[1] = maxpoint                         
                
                return minFloat([shortpath(shortcut[:], [pos[0]-1,pos[1]], cost)+100.0+ diff,shortpath(shortcut[:], [pos[0],pos[1]-1], cost)+100.0+ diff]) 
            else:
                return minFloat([shortpath(shortcut[:], [pos[0]-1,pos[1]], cost)+100.0,shortpath(shortcut[:], [pos[0],pos[1]-1], cost)+100.0])
            
        else:            
            shortcut.remove(pos)   
            return minFloat([shortpath(shortcut[:], [pos[0]-1,pos[1]], cost)+100.0,shortpath(shortcut[:], [pos[0],pos[1]-1], cost)+100.0,shortpath(shortcut[:], [pos[0]-1,pos[1]-1], cost)+141.4213562373])
           
x = 1

while x < int(data[2])*2:
    shortcut.append([int(data[x+2]),int(data[x+3])])
    x += 2;

print int(round(shortpath(shortcut[:], matro, 0.0),0))