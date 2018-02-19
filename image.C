#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "source.h"

void Image::setSrc(Source* src){
    srcPtr = src;
}

Image::Image(){
    width = 0;
    height = 0;
    pixelBuffer = NULL;
    srcPtr = NULL;
    isUpdated = false;
}
Image::Image(int w, int h){
    width = w;
    height = h;
    //pixelBuffer = (Pixel*)malloc(sizeof(Pixel)*(width)*(height));
    if(pixelBuffer != NULL){
        delete [] pixelBuffer;
    }
    pixelBuffer = new Pixel[width*height];
    isUpdated = false;
}
Image::Image(Image &img){
    width = img.getWidth();
    height = img.getHeight();
    //pixelBuffer = (Pixel*)malloc(sizeof(Pixel)*(width)*(height));
    if(pixelBuffer != NULL){
        delete [] pixelBuffer;
    }
    pixelBuffer = new Pixel[width*height];
    for(int i = 0; i< width*height; i++){
        pixelBuffer[i] = img.getBuffer()[i];
    }
    isUpdated = false;
}
Image::~Image(){
    if(pixelBuffer != NULL){
        delete [] pixelBuffer;
    }
}
int Image::getWidth(){
    return width;
}
int Image::getHeight(){
    return height;
}
Pixel* Image::getBuffer(){
    return pixelBuffer;
}
void Image::resetSize(int w, int h){
    if(pixelBuffer != NULL){
        delete [] pixelBuffer;
    }
    width = w;
    height = h;
    //pixelBuffer = (Pixel*)malloc(sizeof(Pixel)*(width)*(height));
    pixelBuffer = new Pixel[width*height];
}

void Image::Update(){
    if(!isUpdated){
        srcPtr->Update();
        isUpdated = true;
    }
}
