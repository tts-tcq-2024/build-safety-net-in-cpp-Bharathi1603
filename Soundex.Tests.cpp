#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, HandleLowerCaseAsFirstLetter) {
    EXPECT_EQ(generateSoundex("f000"), "F000");
}

TEST(SoundexTest, HandleNumberAsFirstLetter) {
    EXPECT_EQ(generateSoundex("6u"), "6000");
}

TEST(SoundexTest, HandleFirstTwoLetters) {
    EXPECT_EQ(generateSoundex("Pfister"), "P236");
}

TEST(SoundexTest, RobertRetursR163) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
}

TEST(SoundexTest, RupertRetursR163) {
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
}

TEST(SoundexTest, HandleTwolLetterBetweenVowel) {
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");
}

TEST(SoundexTest, HandleDuplicateEncodingBetweenOtherConsonant) {
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
}

TEST(SoundexTest, HandleStringWithVowels) {
    EXPECT_EQ(generateSoundex("Aeiou"), "A000");
}

TEST(SoundexTest, HandleStringWithOtherConsonants) {
    EXPECT_EQ(generateSoundex("Chwy"), "C000");
}

TEST(SoundexTest, HandleStringWithVowelAndOtherConsonant) {
    EXPECT_EQ(generateSoundex("Highway"), "H200");
}

TEST(SoundexTest, HandleMoreThanThreeDigits) {
    EXPECT_EQ(generateSoundex("bharathiravi"), "B636");
}

