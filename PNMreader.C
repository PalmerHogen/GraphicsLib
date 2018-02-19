#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "image.h"
#include "source.h"
#include "PNMreader.h"

PNMreader::PNMreader(char* infile){
    int length = strlen(infile);
    filename = new char[length+1];
    strcpy(filename, infile);
    GetOutput()->setSrc(this);
}
PNMreader::~PNMreader(){
    delete [] filename;
}
void PNMreader::Execute(){
    FILE* f_in;
    f_in = fopen(filename, "r");
    
    char magicNum[128];
    int width, height, maxval;
    fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
    GetOutput()->resetSize(width, height);
    
    fread(GetOutput()->getBuffer(), sizeof(Pixel), width*height, f_in);
    fclose(f_in);
}
