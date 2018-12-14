#include "ProteinClass.h"
#include <cstring>
#include <iostream>

using namespace std;

string getProteinTypeName (int type)
{
    if (type==0)
        return "Hormon";
    else if (type==1)
        return "Enzyme";
    else if (type==2)
        return "TF";
    else if (type==3)
        return "Cellular_Function";
}
// constructors and destructor
Protein::Protein()
{

}
Protein::Protein(char * p)
{
    seq=p;
    type=Cellular_Function;
}
Protein::Protein(const Protein& rhs)
{
    seq = new char;
    seq = rhs.seq;
    type = rhs.type;
}
Protein::~Protein()
{

}
Protein_Type Protein::getType()
{
    return type;
}

// return an array of DNA sequences that can possibly
// generate that protein sequence
DNA* Protein::GetDNAStrandsEncodingMe(const DNA & bigDNA)
{

}
// function to be overridden to print all the RNA information
void Protein::Print()
{
    cout << seq << "\nThe type of Protein sequence is " << getProteinTypeName(type%4) << endl;
}
bool Protein::operator==(Protein p)
{
    bool x = true;
    for (int i=0 ; i<(int)strlen(seq) ; i++)
    {
        if (seq[i]!=p.seq[i])
        {
            x = false;
            break;
        }
    }
    return x;
}

bool Protein::operator!=(Protein p)
{
    bool x = false;
    for (int i=0 ; i<(int)strlen(seq) ; i++)
    {
        if (seq[i]!=p.seq[i])
        {
            x = true;
            break;
        }
    }
    return x;
}
Protein Protein::operator = (Protein p)
{
    seq = p.seq;
}
Protein Protein::operator + (Protein p)
{
    char *newSeq=new char[strlen(seq)+strlen(p.seq)+2];
    newSeq[0]='\0';
    strcat(newSeq,seq);
    strcat(newSeq," ");
    strcat(newSeq,p.seq);
    newSeq[strlen(seq)+strlen(p.seq)+1]='\0';
    Protein newProtein(newSeq);
    return newProtein;
}

std::ostream& operator << (std::ostream& out, Protein p)
{
    out << p.seq;
    return out;
}
