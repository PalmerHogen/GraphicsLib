#ifndef SINK
#define SINK

class Sink{
protected:
    Image* input;
    Image* input2;
public:
    void SetInput(Image* a);
    void SetInput2(Image* b);
    Image* getInput();
    Image* getInput2();
};

#endif