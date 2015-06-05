#!179646VO
import sys

dataIn = sys.stdin.read()
data = dataIn.split()
status = True
diff = 0

def balnacePartition(rockList, rockNum, wieght):
    #print rockNum, wieght
    if wieght == 0:
        return 0
    if rockNum == 0:
        return wieght
    if wieght - rockList[rockNum-1] >= 0:
        return min (balnacePartition(rockList, rockNum -1, wieght - rockList[rockNum-1]), balnacePartition( rockList, rockNum-1, wieght))
    else:
        return balnacePartition( rockList, rockNum -1, wieght)
    
for info in data:
    if status:
        numStone = int(info)
        status = False
        count =0
        stonesArr = []        
    else:
        count = count + 1
        stonesArr.append(int(info))        
        if count == numStone:           
            status = True
            sumStoneWeight = sum(stonesArr)    
            weightTest = int(sumStoneWeight/2)
            print sumStoneWeight - weightTest*2 + 2*balnacePartition( stonesArr, numStone , weightTest)
            #while weightTest > 0:
            #    #print weightTest
            #    if balnacePartition( stonesArr, numStone , weightTest):                    
            #        break
            #    else:
            #        weightTest = weightTest - 1           
            #print sumStoneWeight - 2*weightTest      
    