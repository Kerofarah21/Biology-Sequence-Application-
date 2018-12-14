#ifndef SEQUENCECLASS_H_INCLUDED
#define SEQUENCECLASS_H_INCLUDED

class Sequence
{
protected:
    char * seq;
public:
    // constructors and destructor
    Sequence();
    Sequence(int length);
    Sequence(const Sequence& rhs);
    virtual ~Sequence();
    Sequence operator = (Sequence s);
    // pure virtual function that should be overridden because every
    // type of sequence has its own details to be printed
    virtual void Print();
};

#endif // SEQUENCECLASS_H_INCLUDED
