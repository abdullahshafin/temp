#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

float contrast = 1;
int brightness = 0;
char keyPressed;

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

 	Mat image;
    image = imread( argv[1], 1 );

    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }

    Mat imOut = Mat::zeros(image.size(), image.type());
    // cout << image.size() << endl;
    // cout << image.type() << endl;

    namedWindow("Display Image", WINDOW_AUTOSIZE );
	imshow("Display Image", image);
	    
    while(keyPressed!=27&&keyPressed!=10)
	{
		keyPressed = waitKey(0);
		std::cout << "Key pressed: " << (int)keyPressed << std::endl;

		switch((int)keyPressed)
		{
			case 49:
			std::cout << "1 pressed" << std::endl;
			if(brightness>=10)
				brightness -= 10;
			break;
			case 50:
			if (brightness<=90)
				brightness += 10;
			break;
			case 51:
			std::cout << "3 pressed" << std::endl;
			if(contrast>=1.2)
				contrast -= .2;
			break;
			case 52:
			if (contrast<=2.8)
				contrast += .2;
			break;
		}		

		image.convertTo(imOut, -1, contrast, brightness);
		imshow("Display Image", imOut);
	}

    return 0;
}
