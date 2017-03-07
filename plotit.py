#!/usr/bin/python -u
# Length of emlst represents 360-700nM
# Pad with 350nM ?
from __future__ import print_function
import os,sys
import matplotlib.pyplot as plt
import time
f = open(sys.argv[1],'r')
emlst = []
exlst = []
mslst = []
for l in f.readlines() :
    (tm, ex, em) = l.rstrip().split('\t')
    mslst.append(int(tm))
    exlst.append(int(ex))
    emlst.append(int(em))
llen = len(emlst)
outlst = []
for i in range(llen):
    outlst.append(0)
outlst.extend(emlst)
olen = len(outlst)
step = 700.0/olen
print("step is "+str(step))
tmlst = []
indx = 0.0
for i in range(olen) :
    tmlst.append(indx)
    indx = indx + step
plt.plot(tmlst, outlst)
plt.axis([0,700,0, 6*max(emlst)/5])
plt.xlabel('Wavelength')
plt.ylabel('Raman Spectrum of De-Ionized Water')
plt.show()
