#include "compress.h"
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

namespace FileEncryption {
    const char* VERSION = "1.0.0";
    const char ENCRYPTION_KEY = 'K';  // Simple encryption key

    void showHelp() {
        std::cout << "Usage: ./encrypt [option] <file>\n"
                  << "Options:\n"
                  << "  -h, --help              Show this help message\n"
                  << "  -v, --version           Show program version\n"
                  << "  -e, --encrypt <file>    Encrypt specified file\n"
                  << "  -d, --decrypt <file>    Decrypt specified file\n";
    }

    void showVersion() {
        std::cout << "Version: " << VERSION << std::endl;
    }

    // Process file for both encryption and decryption using XOR cipher
    bool processFile(const char* inputPath, const char* outputPath) {
        int fdInput = open(inputPath, O_RDONLY);
        if (fdInput == -1) {
            std::cerr << "Error opening input file\n";
            return false;
        }

        int fdOutput = open(outputPath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fdOutput == -1) {
            std::cerr << "Error creating output file\n";
            close(fdInput);
            return false;
        }

        char buffer[1024];
        ssize_t bytesRead;

        // Read, process and write file content in chunks
        while ((bytesRead = read(fdInput, buffer, sizeof(buffer))) > 0) {
            // Apply XOR to each byte
            for (ssize_t i = 0; i < bytesRead; i++) {
                buffer[i] = buffer[i] ^ ENCRYPTION_KEY;
            }

            if (write(fdOutput, buffer, bytesRead) != bytesRead) {
                std::cerr << "Error writing to output file\n";
                close(fdInput);
                close(fdOutput);
                return false;
            }
        }

        close(fdInput);
        close(fdOutput);
        return true;
    }
}

// Main function implementation
int main(int argc, char* argv[]) {
    using namespace FileEncryption;

    if (argc < 2) {
        showHelp();
        return 1;
    }

    std::string option = argv[1];

    if (option == "-h" || option == "--help") {
        showHelp();
        return 0;
    }

    if (option == "-v" || option == "--version") {
        showVersion();
        return 0;
    }

    if (argc != 3) {
        std::cerr << "Error: File argument required\n";
        return 1;
    }

    std::string inputFile = argv[2];
    std::string outputFile;

    if (option == "-e" || option == "--encrypt") {
        outputFile = inputFile + ".encrypted";
        if (processFile(inputFile.c_str(), outputFile.c_str())) {
            std::cout << "File encrypted successfully: " << outputFile << std::endl;
        }
    }
    else if (option == "-d" || option == "--decrypt") {
        outputFile = inputFile + ".decrypted";
        if (processFile(inputFile.c_str(), outputFile.c_str())) {
            std::cout << "File decrypted successfully: " << outputFile << std::endl;
        }
    }
    else {
        std::cerr << "Invalid option\n";
        showHelp();
        return 1;
    }

    return 0;
}