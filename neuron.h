#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <string>

using namespace std;

class Neuron
{
    struct weights{
        double w1;
        double w2;
    }weights;
    unsigned short ins[2];
    unsigned short out;
    unsigned short choose_activate_function;

public:
    Neuron(double d1, double d2, unsigned short func);
    Neuron(double d1, double d2);
    void setIns(unsigned short in1, unsigned short in2);
    double sum();
    unsigned short stepFunction();
    unsigned short linearFunction(int a, int b);
    unsigned short sigmoidFunction();
    void correctWeights(unsigned short wanted_result, int aa, int bb);
    void foo(int aa, int bb);
    void learnOperation(string in1, string in2, string out, int limit);
    void doSomethig(unsigned short in1, unsigned short in2);
};

#endif // NEURON_H
