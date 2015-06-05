#!/usr/bin/env python

def strKBase(K,num):
    string = ""  
    while num != 0:
        string = str(int(num%K)) + string
        num = int(num/K)                
    return string 
