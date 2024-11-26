#include "pch.h"
#include "CppUnitTest.h"
#include "../Laboratorna-12.1/Laboratorna-12.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest122
{
	TEST_CLASS(UnitTest122)
       {
	public:
		
		TEST_METHOD(TestProcessBIN)
		{
            const char* inputFileName = "test_input.bin";
            const char* outputFileName = "test_output.bin";

            std::ofstream inputFile(inputFileName, std::ios::binary);
            inputFile << "a1b2c3d4e5";
            inputFile.close();

            ProcessBIN(const_cast<char*>(inputFileName), const_cast<char*>(outputFileName));

            std::ifstream outputFile(outputFileName, std::ios::binary);
            std::string outputContent;
            char c;
            while (outputFile.read((char*)&c, sizeof(c)))
            {
                outputContent += c;
            }
            outputFile.close();

            Assert::AreEqual(std::string("abcde"), outputContent);
		}
	};
}
