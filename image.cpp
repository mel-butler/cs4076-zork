#include "image.h"

Image::Image(string img)
{
    this->image=img;
}

Image::~Image()
{

}

string Image::getImage()
{
    return this->image;
}

void Image::setImage(string img)
{
    this->image = img;
}
