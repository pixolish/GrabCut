# GrabCut algorithm for Interactive Image Segmentation Using OpenCV

Interactive Image Segmentation can be developed by GrabCut algorithm in a very simple way , just need to mark the probable image foreground object by marking 
a rectangle on the desired object need to segmentation by using mousecallback() function in opencv and number of iteration you need to compute the grabcut
then you find the segmented grabcut output  

# How to Compile and Run the code

**Changes**: `CV_EVENT_LBUTTONDOWN` etc. mouse call back events don't work anymore for OpenCV 3.x versions. These have to be replaced with `EVENT_LBUTTONDOWN`. 

**Compilation (Linux):** ```g++ Grabcut.cpp `pkg-config opencv --cflags --libs` -o Grabcut``` 

**Executation (Linux):**`./Grabcut screenshot1.png`

# Process to get result
First give the input of number of iteration  from the keyboard and then 
Mark a rectangle of the object you want to segment by  left button of mouse and press right button of the mouse to see the region of the rectangle and  make the process continue, Press enter to continue the GrabCut process and see the out put segmented result, press 'Esc'from keyboard to exit from the process.

# Sample Images

![Alt text](https://github.com/pixolish/GrabCut/blob/master/screenshot1.png "Original Image")
![Alt text](https://github.com/pixolish/GrabCut/blob/master/screenshot2.png "Marked Image")
![Alt text](https://github.com/pixolish/GrabCut/blob/master/screenshot3.png "Marked Region")
![Alt text](https://github.com/pixolish/GrabCut/blob/master/screenshot4.png "Grabcut output")
 
# How does it work?

The GrabCut function will first take the input image with rectangle information along with mask image, rectangle , background and foreground model blank image,finally it will calculate mask and using compare function make it probable foreground by the Macro of opencv GC_PR_FGD
the rgb image pixel values on that specified region will be bitwise ANDed with the mask.
```css
		cv::grabCut(img,result,rect,bg,fg,i,GC_INIT_WITH_RECT);
		cv::compare(result,cv::GC_PR_FGD,result,cv::CMP_EQ);
		img.copyTo(foreground,result); 
```
More information can be obtained in the foloowing link of opencv documentation
http://docs.opencv.org/master/d8/d83/tutorial_py_grabcut.html

Any confusion contact with pixolish@gmail.com/somnath.7.mukherjee@gmail.com
