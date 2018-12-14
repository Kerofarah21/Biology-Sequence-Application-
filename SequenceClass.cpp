#include "SequenceClass.h"
#include <iostream>

// constructors and destructor
Sequence::Sequence()
{

}
Sequence::Sequence(int length)
{
    seq = new char[length];
}
Sequence::Sequence(const Sequence& rhs)
{
    seq = new char;
    seq = rhs.seq;
}
Sequence::~Sequence()
{

}

Sequence Sequence::operator = (Sequence s)
{
    seq=s.seq;
}

// pure virtual function that should be overridden because every
// type of sequence has its own details to be printed
void Sequence::Print()
{

}
