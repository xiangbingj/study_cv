import cv2
import numpy as np
from skimage import transform as trans

#相似变换
img = cv2.imread('../pic_left_red.bmp')
pts1 = np.array([
      [30.2946, 51.6963],
      [65.5318, 51.5014],
      [48.0252, 71.7366],
      [33.5493, 92.3655],
      [62.7299, 92.2041] ], dtype=np.float32 )
pts2 = np.float32([[120, 97],[163, 87],[130, 117], [126, 148],[163, 141]]) #变换后的点
t = trans.SimilarityTransform()
t.estimate(pts2, pts1)
M = t.params[0:2,:]
res = cv2.warpAffine(img,M,(112, 112), borderValue = 0.0)
cv2.imshow("img",img)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imshow("res",res)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imwrite("pic_left_red_sim.bmp", res)

#透视变换
img_per = cv2.imread('../lena/baby_24.bmp')
rows,cols = img_per.shape[:2]

src = np.float32([[49,83],[265,1],[1,352],[226,353]])
dst = np.float32([[0,0],[266,0],[0,359],[266,359]])
M_per = cv2.getPerspectiveTransform(src, dst)
res_per = cv2.warpPerspective(img_per, M_per, (rows,cols))
cv2.imshow("img_per",img_per)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imshow("res_per",res_per)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imwrite("baby_per.bmp", res_per)

#仿射变换
img = cv2.imread('../lena/baby_24.bmp')
cv2.imshow("img",img)
cv2.waitKey(0)
cv2.destroyAllWindows()
rows,cols = img.shape[:2]
pts1 = np.float32([[120,97],[164,87],[131,113]]) #原始的点
pts2 = np.float32([[111,85],[164,87],[131,113]]) #变换后的点
M = cv2.getAffineTransform(pts1,pts2)
#第三个参数：变换后的图像大小
res = cv2.warpAffine(img,M,(rows,cols))
cv2.imshow("res",res)
cv2.waitKey(0)
cv2.destroyAllWindows()

#旋转变换
img = cv2.imread('../lena/baby_24.bmp')
rows,cols = img.shape[:2]
#第一个参数旋转中心，第二个参数旋转角度，第三个参数：缩放比例
M = cv2.getRotationMatrix2D((cols/2,rows/2),45,1)
#第三个参数：变换后的图像大小
res = cv2.warpAffine(img,M,(rows,cols))
cv2.imshow("res",res)
cv2.waitKey(0)
cv2.destroyAllWindows()
