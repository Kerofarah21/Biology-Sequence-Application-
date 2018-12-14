#include <iostream>
#include <cstring>
#include "DNAClass.h"

using namespace std;

string getDNATypeName (int type)
{
    if (type==0)
        return "promoter";
    else if (type==1)
        return "motif";
    else if (type==2)
        return "tail";
    else if (type==3)
        return "noncoding";
}
DNA::DNA()
{

}

DNA::DNA(char * seq, DNA_Type atype)
{
    this->seq = seq;
    type = atype;
}

DNA::DNA(const DNA& rhs)
{
    seq = new char;
    seq = rhs.seq;
    type = rhs.type;
}

DNA::~DNA() {}

DNA_Type DNA::getType()
{
    return type;
}

DNA DNA::getComplementaryStrand()
{
    BuildComplementaryStrand();
    return *complementary_strand;
}

void DNA::Print()
{
    cout << seq << "\nThe type of DNA sequence is " << getDNATypeName(type) << endl;
}

RNA DNA::ConvertToRNA()
{
    BuildComplementaryStrand();
    newS=new char[strlen(complementary_strand->seq+1)];
    newS[0]='\0';
    for (int i=0 ; i<strlen(complementary_strand->seq) ; i++)
    {
        if (complementary_strand->seq[i] == 'T')
            newS[i] = 'U';
        else
            newS[i]=complementary_strand->seq[i];
    }
    newS[strlen(complementary_strand->seq)]='\0';
    RNA r1(newS, mRNA);
    return r1;
}

void DNA::BuildComplementaryStrand()
{
    cout << "Enter the start index : ";
    cin >> startIndex;
    cout << "Enter the end index : ";
    cin >> endIndex;
    string ex = "Invalid indexes .. choose your index from 1 to ";
    stringstream l;
    l << strlen(seq);
    ex+= l.str() + " or enter -1 for both to convert the whole sequence";
    int len;
    if (startIndex == -1 && endIndex == -1)
    {
        len=strlen(seq);
        startIndex=0;
    }
    else if (startIndex>=1 && endIndex >=startIndex && endIndex<=strlen(seq))
        len = (endIndex - startIndex)+1;
    else
        throw ex;
    newS = new char[len+1];
    newS[0]='\0';
    for (int i=0, j=startIndex-1 ; i<len ; j++, i++)
    {
        if (seq[j] == 'A')
            newS[len-i-1] = 'T';
        else if (seq[j] == 'T')
            newS[len-i-1] = 'A';
        else if (seq[j] == 'G')
            newS[len-i-1] = 'C';
        else if (seq[j] == 'C')
            newS[len-i-1] = 'G';

    }
    newS[len]='\0';
    complementary_strand = new DNA(newS, this->type);
}

bool DNA::operator==(DNA d)
{
    bool x = true;
    for (int i=0 ; i<(int)strlen(seq) ; i++)
    {
        if (seq[i]!=d.seq[i])
        {
            x = false;
            break;
        }
    }
    return x;
}

bool DNA::operator!=(DNA d)
{
    bool x = false;
    for (int i=0 ; i<(int)strlen(seq) ; i++)
    {
        if (seq[i]!=d.seq[i])
        {
            x = true;
            break;
        }
    }
    return x;
}
DNA DNA::operator = (DNA d)
{
    seq=d.seq;
}
DNA DNA::operator + (DNA d)
{
    char *newSeq=new char[strlen(seq)+strlen(d.seq)+1];
    newSeq[0]='\0';
    strcat(newSeq,seq);
    strcat(newSeq,d.seq);
    newSeq[strlen(seq)+strlen(d.seq)]='\0';
    DNA newDNA(newSeq,promoter);
    return newDNA;
}

std::istream& operator >> (std::istream& in, DNA& d)
{
    int len;
    cout << "Enter the length of the sequence : ";
    cin >> len;
    string ex="Invalid DNA sequence .. try to enter another one (contains only A,T,C  or G)";
    d.seq=new char[len+1];
    cout << "Enter the sequence : ";
    for (int i=0 ; i<len ; i++)
    {
        in >> d.seq[i];
    }
    for (int i=0 ; i<len ; i++)
    {
        if (d.seq[i]!='A' && d.seq[i]!='T' && d.seq[i]!='C' && d.seq[i]!='G')
        {
            throw ex;
        }
    }
    d.seq[len]='\0';
    cout << "Choose DNA type : ";
    for (int i=0 ; i<4 ; i++)
        cout << i+1 << "-" << getDNATypeName(i) << "   ";
    cout << endl;
    int type;
    cin >> type;
    d.type=DNA_Type(type-1);
    return in;
}

std::ostream& operator << (std::ostream& out, DNA d)
{
    out << d.seq;
    return out;
}

