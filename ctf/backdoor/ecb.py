import cv2
import numpy as np
img = cv2.imread('img1.png')
img=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
for i in img:
    print i
    j=input()
cv2.imshow('output',img)
cv2.waitKey(0)
