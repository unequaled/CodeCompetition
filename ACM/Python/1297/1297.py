#!179646VO

import sys

data = sys.stdin.read()
revData = ""
string = data[0]
dataLen = len(data)
count = dataLen
flag = False

for x in data:
    revData = x + revData 

#print revData

while count > 1 and not flag:   
    x = 0
    while x + count <= dataLen:
        window = int(count/2)
        #print revData[x:x+window], data[dataLen-count-x:dataLen-count-x+window]
        if data[x:x+window] == revData[dataLen-count-x:dataLen-count-x+window]:
            flag = True
            string = data[x:x+count]
            break;
        else:
            x += 1         
    count -= 1

print string