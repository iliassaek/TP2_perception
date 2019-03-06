
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	// Read the image file
	Mat image = imread("bruit.jpg");

	// Check for failure
	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}

	//Blur the image with 3x3 Gaussian kernel
	Mat image_blurred_with_3x3_kernel;
	blur(image, image_blurred_with_3x3_kernel, Size(3, 3));


	// Gaussian
	Mat image_Gaussian_blurred_with_5x5_kernel;
	GaussianBlur(image, image_Gaussian_blurred_with_5x5_kernel, Size(5, 5), 0);

	//Median
	Mat image_Median_blurred_with_5x5_kernel;
	medianBlur(image, image_Median_blurred_with_5x5_kernel, 3);

	//Lissage bilatéral
	Mat image_Bilateral_blurred_with_5x5_kernel;
	medianBlur(image, image_Bilateral_blurred_with_5x5_kernel, 15);

	//Define names of the windows
	String window_name = "Eliotrope";
	String window_name_blurred_with_3x3_kernel = "Application du filtre moyenneur 3x3";
	String window_name_Gaussian_blurred_with5x5_kernel = "Application du filtre gaussien 5x5";
	String window_name_Median_blurred = "Application du filtre Median";
	String window_name_Bilateral_blurred = "Lissage bilatéral";
	
	// Create windows with above names
	namedWindow(window_name);
	namedWindow(window_name_blurred_with_3x3_kernel);
	namedWindow(window_name_Gaussian_blurred_with5x5_kernel);
	namedWindow(window_name_Median_blurred);
	namedWindow(window_name_Bilateral_blurred);

	

	// Show our images inside the created windows.
	imshow(window_name, image);
	imshow(window_name_blurred_with_3x3_kernel, image_blurred_with_3x3_kernel);
	imshow(window_name_Gaussian_blurred_with5x5_kernel, image_Gaussian_blurred_with_5x5_kernel);
	imshow(window_name_Median_blurred, image_Median_blurred_with_5x5_kernel);
	imshow(window_name_Bilateral_blurred, image_Bilateral_blurred_with_5x5_kernel);

	waitKey(0); // Wait for any keystroke in the window

	destroyAllWindows(); //destroy all opened windows

	return 0;
}
