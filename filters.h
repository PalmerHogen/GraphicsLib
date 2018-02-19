#ifndef FILTERS
#define FILTERS
#include "image.h"
#include "source.h"
#include "sink.h"

class Filter : public Source, public Sink{
    
};

class Shrinker : public Filter{
public:
    void Execute();
    Shrinker();
private:
    void HalveInSize(Image &input, Image &output);
};

class LRConcat : public Filter{
public:
    void Execute();
    LRConcat();
};

class TBConcat : public Filter{
public:
    void Execute();
    TBConcat();
};

class Blender : public Filter{
public:
    void Execute();
    void SetFactor(double f);
    Blender();
private:
    double factor;
};
#endif