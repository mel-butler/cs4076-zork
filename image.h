#ifndef IMAGE_H
#define IMAGE_H
#include <string>
using namespace std;

class Image
{
public:
    Image(string img);
    ~Image();
    string getImage();
    void setImage(string img);
private:
    string image;
};

#endif // IMAGE_H
