$
\begin{bmatrix}
Ypre\\
Xpre\\
1
\end{bmatrix}=\begin{bmatrix}
 1&  0& MIDYpre\\
 0&  1& MIDXpre\\
 0&  0& 1
\end{bmatrix}\ast \begin{bmatrix}
Sy &  0& 0\\
0 &  Sx& 0\\
0 &  0& 1
\end{bmatrix}\ast \begin{bmatrix}
\cos \theta & \sin \theta & 0\\
-\sin \theta & \cos \theta & 0\\
0 &  0& 1
\end{bmatrix}\ast \begin{bmatrix}
1 & 0 & 0\\
-\tan \alpha & 1 & 0\\
0 & 0 & 1
\end{bmatrix}\ast \begin{bmatrix}
1 & 0 & MIDYafter\\
0 & 1 & MIDXafter\\
0 & 0 & 1
\end{bmatrix}\ast \begin{bmatrix}
Yafter\\
Xafter\\
1
\end{bmatrix}\\
$
分别为平移矩阵、缩放矩阵、旋转矩阵、横切矩阵、平移矩阵