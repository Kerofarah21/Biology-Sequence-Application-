#include "CodonTableClass.h"
#include <cstring>
#include <fstream>
using namespace std;
// constructors and destructor
CodonsTable::CodonsTable()
{

}
CodonsTable::~CodonsTable()
{

}
// function to load all codons from the given text file
void CodonsTable::LoadCodonsFromFile(std::string codonsFileName)
{
    int i=0;
    char value[4];
    char AminoAcid;
    char CFN[codonsFileName.length()+1];
    strcpy(CFN,codonsFileName.c_str());
    ifstream Table(CFN);
    while (!Table.eof())
    {
        Table >> value ;
        if (strcmp(value,"UAA")==0 || strcmp(value,"UAG")==0 || strcmp(value,"UGA")==0)
        {
            AminoAcid=' ';
        }
        else
            Table >> AminoAcid;
        setCodon(value,AminoAcid,i);
        i++;

    }
    Table.close();
}
Codon CodonsTable::getAminoAcid(char * value)
{
    int thisCodon=0;
    for (int i=0 ; i< 64 ; i++)
    {
        if (strcmp((codons[i].value),value)==0)
        {
            thisCodon=i;
            break;
        }
    }
    return codons[thisCodon];
}
void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{
    strcpy(codons[index].value,value);
    codons[index].AminoAcid=AminoAcid;
}
