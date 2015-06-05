#!179646VO

import sys

dataIn = sys.stdin.read()
data = dataIn.split()
num = int(data[0])
dictionary = dict()
itemList = []
for x in range(1, len(data[1:]),2):
    dictionary[int(data[x])] = int(data[x+1])
    itemList = int(data[x+1])



for key, value in sorted(dictionary.iteritems(), key=lambda (k,v): (v,-k), reverse=True):
    print "%s %s" % (key, value)
#    print chr(dictionary[value])+" "+ chr(value)
    

