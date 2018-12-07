# coding=utf-8
import cv2
import numpy as np

img = cv2.imread("../lena/lena.bmp", 0)
# x方向求一阶导数
x = cv2.Sobel(img, cv2.CV_16S, 1, 0)
# y方向求一阶导数
y = cv2.Sobel(img, cv2.CV_16S, 0, 1)

absX = cv2.convertScaleAbs(x) # 转回uint8
absY = cv2.convertScaleAbs(y)

# 由于Sobel算子是在两个方向计算的，最后还需要用cv2.addWeighted(...)函数将其组合起来。
dst = cv2.addWeighted(absX, 0.5, absY, 0.5, 0)

cv2.imshow("absX", absX)
cv2.imshow("absY", absY)
cv2.imshow("Result", dst)
cv2.waitKey(0)
cv2.destroyAllWindows()
