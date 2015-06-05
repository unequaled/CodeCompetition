#!179646VO

import sys

data = sys.stdin.read().split()
canidate = int(data[0])
elector = int(data[1])
vote = dict()

for x in range(canidate):
    vote[x+1] = int(0)

for x in range(len(data)-2):    
    key = int(data[x+2])
    vote[key] = vote[key] + 1

for x in range(canidate):
    result = vote[x+1]*100.0/elector
    print "%.2f%s" %(result,"%")
   