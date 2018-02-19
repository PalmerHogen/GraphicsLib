#ifndef IMAGE
#define IMAGE

class Source;

struct Pixel{
    unsigned char red, green, blue;
};

class Image{
    public:
        Image(); //default
        Image(int w, int h); //parameterized
        Image(Image &img); //copy
        ~Image();
        int getWidth();
        int getHeight();
        Pixel* getBuffer();
        void resetSize(int w, int h);
        void setSrc(Source* src);
        bool isUpdated;
        void Update();
    
    private:
        int width, height;
        Pixel* pixelBuffer;
        Source* srcPtr;
};

#endif