#ifndef CODONTABLECLASS_H_INCLUDED
#define CODONTABLECLASS_H_INCLUDED
#include <iostream>
struct Codon
{
    char value[4];    	    // 4th location for null character
    char AminoAcid;  	    // corresponding AminoAcid according to Table
};

// need to create one object of that class to load the AminoAcids table
// into memory
class CodonsTable
{
private:
    Codon codons[64];
public:
    // constructors and destructor
    CodonsTable();
    ~CodonsTable();
    // function to load all codons from the given text file
    void LoadCodonsFromFile(std::string codonsFileName);
    Codon getAminoAcid(char * value);
    void setCodon(char * value, char AminoAcid, int index);
};

#endif // CODONTABLECLASS_H_INCLUDED
