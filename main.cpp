#include <iostream>
#include <cstdlib>
#include <string>
#include "neuron.h"

int main()
{
    srand(time(NULL));

    string OR_in1="10011101101101101100111001010100110001001101100";
    string OR_in2="01010101000100111010110100101101001100001011001";
    string OR_res="11011101101101111110111101111101111010011111011";

    string AND_in1="10011101101101101100111001010100110001001101100";
    string AND_in2="01010101000100111010110100101101001100001011001";
    string AND_res="00010101000100101000110000000100000000001001000";

    double w1=(double)rand()/RAND_MAX;
    double w2=(double)rand()/RAND_MAX;

    int limit_OR = OR_in1.length();
    int limit_AND = AND_in1.length();

    Neuron *n1 = new Neuron(w1, w2);
    n1->learnOperation(OR_in1, OR_in2, OR_res, limit_OR);

    Neuron *n2 = new Neuron(w1, w2);
    n2->learnOperation(AND_in1, AND_in2, AND_res, limit_AND);

    unsigned short i1, i2;

    while (true){  //nieskonczona zeby sobie nie wlaczac tego za kazdym razem
        cin>>i1>>i2;
        cout << "OR:" <<endl;
        n1->doSomethig(i1,i2);
        cout << "AND:"<<endl;
        n2->doSomethig(i1,i2);
    }
    delete n1;
    delete n2;
    return 0;
}
