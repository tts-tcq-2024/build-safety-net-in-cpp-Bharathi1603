#include "Soundex.h"
#include <cctype>

char getSoundexCode(char c) {
    c = toupper(c);
    switch (c) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // For A, E, I, O, U, H, W, Y
    }
}
bool isFirstTwoLettersSame(const std::string& name)
{
    if(name.length() < 2)
    {
        return false;
    }
    return getSoundexCode(name[0]) == getSoundexCode(name[1]);
}

bool isTwoLettersWithSameDigit(std::string& name, std::uint8_t index)
{
    if((name.length() - index) >= 3)
    {
        if(getSoundexCode(name[index]) == getSoundexCode(name[index + 2]))
        {
            return true;
        }
    }
    return false;
}

bool isTwoConsecutiveLettersSame(std::string& name, std::uint8_t index)
{
    if((name.length() - index) >= 2)
    {
        if(getSoundexCode(name[index]) == getSoundexCode(name[index + 1]))
        {
            return true;
        }
    }
    return false;
}

bool isVowelPresent(char ch) {
    std::string vowels = "aeiou";
    for (char vowel : vowels) 
    {
        if (tolower(ch) == vowel) {
            return true;
        }
    }
    return false;
}

bool isOtherConsonantPresent(char ch) {
    std::string otherConsonants = "hwy";
    for (char otherConsonant : otherConsonants) 
    {
        if (tolower(ch) == otherConsonant) {
            return true;
        }
    }
    return false;
}

void removeCharacterFromString(std::string& name, const char & charToRemove )
{
    std::size_t pos = name.find(charToRemove);
    if (pos != std::string::npos) 
    {
        name.erase(pos, 1);
    }
}

void encodeDigit(std::string& soundex, char& currentCode, char& prevCode )
{
    soundex += currentCode;
    prevCode = currentCode;  
}

void encodeTwoSameDigitsSeperatedByVowel(const std::string& name, std::size_t& startIndex, std::string& soundex, char& prevCode)
{
    for(std::size_t j =0; j < 3; j++)
    {
        char currentCode = getSoundexCode(name[startIndex + j]);
        if(currentCode != '0')
        {
            encodeDigit(soundex, currentCode, prevCode);
        }
    }
    startIndex +=3;
}

void encodeDigitWithVowelAndOtherConsonant(std::string& name, std::size_t& index, std::string& soundex, char& prevCode)
{
    if(isVowelPresent(name[index + 1]))
    {
        encodeTwoSameDigitsSeperatedByVowel(name, index, soundex, prevCode);
    }
    else if(isOtherConsonantPresent(name[index + 1]))
    {
        removeCharacterFromString(name,index+1);
    }
}

std::string generateSoundex(std::string name) {
    if (name.empty()) 
    {
        return "";
    }

    if (isFirstTwoLettersSame(name))
    {
        removeCharacterFromString(name, name[1]);
    }
    
    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);
    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) 
    {
        if(isTwoConsecutiveLettersSame(name, i))
        {
           removeCharacterFromString(name, i);
           continue; 
        }
        
        char currentCode = getSoundexCode(name[i]);
        if (isTwoLettersWithSameDigit(name, i))
        {
            encodeDigitWithVowelAndOtherConsonant(name, i, soundex, prevCode);
        }
        else if(currentCode == '0')
        {
            continue;
        }
        else
        {
            encodeDigit(soundex, currentCode, prevCode);
        }
    }
    soundex.resize(4, '0');
    
    return soundex;
}
