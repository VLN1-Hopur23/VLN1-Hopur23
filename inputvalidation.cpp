#include "inputvalidation.h"
#include <string>

InputValidation::InputValidation()
{

}
string InputValidation::typeOf(string what)
{
    int whatSize = what.size();
    while(what.substr(whatSize-1,whatSize) ==" ")
    {
        what = what.substr(0,whatSize-1);
        whatSize = what.size();
    }
    int whatArrayInt[whatSize] = {};
    bool whatIsInt[whatSize] = {false};
    bool whatIsAlphabet[whatSize] = {false};
    bool whatIsAlowedChar[whatSize] = {false};
    bool whatNotValidated[whatSize] = {false};

    for(int i =0; i<whatSize; i++)
    {
        whatArrayInt[i] = int(what.substr(i,i+1));

    }
    for(int i = 0; i<whatSize; i++)
    {
        if(whatArrayInt[i] >=48 && whatArrayInt[i] <=57) //48 ='0' ...57 ='9'
        {
            whatIsInt[i]=true;
        }
        else if((whatArrayInt[i] >=65 && whatArrayInt[i] <= 90) || (whatArrayInt[i] >=97 && whatArrayInt[i] <=122) || (whatArrayInt[i] ==32) )//65 = 'A', 90='Z', 97='a',122='z',32 =SPACE
        {
            whatIsAlphabet[i] = true;
        }
        else if(whatArrayInt[i] == 46 || whatArrayInt[i] == 44 ) // 46='.', 44 = ',',
        {
           whatIsAlowedChar[i] =true;
        }
        else
        {
            whatNotValidated[i] = true;
        }
    }
    bool ThereAreSomeCharNotValidated = false;
    bool ThereAreSomeInt = false;
    bool ThereAreSomeAlphabet = false;
    bool ThereAreSomeAlowedChar = false;
    for(int i =0; i<whatSize; i++)
    {
        if(whatIsInt[i])
        {
            ThereAreSomeInt = true;
        }
        else if(whatIsAlphabet[i])
        {
            ThereAreSomeAlphabet = true;

        }
        else if(whatIsAlowedChar[i])
        {
            ThereAreSomeAlowedChar =true;
        }
        else
        {
            ThereAreSomeCharNotValidated =true;
        }
    }
    if(ThereAreSomeCharNotValidated)
    {
        return "NV"; //has: Not Validated input
    }
    else if(ThereAreSomeAlphabet && ThereAreSomeAlowedChar && ThereAreSomeInt)
    {
        return "ACI"; //has onlie: Alphabet, char, int
    }
    else if(ThereAreSomeAlowedChar && ThereAreSomeAlphabet)
    {
        return "AC"; //has onlie: Alphabet, char
    }
    else if(ThereAreSomeAlowedChar && ThereAreSomeInt)
    {
        return "CI"; //has onlie: char , int
    }
    else if(ThereAreSomeAlphabet && ThereAreSomeInt)
    {
        return "AI"; // has onlie: Alphabet, int
    }
    else if(ThereAreSomeAlphabet)
    {
        return "A"; // has onlie: Alphabet
    }
    else if(ThereAreSomeAlowedChar)
    {
        return "C"; // has onlie: char
    }
    else if(ThereAreSomeInt)
    {
        return "I"; // has onlie: int

    }
    else
    {
        return "error in localtime::typeOf(string what)";
    }



}
