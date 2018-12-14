#ifndef PROTEINCLASS_H_INCLUDED
#define PROTEINCLASS_H_INCLUDED
#include "SequenceClass.h"
#include <iostream>
#include <vector>

class DNA;

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};
std::string getProteinTypeName (int type);

class Protein : public Sequence
{
private:
    Protein_Type type;
public:
    // constructors and destructor
    Protein();
    Protein(char * p);
    Protein(const Protein& rhs);
    ~Protein();
    // function to be overridden to print all the RNA information
    void Print();
    Protein_Type getType();
    // operators
    bool operator == (Protein p);
    bool operator != (Protein p);
    Protein operator = (Protein p);
    Protein operator + (Protein p);
    friend std::istream& operator >> (std::istream& in, Protein& p);
    friend std::ostream& operator << (std::ostream& out, Protein p);
    // return an array of DNA sequences that can possibly
    // generate that protein sequence
    DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);
};

std::istream& operator >> (std::istream& in, Protein& p);
std::ostream& operator << (std::ostream& out, Protein p);

#endif // PROTEINCLASS_H_INCLUDED
