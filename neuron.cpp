#include "neuron.h"
#include <math.h>
#include <iostream>

#define LEARNING_RATE     0.2
#define EXP               2.718

Neuron::Neuron(double d1, double d2, unsigned short func){
    weights.w1=d1;
    weights.w2=d2;
    this->choose_activate_function=func;
}

Neuron::Neuron(double d1, double d2){
    weights.w1=d1;
    weights.w2=d2;
    this->choose_activate_function=0;
}

void Neuron::setIns(unsigned short in1, unsigned short in2){
    ins[0]=in1;
    ins[1]=in2;
}

double Neuron::sum(){
    return weights.w1*ins[0] + weights.w2*ins[1];
}

unsigned short Neuron::stepFunction(){
    double summ=sum();
    return (summ>0.6) ? 1 : 0;
}

unsigned short Neuron::linearFunction(int a, int b){
    double summ=sum();
    return a*summ+b;
}

unsigned short Neuron::sigmoidFunction(){
    double summ=sum();
    return (short)(1/(1+ pow(EXP,(-summ))));
}

void Neuron::correctWeights(unsigned short wanted_result, int aa, int bb){
    foo(aa, bb);
    unsigned short current_result=out;
    double new_w1, new_w2;
    new_w1 = weights.w1 + ((ins[0] * (wanted_result - current_result)) * LEARNING_RATE);
    weights.w1=new_w1;
    new_w2 = weights.w2 + ((ins[1] * (wanted_result - current_result)) * LEARNING_RATE);
    weights.w2=new_w2;

}

void Neuron::foo(int aa, int bb){
    if(choose_activate_function==0)
        this->out = stepFunction();
    if(choose_activate_function==1)
        this->out = linearFunction(aa,bb);
    if(choose_activate_function==2)
       this->out = sigmoidFunction();
}

void Neuron::learnOperation(string in1, string in2, string out, int limit){
    for(int i=0; i<50000; i++){
       int indeks = rand()%limit;
       ins[0]=(in1[indeks] - '0');
       ins[1]=(in2[indeks] - '0');
       unsigned short temp = (out[indeks] - '0');
       correctWeights(temp, 0, 0);
    }
}

void Neuron::doSomethig(unsigned short in1, unsigned short in2){
    ins[0]=in1;
    ins[1]=in2;

    foo(0, 0);

    cout<<this->out<<endl;
}
