#!/usr/bin/python -u
from __future__ import print_function
import os,sys
import matplotlib.pyplot as plt
import time
f = open(sys.argv[1],'r')
inlst = []
for l in f.readlines() :
    inlst.append(l.split('\t')[1])
llen = len(inlst)

lst = []
for i in range(llen):
    lst.append(0)
lst.extend(inlst)
llen = len(lst)

lams = []
for i in range(llen) :
    lams.append(i*720/llen)

plt.plot(lams, lst)
plt.axis([0,720,0,100])
plt.xlabel('Wavelength')
plt.ylabel('Raman Spectrum of De-Ionized Water')
plt.show()
