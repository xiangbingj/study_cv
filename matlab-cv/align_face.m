function [targetimage]  = align_face(I)
rows = 128;
cols = 128;
rowFrac = 0.35;
colFrac = 0.65;
le = [(1-colFrac)*cols, rows*rowFrac];
re = [colFrac*cols,rows*rowFrac];
mouth = [0.5*cols,rows*(1-rowFrac)];
landmark_tool = [le;re;mouth];
TOTALNUM = 3;
landmark = [];
LeftEyeDetect = vision.CascadeObjectDetector('LeftEye','MergeThreshold',16); 
le_dtect = step(LeftEyeDetect,I);
figure('Name','original image'),
imagesc(I);
title('Original image');
figure('Name','detection'),
imagesc(I);
hold on
minx = 160;
for i = 1:size(le_dtect,1)
    rectangle('Position',le_dtect(i,:),'LineWidth',4,'LineStyle','-','EdgeColor','m');    
    if(le_dtect(i,1)<minx)
        minx = le_dtect(i,1);
    end
end
le_index = find(le_dtect(:,1)==minx);
landmark = [landmark;[mean(le_dtect(le_index,1)+le_dtect(le_index,3)/2),mean(le_dtect(le_index,2)+le_dtect(le_index,4)/2)]];
RightEyeDetect = vision.CascadeObjectDetector('RightEye','MergeThreshold',16); 
re_dtect=step(RightEyeDetect,I); 
hold on
maxx = 0;
for i = 1:size(re_dtect,1)
    rectangle('Position',re_dtect(i,:),'LineWidth',4,'LineStyle','-','EdgeColor','m');
    if(re_dtect(i,1)>=maxx)
        maxx = re_dtect(i,1);
    end
end
re_index = find(re_dtect(:,1)==maxx);
landmark = [landmark;[mean(re_dtect(re_index,1)+re_dtect(re_index,3)/2),mean(re_dtect(re_index,2)+re_dtect(re_index,4)/2)]];
mouth_detect = vision.CascadeObjectDetector('Mouth','MergeThreshold',16); 
mouth_dtect=step(mouth_detect,I); 
hold on
maxy = 0;
for i = 1:size(mouth_dtect,1)
    rectangle('Position',mouth_dtect(i,:),'LineWidth',4,'LineStyle','-','EdgeColor','m');
    if(mouth_dtect(i,2)>=maxy)
        maxy = mouth_dtect(i,2);
    end
end
mouth_index = find(mouth_dtect(:,2)==maxy);
landmark = [landmark;[mean(mouth_dtect(mouth_index,1)+mouth_dtect(mouth_index,3)/2),mean(mouth_dtect(mouth_index,2)+mouth_dtect(mouth_index,4)/2)]];
hold on
for k = 1:TOTALNUM
    plot(landmark(k,1),landmark(k,2),'y.','LineWidth',34);
    plot(landmark_tool(k,1),landmark_tool(k,2),'b.','LineWidth',34);
end
hold off
title('Detection');
% tform = cp2tform(MOVINGPOINTS,FIXEDPOINTS,'affine');
% tform = fitgeotrans(landmark,landmark_tool,'affine');
tform = fitgeotrans(landmark,landmark_tool,'similarity');
% targetimage = imtransform(I,tform,'FillValue',1);
targetimage = imwarp(I,tform,'FillValue',1);
figure('Name','affined image');
imagesc(targetimage);
title('Affined image');
posx_start = find(targetimage(1,:,1)~=1);
posx_end = find(targetimage(end,:,1)~=1);
posy_start = find(targetimage(:,1,1)~=1);
posy_end = find(targetimage(:,end,1)~=1);
counter = 0;
while(isempty(posx_start))
    counter = counter+1;
    posx_start = find(targetimage(1+counter,:,1)~=1);
end
counter = 0;
while(isempty(posx_end))
    counter = counter+1;
    posx_end = find(targetimage(end-counter,:,1)~=1);
end
counter = 0;
while(isempty(posy_start))
    counter = counter+1;
    posy_start = find(targetimage(:,1+counter,1)~=1);
end
counter = 0;
while(isempty(posy_end))
    counter = counter+1;
    posy_end = find(targetimage(:,end-counter,1)~=1);
end
xmin = min(min(posx_start),min(posx_end));
xmax = max(max(posx_start),max(posx_end));
ymin = min(min(posy_start),min(posy_end));
ymax = max(max(posy_start),max(posy_end));
xmin = floor(mean(xmin));
xmax = floor(mean(xmax));
ymin = floor(mean(ymin));
ymax = floor(mean(ymax));
[th,tw]= size(targetimage(:,:,1));
targetimage = targetimage(floor(max(1,ymin/2)):floor((ymax+th)/2),floor(max(1,xmin/2)):floor((xmax+tw)/2),:);
% targetimage = targetimage(ymin:ymax,xmin:xmax,:);
figure('Name','affined cropped image');
imagesc(targetimage);
title('Affined cropped image');
end