#!179646VO

import sys

dataIn = sys.stdin.read()
data = dataIn.split()
num = int(data[0])
group = []

for x in range(len(data[1:])):
    group.append(int(data[x+1]))

group.sort()
minPopulation = 0
for i in range(len(group)/2 +1):
    minPopulation += group[i]/2 + 1

print minPopulation


