#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <iostream>

extern const char ENCRYPTION_KEY;

bool processFile(const char* inputPath, const char* outputPath);

#endif