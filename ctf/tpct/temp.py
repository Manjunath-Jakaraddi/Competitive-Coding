import cv2
import numpy as np

img = cv2.imread('twirl.jpg',0)
for i in img:
    print(i)
        #if img[i][j]!=254 and img[i][j]!=0 and img[i][j]!=75:
            #print(str(i)+"   "+str(j)+"    "+str(img[i][j]))
        #   img[i][j]=255
        #else:
        #    img[i][j]=0
print(img.shape)
cv2.imshow('Original', img)
cv2.waitKey(0)
