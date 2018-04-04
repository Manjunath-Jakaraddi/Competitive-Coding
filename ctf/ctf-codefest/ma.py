
"""
import cv2
import numpy as np
img = cv2.imread('a.png')
img=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
sz = np.ones((128,128))
img=abs(img-sz)
img = img * 255
cv2.imshow('orig',img)
cv2.waitKey(0)

"""
import cv2
import numpy as np
img = cv2.imread('c.png')
img=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

for i in range(128):
    for j in range(128):
        if(img[i][j]!=0):
            img[i][j]-=254
img=img*128

print img[0]
cv2.imwrite('cout.png',img[0:16])
cv2.imshow('orig',img)
cv2.waitKey(0)

