#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::MatchesRegex;

TEST(SentenceAnalysisTest, ExecutesAndExits) {
  std::string user_input = "a\nquit\n";
  ASSERT_EXECEXIT("main", user_input, 3)
      << "      Your program should exit after the user type \"quit\"";
}

TEST(SentenceAnalysisTest, PromptsForCharacter) {
  std::string user_input = "a\nquit\n";
  ASSERT_DURATION_LE(3, {
      ASSERT_EXECTHAT(
          "main", user_input,
          MatchesRegex(".*[Ww]hat character do you want stats on?.*")) <<
          "    Your program should prompt the user to enter a character. "
          "Check your spelling and whitespace.";
    });
}

TEST(SentenceAnalysisTest, SingleLetter) {
  std::string user_input = "a\na\nquit\n";
  ASSERT_DURATION_LE(3, {
      ASSERT_EXECTHAT(
          "main", user_input,
          MatchesRegex(".*[Tt]he character a appears 1 time.*")) <<
          "    Your program should find the character 'a' once in the input \"a\"";
    });
}

TEST(SentenceAnalysisTest, SingleLetterMissing) {
  std::string user_input = "a\nb\nquit\n";
  ASSERT_DURATION_LE(3, {
      ASSERT_EXECTHAT(
          "main", user_input,
          MatchesRegex(".*[Tt]he character b appears 0 time.*")) <<
          "    Your program should find the character 'b' zero times in the input \"a\"";
    });
}

TEST(SentenceAnalysisTest, MultipleLetters) {
  std::string user_input = "a\nb\na\nc\nquit\n";
  ASSERT_DURATION_LE(3, {
      ASSERT_EXECTHAT(
          "main", user_input,
          MatchesRegex(".*[Tt]he character b appears 0 time.*[Tt]he character "
                       "a appears 1 time.*[Tt]he character c appears 0 time.*"))
              << "    Your program should ask the user to enter a character repeatedly until they type \"quit\"";
    });
}

TEST(SentenceAnalysisTest, InterestingSentence) {
  std::string user_input = "Once upon a time there was a tiny black kitty!\nt\n!\nz\nquit\n";
  ASSERT_DURATION_LE(3, {
      ASSERT_EXECTHAT(
          "main", user_input,
          MatchesRegex(".*[Tt]he character t appears 5 time.*[Tt]he character "
                       "! appears 1 time.*[Tt]he character z appears 0 time.*"))
              << "    Your program should find the character 't' five times, "
                 "the character '!' once, and the character 'z' zero times in "
                 "the input \"Once upon a time there was a tiny black kitty!\"";
    });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  bool skip = true;
  for (int i = 0; i < argc; i++)
  {
    if (std::string(argv[i]) == "--noskip")
    {
      skip = false;
    }
  }
  if (skip)
  {
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  }
  return RUN_ALL_TESTS();
}
