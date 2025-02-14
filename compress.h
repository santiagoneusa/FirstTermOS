#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

namespace FileEncryption {
    // Constants
    extern const char* VERSION;
    extern const char ENCRYPTION_KEY;

    // Main functionality
    bool processFile(const char* inputPath, const char* outputPath);

    // Helper functions
    void showHelp();
    void showVersion();
}

#endif // ENCRYPTION_H