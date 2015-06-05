#!.179646VO
import sys

def searchStrFromHead(string, stringArr):
    strArr = []
    for x in stringArr:
        if x == string:
            strArr.append(x)
            return strArr     
        if x == string[:len(x)]:
            resultstr = searchStrFromHead(string[len(x):], stringArr)
            if not resultstr:# != "":
                strArr.append(x + " " + searchStrFromHead(string[len(x):], stringArr))
                return strArr
    return strArr

inputData = sys.stdin.read()
data = inputData.split()
status = 0
dictionary = dict(zip(("i", "j", "a", "b", "c", "d", "e", "f", "g", "h", "k", "l", "m", "n", "p", "r", "s", "t", "u", "v", "w", "x", "y", "o", "q", "z"),
                      ("1", "1", "2", "2", "2", "3", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "7", "8", "8", "8", "9", "9", "9", "0", "0", "0")))

for x in data:    
    if status == 0:
        cypher = x
        status = 1
    elif status == 1:
        total_num = int(x)
        count = 0
        status = 2
        arrTrans = []
        dictText = dict()
    elif status == 2:
        string = ""
        for char in x:
            string = string + dictionary[char]
        arrTrans.append(string)
        dictText[string] = x
        count = count + 1
        if count == total_num:
            status = 3    
    if status == 3:
        status = 0
        arrTrans = sorted(arrTrans, reverse=True)
        resultdata = searchStrFromHead(cypher, arrTrans)
        if not resultdata: # == "":
            print "No solution."
        else:
            result = ""
            for item in resultdata:
                result = item.split()
                output = ""
                for x in result:
                    output = output + dictText[x] + " "
                output = output[:len(output)-1]
                print output