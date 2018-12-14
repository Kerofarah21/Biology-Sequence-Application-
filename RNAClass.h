#ifndef _RNA_H
#define _RNA_H

#include <iostream>
#include "SequenceClass.h"
#include "DNAClass.h"
#include "ProteinClass.h"
#include "CodonTableClass.h"
class Protein;
class CodonsTable;
class DNA;

enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};
std::string getRNATypeName (int type);
class RNA : public Sequence
{
private:
    RNA_Type type;
public:
    // constructors and destructor
    RNA();
    RNA(char * seq, RNA_Type atype);
    RNA(const RNA& rhs);
    ~RNA();
    RNA_Type getType();
    // function to be overridden to print all the RNA information
    void Print();
    // function to convert the RNA sequence into protein sequence
    // using the codonsTable object
    Protein ConvertToProtein(CodonsTable & table);
    // function to convert the RNA sequence back to DNA
    DNA ConvertToDNA();
    // operators
    bool operator == (RNA r);
    bool operator != (RNA r);
    RNA operator = (RNA r);
    RNA operator + (RNA r);
    friend std::istream& operator >> (std::istream& in, RNA& r);
    friend std::ostream& operator << (std::ostream& out, RNA r);
};

std::istream& operator >> (std::istream& in, RNA& r);
std::ostream& operator << (std::ostream& out, RNA r);

#endif // _RNA_H
