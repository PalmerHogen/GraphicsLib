#ifndef PNMREADER
#define PNMREADER

#include "image.h"
#include "source.h"

class PNMreader : public Source{
public:
    PNMreader(char* infile);
    ~PNMreader();
    void Execute();
private:
    char* filename;
};

#endif