#ifndef ARG_PARSER_H
#define ARG_PARSER_H

#include <string>
#include <iostream>

extern const char* VERSION;

enum class Mode {
    ENCRYPT,
    DECRYPT
};

struct Arguments {
    std::string inputFile;
    std::string outputFile;
    Mode mode;
    bool valid = false;
};

Arguments parseArguments(int argc, char* argv[]);
void showHelp();
void showVersion();

#endif