#include <iostream>
#include "SequenceClass.h"
#include "DNAClass.h"
#include "RNAClass.h"
#include "ProteinClass.h"
#include "CodonTableClass.h"
using namespace std;

int main()
{
    CodonsTable allCodons;
    allCodons.LoadCodonsFromFile("RNA_codon_table.txt");
    int nd=0, nr=0, np=0;
    DNA* D = new DNA[10];
    RNA* R = new RNA[10];
    Protein* P = new Protein[10];
    while (true)
    {
        cout << "What do you want to do" << endl;
        cout << "1- Enter a new sequence\n2- Convert from DNA\n3- Convert from RNA" << endl;
        cout << "4- Get DNA that generates some stored Protein\n5- Show all stored sequences" << endl;
        cout << "0- close the application" << endl;
        char choose;
        cin >> choose;
        if (choose=='1')
        {
            while (true)
            {
                cout << "Which type you want to enter : a- DNA b- RNA" << endl;
                char choice;
                cin >> choice;
                if (choice=='a')
                {
                    try
                    {
                        cin >> D[nd];
                        nd++;
                        break;
                    }
                    catch (string msg)
                    {
                        cout << msg << endl;
                    }
                }
                else if (choice=='b')
                {
                    try
                    {
                        cin >> R[nr];
                        nr++;
                        break;
                    }
                    catch (string msg)
                    {
                        cout << msg << endl;
                    }
                }
                else
                    cout << "Please choose from the valid choices only" << endl;
            }
        }
        else if (choose=='2')
        {
            if (nd>0)
            {
                char toconvert;
                while (true)
                {
                    cout << "Convert to : a- RNA   b- Protein   c- Show Complementary strand" << endl;
                    cin >> toconvert;
                    if (toconvert != 'a' && toconvert != 'b' && toconvert != 'c')
                        cout << "Invalid choice" << endl;
                    else
                        break;
                }
                cout << "Choose from stored DNAs" << endl;
                bool found=true;
                while (found)
                {
                    for (int i=0 ; i<nd ; i++)
                        cout << i+1 << "- DNA" << i+1 << " -> " << D[i] << endl;
                    int choice;
                    cin >> choice;
                    while (choice>0 && choice<=nd)
                    {
                        try
                        {
                            if (toconvert=='a')
                            {
                                R[nr]=D[choice-1].ConvertToRNA();
                                nr++;
                                cout << "The resulted RNA stored as RNA" << nr << " -> " << R[nr-1] << endl << endl;
                            }
                            else if (toconvert=='b')
                            {
                                R[nr]=D[choice-1].ConvertToRNA();
                                P[np]=R[nr].ConvertToProtein(allCodons);
                                np++;
                                cout << "The resulted Protein stored as Protein" << np << " -> " << P[np-1] << endl << endl;
                            }
                            else
                                cout << D[choice-1].getComplementaryStrand() << endl << endl;
                            found=false;
                            break;
                        }
                        catch (string msg)
                        {
                            cout << msg << endl;
                        }
                    }
                    if (choice>nd || choice<0)
                        cout << "Invalid choice .. choose from these DNAs" << endl;
                }
            }
            else
                cout << "No DNAs stored yet" << endl << endl;
        }
        else if (choose=='3')
        {
            if (nr>0)
            {
                char toconvert;
                while (true)
                {
                    cout << "Convert to : a- DNA b- Protein" << endl;
                    cin >> toconvert;
                    if (toconvert != 'a' && toconvert !='b')
                        cout << "Invalid choice" << endl;
                    else
                        break;
                }
                cout << "Choose from stored RNAs" << endl;
                bool found=true;
                while (found)
                {
                    for (int i=0 ; i<nr ; i++)
                        cout << i+1 << "- RNA" << i+1 << " -> " << R[i] << endl;
                    int choice;
                    cin >> choice;
                    while (choice>0 && choice<=nr)
                    {
                        try
                        {
                            if (toconvert=='a')
                            {
                                D[nd]=R[choice-1].ConvertToDNA();
                                nd++;
                                cout << "The resulted DNA stored as DNA" << nd << " -> " << D[nd-1] << endl << endl;
                            }
                            else
                            {
                                P[np]=R[choice-1].ConvertToProtein(allCodons);
                                np++;
                                cout << "The resulted Protein stored as Protein" << np << " -> " << P[np-1] << endl << endl;
                            }
                            found=false;
                            break;
                        }
                        catch (string msg)
                        {
                            cout << msg << endl;
                        }
                    }
                    if (choice>nr || choice<=0)
                        cout << "Invalid choice .. choose from these RNAs" << endl;
                }
            }
            else
                cout << "No RNAs stored yet" << endl << endl;
        }
        else if (choose=='4')
        {
            if (np>0)
            {
                cout << "Choose from stored Proteins" << endl;
                for (int i=0 ; i<np ; i++)
                    cout << "Protein" << i << " -> " << P[i];
            }
            else
                cout << "No Proteins stored yet" << endl << endl;
        }
        else if (choose=='5')
        {
            if (nd>0)
            {
                cout << "DNAs :" << endl;
                for (int i=0 ; i<nd ; i++)
                {
                    cout << i+1 << "- DNA -> " ;
                    D[i].Print();
                }
            }
            else
                cout << "No stored DNAs yet" << endl;
            cout << endl;
            if (nr>0)
            {
                cout << "RNAs :" << endl;
                for (int i=0 ; i<nr ; i++)
                {
                    cout << i+1 << "- RNA -> " ;
                    R[i].Print();
                }
            }
            else
                cout << "No stored RNAs yet" << endl;
            cout << endl;
            if (np>0)
            {
                cout << "Proteins :" << endl;
                for (int i=0 ; i<np ; i++)
                {
                    cout << i+1 << "- Protein -> " ;
                    P[i].Print();
                }
            }
            else
                cout << "No stored Proteins yet" << endl;
            cout << endl;
        }
        else if (choose=='0')
            return 0;
        else
            cout << "Choose from these choices only" << endl;
    }
    return 0;
}
