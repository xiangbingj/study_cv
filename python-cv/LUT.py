# coding=utf-8
import cv2
import numpy as np

##################使用查找表来拉伸直方图#########################
image = cv2.imread("../lena/lena.bmp", 0)
lut = np.zeros(256, dtype=image.dtype)  # 创建空的查找表
hist = cv2.calcHist([image],  # 计算图像的直方图
                    [0],  # 使用的通道
                    None,  # 没有使用mask
                    [256],  # it is a 1D histogram
                    [0.0, 255.0])

minBinNo, maxBinNo = 0, 255

# 计算从左起第一个不为0的直方图柱的位置
for binNo, binValue in enumerate(hist):
    if binValue != 0:
        minBinNo = binNo
        break
# 计算从右起第一个不为0的直方图柱的位置
for binNo, binValue in enumerate(reversed(hist)):
    if binValue != 0:
        maxBinNo = 255 - binNo
        break
print
minBinNo, maxBinNo

# 生成查找表，方法来自参考文献1第四章第2节
for i, v in enumerate(lut):
    print(i)
    if i < minBinNo:
        lut[i] = 0
    elif i > maxBinNo:
        lut[i] = 255
    else:
        lut[i] = int(255.0 * (i - minBinNo) / (maxBinNo - minBinNo) + 0.5)

# 计算
result = cv2.LUT(image, lut)
cv2.imshow("LutImage", result)
cv2.waitKey(0)
cv2.destroyAllWindows()

#################显示直方图######################
def calcAndDrawHist(image, color):
    hist = cv2.calcHist([image],
                        [0],  # 使用的通道
                        None,  # 没有使用mask
                        [256],  # HistSize
                        [0.0, 255.0])  # 直方图柱的范围
    minVal, maxVal, minLoc, maxLoc = cv2.minMaxLoc(hist)
    histImg = np.zeros([256, 256, 3], np.uint8)
    hpt = int(0.9 * 256)

    for h in range(256):
        intensity = int(hist[h] * hpt / maxVal)
        cv2.line(histImg, (h, 256), (h, 256 - intensity), color)
    return histImg
histImgB = calcAndDrawHist(image, [255, 0, 0])
histLutImgB = calcAndDrawHist(result, [255, 0, 0])
cv2.imshow("histImgB", histImgB)
cv2.imshow("histLutImgB", histLutImgB)

equ = cv2.equalizeHist(image)
cv2.imshow('equ',equ)
histequImgB = calcAndDrawHist(equ, [255, 0, 0])
cv2.imshow("histequImgB", histequImgB)
cv2.waitKey(0)
cv2.destroyAllWindows()