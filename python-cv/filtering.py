# coding=utf-8
import cv2
import numpy as np

img = cv2.imread("../lena/lena.bmp", 0)
result = cv2.blur(img, (5, 5))

cv2.imshow("Origin", img)
cv2.imshow("Blur", result)

cv2.waitKey(0)
cv2.destroyAllWindows()
########################################################
def salt(img, n):
    for k in range(n):
        i = int(np.random.random() * img.shape[1])
        j = int(np.random.random() * img.shape[0])
        if img.ndim == 2:
            img[j, i] = 255
        elif img.ndim == 3:
            img[j, i, 0] = 255
            img[j, i, 1] = 255
            img[j, i, 2] = 255
    return img

result = salt(img, 500)
median = cv2.medianBlur(result, 5)
gaussianResult = cv2.GaussianBlur(img,(5,5),1.5)

cv2.imshow("Salt", result)
cv2.imshow("Median", median)
cv2.imshow("gaussianResult", gaussianResult)
cv2.waitKey(0)
