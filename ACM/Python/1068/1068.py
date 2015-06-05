#!179646VO

data = raw_input()
total = 0
numTo = int(data)

if numTo != 0:
    for x in range(1,numTo, numTo/abs(numTo)):
        total += x
    total += numTo
else:
    total = 1
    
print total



