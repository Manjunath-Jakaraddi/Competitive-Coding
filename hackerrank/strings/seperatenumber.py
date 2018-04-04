#!/bin/python

import sys

def separateNumbers(s):
    # Complete this function
    i=1
    n=len(s)
    while i<=n/2:
        num=int(s[:i])
        tmp=""
        while len(tmp)<n:
            tmp+=str(num)
            num+=1
        if tmp==s:
            print("YES {}".format(s[:i]))
            return
        i+=1
    print "NO"

if __name__ == "__main__":
    q = int(raw_input().strip())
    for a0 in xrange(q):
        s = raw_input().strip()
        separateNumbers(s)
