# coding=utf-8
import cv2
import numpy as np

img = cv2.imread("../lena/lena.bmp", 0)
# 高斯模糊 做滤波处理
img = cv2.GaussianBlur(img,(3,3),1.5)
gray_lap = cv2.Laplacian(img, cv2.CV_16S, ksize=5)
dst = cv2.convertScaleAbs(gray_lap)

cv2.imshow('laplacian', dst)
cv2.waitKey(0)
cv2.destroyAllWindows()

