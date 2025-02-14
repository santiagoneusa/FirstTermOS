#include "../include/encryption.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

const char ENCRYPTION_KEY = 'K';

bool processFile(const char* inputPath, const char* outputPath) {
    int fdInput = open(inputPath, O_RDONLY);
    if (fdInput == -1) {
        std::cerr << "Error opening input file: " << inputPath << std::endl;
        return false;
    }

    int fdOutput = open(outputPath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fdOutput == -1) {
        std::cerr << "Error creating output file: " << outputPath << std::endl;
        close(fdInput);
        return false;
    }

    char buffer[1024];
    ssize_t bytesRead;

    // Read, process, and write file content in chunks
    while ((bytesRead = read(fdInput, buffer, sizeof(buffer))) > 0) {  // Aquí estaba el error
        // Apply XOR to each byte
        for (ssize_t i = 0; i < bytesRead; i++) {
            buffer[i] = buffer[i] ^ ENCRYPTION_KEY;
        }

        if (write(fdOutput, buffer, bytesRead) != bytesRead) {
            std::cerr << "Error writing to output file: " << outputPath << std::endl;
            close(fdInput);
            close(fdOutput);
            return false;
        }
    }

    close(fdInput);
    close(fdOutput);
    return true;
}