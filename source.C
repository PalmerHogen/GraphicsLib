#include <stdio.h>
#include <stdlib.h>
#include "source.h"
#include "image.h"

Image* Source::GetOutput(){
    return &output;
}

void Source::Update(){
    Execute();
}