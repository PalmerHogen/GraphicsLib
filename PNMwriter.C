#include "image.h"
#include "PNMwriter.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void PNMwriter::Write(char* filename){
    FILE* outFile;
    outFile = fopen(filename, "w");
    fprintf(outFile, "%s\n%d %d\n%d\n", "P6", getInput()->getWidth(), getInput()->getHeight(), 255);
    fwrite(getInput()->getBuffer(), sizeof(Pixel), (getInput()->getWidth())*(getInput()->getHeight()), outFile);
    fclose(outFile);
}
