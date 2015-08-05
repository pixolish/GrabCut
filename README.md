# GrabCut algorithm for Interactive Image Segmentation Using OpenCV
Interactive Image Segmentation can be developed by GrabCut algorithm in a very simple way , just need to mark the probable image foreground object by marking 
a rectangle on the desired object need to segmentation by using mousecallback() function in opencv and number of iteration you need to compute the grabcut
then you find the segmented grabcut output  

# How to Compile and Run the code
You need to make a project in Windows or Linux or in Mac system and opencv should be installed in your system.
Link the opencv library file like opencv_core,opencv_highgui,opencv_imgproc,opencv_video, opencv_objdetect with any opencv version with 2.4.x
You can compile by include the header file listed in code and run it by passing one image into the command line argument.

# Process to get result
First give the input of number of iteration  from the keyboard and then 
Mark a rectangle of the object you want to segment by  left button of mouse and press right button of the mouse to see the region of the rectangle 
and  make the process continue
!(screenshot1.png)
!(screenshot2.png)
!(screenshot3.png)
Press enter to continue the GrabCut process and see the out put segmented result, press 'Esc'from keyboard to exit from the process
!(screenshot4.png)
 
# How does it work?
The GrabCut function will first take the input image with rectangle information along with mask image, rectangle , background and foreground model blank image
, finally it will calculate mask and using compare function make it probable foreground by the Macro of opencv GC_PR_FGD
the rgb image pixel values on that specified region will be bitwise ANDed with the mask.
```css
		cv::grabCut(img,result,rect,bg,fg,i,GC_INIT_WITH_RECT);
		cv::compare(result,cv::GC_PR_FGD,result,cv::CMP_EQ);
		img.copyTo(foreground,result); 
```
More information can be obtained in the foloowing link of opencv documentation
http://docs.opencv.org/master/d8/d83/tutorial_py_grabcut.html

Any confusion contact with pixolish@gmail.com/somnath.7.mukherjee@gmail.com
