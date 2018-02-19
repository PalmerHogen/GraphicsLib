#ifndef SOURCE
#define SOURCE

#include "image.h"

class Source{
public:
    Image* GetOutput();
    virtual void Update();
protected:
    virtual void Execute() =0;
    Image output;
};

#endif