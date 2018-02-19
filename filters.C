#include "image.h"
#include "source.h"
#include "sink.h"
#include "filters.h"
#include <stdio.h>

Shrinker::Shrinker(){
    GetOutput()->setSrc(this);
}

void Shrinker::Execute(){
    if(!getInput()->isUpdated){
        getInput()->Update();
    }
    int inWidth;
    int inHeight;
    inWidth = getInput()->getWidth();
    inHeight = getInput()->getHeight();
    int outWidth, outHeight;
    outWidth = inWidth/2;
    outHeight = inHeight/2;
    
    GetOutput()->resetSize(outWidth, outHeight);
    
    for(int h = 0; h<outHeight; h++){
        for(int w = 0; w<outWidth; w++){
            GetOutput()->getBuffer()[w + outWidth*h] = getInput()->getBuffer()[w*2 + inWidth*2*h];
        }
    }
}

LRConcat::LRConcat(){
    GetOutput()->setSrc(this);
}

void LRConcat::Execute(){
    if(!getInput()->isUpdated){
        getInput()->Update();
    }
    if(!getInput2()->isUpdated){
        getInput2()->Update();
    }
    GetOutput()->resetSize(getInput()->getWidth() + getInput2()->getWidth(), getInput()->getHeight());
    for(int h = 0; h<getInput()->getHeight(); h++){
        for(int w = 0; w < GetOutput()->getWidth(); w++){
            if(w < getInput()->getWidth()){
                GetOutput()->getBuffer()[w + GetOutput()->getWidth()*h] = getInput()->getBuffer()[w + getInput()->getWidth()*h];
            }
            else {
                GetOutput()->getBuffer()[w + GetOutput()->getWidth()*h] = getInput2()->getBuffer()[(w-getInput()->getWidth()) + getInput2()->getWidth()*h];
            }
        }
    }
}

TBConcat::TBConcat(){
    GetOutput()->setSrc(this);
}

void TBConcat::Execute(){
    if(!getInput()->isUpdated){
        getInput()->Update();
    }
    if(!getInput2()->isUpdated){
        getInput2()->Update();
    }
    GetOutput()->resetSize(getInput()->getWidth(), getInput()->getHeight() + getInput2()->getHeight());
    for(int h = 0; h < GetOutput()->getHeight(); h++){
        for(int w = 0; w<getInput()->getWidth(); w++){
            if(h<getInput()->getHeight()){
                GetOutput()->getBuffer()[w + GetOutput()->getWidth()*h] = getInput()->getBuffer()[w + getInput()->getWidth()*h];
            }
            else{
                GetOutput()->getBuffer()[w + GetOutput()->getWidth()*h] = getInput2()->getBuffer()[w + getInput2()->getWidth()*(h-getInput()->getHeight())];
            }
        }
    }
}

Blender::Blender(){
    GetOutput()->setSrc(this);
}

void Blender::Execute(){
    if(!getInput()->isUpdated){
        getInput()->Update();
    }
    if(!getInput2()->isUpdated){
        getInput2()->Update();
    }
    GetOutput()->resetSize(getInput()->getWidth(), getInput()->getHeight());
    for(int i = 0; i<getInput()->getWidth()*getInput()->getHeight(); i++){
        GetOutput()->getBuffer()[i].red = getInput()->getBuffer()[i].red * factor + getInput2()->getBuffer()[i].red * (1-factor);
        GetOutput()->getBuffer()[i].green = getInput()->getBuffer()[i].green * factor + getInput2()->getBuffer()[i].green * (1-factor);
        GetOutput()->getBuffer()[i].blue = getInput()->getBuffer()[i].blue * factor + getInput2()->getBuffer()[i].blue * (1-factor);
    }
}
void Blender::SetFactor(double f){
    factor = f;
}