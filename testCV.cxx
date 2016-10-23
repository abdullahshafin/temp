#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

float contrast = 1;
int brightness = 0;
float gammaC = 1;
char keyPressed;


void gammaCCorrection(Mat& , Mat& , float);

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

    namedWindow("Display Image", WINDOW_AUTOSIZE );
	imshow("Display Image", image);
	    
    while(keyPressed!=27&&keyPressed!=10)
	{
		keyPressed = waitKey(0);
		// std::cout << "Key pressed: " << (int)keyPressed << std::endl;

		switch((int)keyPressed)
		{
			case 49:
			std::cout << "Brightness decreased" << std::endl;
			// if(brightness>=10)
				brightness -= 10;
			break;
			case 50:
			std::cout << "Brightness increased" << std::endl;
			// if (brightness<=90)
				brightness += 10;
			break;
			case 51:
			std::cout << "Contrast decreased" << std::endl;
			// if(contrast>=1.2)
				contrast -= .2;
			break;
			case 52:
			std::cout << "Contrast increased" << std::endl;
			// if (contrast<=2.8)
				contrast += .2;
			break;
			case 53:
			std::cout << "Gamma decreased" << std::endl;
			// if(gammaC>=0.2)
				gammaC -= .1;
			break;
			case 54:
			std::cout << "Gamma increased" << std::endl;
			if (gammaC<=9.8)
				gammaC += .2;
			break;
			default:
			continue;
		}		

		image.convertTo(imOut, -1, contrast, brightness);
		gammaCCorrection(imOut, imOut, gammaC);	
		imshow("Display Image", imOut);
	}

    return 0;
}

void gammaCCorrection(Mat& src, Mat& dst, float fgammaC)

{

	unsigned char lut[256];

	for (int i = 0; i < 256; i++)

	{

		lut[i] = saturate_cast<uchar>(pow((float)(i / 255.0), fgammaC) * 255.0f);

	}

	dst = src.clone();

	const int channels = dst.channels();

	switch (channels)

	{

		case 1:

		{

			MatIterator_<uchar> it, end;

			for (it = dst.begin<uchar>(), end = dst.end<uchar>(); it != end; it++)

				*it = lut[(*it)];

			break;

		}

		case 3:

		{

			MatIterator_<Vec3b> it, end;

			for (it = dst.begin<Vec3b>(), end = dst.end<Vec3b>(); it != end; it++)

			{

				(*it)[0] = lut[((*it)[0])];

				(*it)[1] = lut[((*it)[1])];

				(*it)[2] = lut[((*it)[2])];

			}

			break;

		}

	}

}