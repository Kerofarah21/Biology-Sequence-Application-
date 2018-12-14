#ifndef _DNA_H
#define _DNA_H

#include <iostream>
#include <sstream>
#include "SequenceClass.h"
#include "RNAClass.h"

class RNA;

enum DNA_Type {promoter, motif, tail, noncoding};
std::string getDNATypeName (int type);
class DNA : public Sequence
{
private:
    DNA_Type type;
    DNA * complementary_strand;
    int startIndex;
    int endIndex;
    char * newS;
public:
    // constructors and destructor
    DNA();
    DNA(char * seq, DNA_Type atype);
    DNA(const DNA& rhs);
    ~DNA();
    // setters and getters
    DNA_Type getType();
    DNA getComplementaryStrand();
    // function printing DNA sequence information to user
    void Print();
    // function to convert the DNA sequence to RNA sequence
    // It starts by building the complementary_strand of the current
    // DNA sequence (starting from the startIndex to the endIndex), then,
    // it builds the RNA corresponding to that complementary_strand.
    RNA ConvertToRNA();
    // function to build the second strand/pair of DNA sequence
    // To build a complementary_strand (starting from the startIndex to
    // the endIndex), convert each A to T, each T to A, each C to G, and
    // each G to C. Then reverse the resulting sequence.
    void BuildComplementaryStrand();
    // operators
    bool operator == (DNA d);
    bool operator != (DNA d);
    DNA operator = (DNA d);
    DNA operator + (DNA d);
    friend std::istream& operator >> (std::istream& in, DNA& d);
    friend std::ostream& operator << (std::ostream& out, DNA d);
};

std::istream& operator >> (std::istream& in, DNA& d);
std::ostream& operator << (std::ostream& out, DNA d);

#endif // _DNA_H
