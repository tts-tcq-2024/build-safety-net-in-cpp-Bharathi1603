#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, RobertRetursR163) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
}

TEST(SoundexTest, RupertRetursR163) {
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
}

