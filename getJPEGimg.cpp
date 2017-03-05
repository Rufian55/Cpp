/*****************************************************************************
Program: getJPEGimg.cpp reads a jpeg image using the boost library.
Compile:
g++ getJPEGimg.cpp -o getJPGimg -g -Wall -std=c++0x /usr/lib64/libjpeg.so.62 
*****************************************************************************/
#include <iostream>
#include <boost/gil/extension/io/jpeg_io.hpp>
namespace gil = boost::gil;

int main() {
	gil::rgb8_image_t img;
	gil::jpeg_read_image("red.jpg", img);
	std::cout << "Read complete, got an image " << img.width() << "by" << img.height() << " pixels\n";

	return 0;
}