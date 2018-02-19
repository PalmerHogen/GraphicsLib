#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "sink.h"

void Sink::SetInput(Image* a){
    input = a;
}

void Sink::SetInput2(Image* b){
    input2 = b;
}

Image* Sink::getInput(){
    return input;
}

Image* Sink::getInput2(){
    return input2;
}