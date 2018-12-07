import cv2
import numpy as np
# coding=utf-8
import cv2
import numpy as np

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

if __name__ == '__main__':
    img = cv2.imread("../lena/lena.bmp")
    b, g, r = cv2.split(img)

    histImgB = calcAndDrawHist(b, [255, 0, 0])
    histImgG = calcAndDrawHist(g, [0, 255, 0])
    histImgR = calcAndDrawHist(r, [0, 0, 255])

    cv2.imshow("histImgB", histImgB)
    cv2.imshow("histImgG", histImgG)
    cv2.imshow("histImgR", histImgR)
    cv2.imshow("Img", img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

    h = np.zeros((300, 256, 3))
    bins = np.arange(257)
    bin = bins[0:-1]
    color = [(255, 0, 0), (0, 255, 0), (0, 0, 255)]

    for ch, col in enumerate(color):
        item = img[:, :, ch]
        N, bins = np.histogram(item, bins)
        v = N.max()
        N = np.int32(np.around((N * 255) / v))
        N = N.reshape(256, 1)
        pts = np.column_stack((bin, N))
        cv2.polylines(h, [pts], False, col)

    h = np.flipud(h)

    cv2.imshow('img',
               )
    cv2.waitKey(0)
