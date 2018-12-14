#include <iostream>
#include "RNAClass.h"
#include <cstring>

using namespace std;

string getRNATypeName (int type)
{
    if (type==0)
        return "mRNA";
    else if (type==1)
        return "pre_mRNA";
    else if (type==2)
        return "mRNA_exon";
    else if (type==3)
        return "mRNA_intron";
}

RNA::RNA()
{

}

RNA::RNA(char * seq, RNA_Type atype)
{
    this->seq = seq;
    type = atype;
}

RNA::RNA(const RNA& rhs)
{
    seq = new char;
    seq = rhs.seq;
    type = rhs.type;
}

RNA::~RNA() {}

RNA_Type RNA::getType()
{
    return type;
}

void RNA::Print()
{
    cout << seq << "\nThe type of RNA sequence is " << getRNATypeName(type) << endl;
}

// function to convert the RNA sequence into protein sequence
// using the codonsTable object
Protein RNA::ConvertToProtein(CodonsTable & table)
{
    char value[4]= {'\0'};
    char *proteinSeq=new char[(strlen(seq)/3)+1];
    proteinSeq[0]='\0';
    for (int i=0 ; i<(int)strlen(seq) ; i++)
    {
        value[i%3]=seq[i];
        if ((i+1)%3==0)
        {
            value[3]='\0';
            Codon c=table.getAminoAcid(value);
            proteinSeq[(i+1)/3-1]=c.AminoAcid;
        }
    }
    proteinSeq[strlen(seq)/3]='\0';
    while (proteinSeq[strlen(proteinSeq)-1]==' ')
        proteinSeq[strlen(proteinSeq)-1]='\0';
    string ex = "There is no protein sequence corresponds this RNA sequence or may it contain only stop codons";
    if (strlen(proteinSeq)==0)
        throw ex;
    else
    {
        Protein p(proteinSeq);
        return p;
    }
}
DNA RNA::ConvertToDNA()
{
    char *newS = new char[strlen(seq)+1];
    newS[0]='\0';
    for (int i=0 ; i<strlen(seq) ; i++)
    {
        if (seq[i] == 'A')
            newS[strlen(seq)-i-1] = 'T';
        else if (seq[i] == 'U')
            newS[strlen(seq)-i-1] = 'A';
        else if (seq[i] == 'G')
            newS[strlen(seq)-i-1] = 'C';
        else if (seq[i] == 'C')
            newS[strlen(seq)-i-1] = 'G';

    }
    newS[strlen(seq)]='\0';
    DNA d1(newS, d1.getType());
    return d1;
}

bool RNA::operator==(RNA r)
{
    bool x = true;
    for (int i=0 ; i<(int)strlen(seq) ; i++)
    {
        if (seq[i]!=r.seq[i])
        {
            x = false;
            break;
        }
    }
    return x;
}

bool RNA::operator!=(RNA r)
{
    bool x = false;
    for (int i=0 ; i<(int)strlen(seq) ; i++)
    {
        if (seq[i]!=r.seq[i])
        {
            x = true;
            break;
        }
    }
    return x;
}

RNA RNA::operator = (RNA r)
{
    seq=r.seq;
}

RNA RNA::operator + (RNA r)
{
    char *newSeq=new char[strlen(seq)+strlen(r.seq)+1];
    newSeq[0]='\0';
    strcat(newSeq,seq);
    strcat(newSeq,r.seq);
    newSeq[strlen(seq)+strlen(r.seq)]='\0';
    RNA newRNA(newSeq,mRNA);
    return newRNA;
}

std::istream& operator >> (std::istream& in, RNA& r)
{
    int len;
    cout << "Enter the length of the sequence : ";
    cin >> len;
    string ex="Invalid RNA sequence .. try to enter another one (contains only A,U,C  or G)";
    r.seq=new char[len+1];
    cout << "Enter the sequence : ";
    for (int i=0 ; i<len ; i++)
    {
        in >> r.seq[i];
    }
    for (int i=0 ; i<len ; i++)
    {
        if (r.seq[i]!='A' && r.seq[i]!='U' && r.seq[i]!='C' && r.seq[i]!='G')
        {
            throw ex;
        }
    }
    r.seq[len]='\0';
    cout << "Choose RNA type : ";
    for (int i=0 ; i<4 ; i++)
        cout << i+1 << "-" << getRNATypeName(i) << "   ";
    cout << endl;
    int type;
    cin >> type;
    r.type=RNA_Type(type);
    return in;
}

std::ostream& operator << (std::ostream& out, RNA r)
{
    out << r.seq;
    return out;
}

