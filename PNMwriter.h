#ifndef PNMWRITER
#define PNMWRITER
#include "image.h"
#include "sink.h"

class PNMwriter : public Sink{
public:
    void Write(char* filename);
};



#endif