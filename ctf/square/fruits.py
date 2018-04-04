import numpy
import cv2
img = cv2.imread('fruit.jpeg')
img=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
res=0
#for i in range(len(img)):
#    for j in range(len(img)):
#        print img[i][j]
for i in img:
    print i
cv2.imshow('Original',img)
cv2.waitKey(5000)
