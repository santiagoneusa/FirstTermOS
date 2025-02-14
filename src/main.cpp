#include "../include/arg_parser.h"
#include "../include/encryption.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Parse arguments
    Arguments args = parseArguments(argc, argv);

    // Process the file based on the arguments
    if (args.valid) {
        if (processFile(args.inputFile.c_str(), args.outputFile.c_str())) {
            cout << "Operation completed successfully: " << args.outputFile << endl;
        } else {
            cerr << "Error processing file." << endl;
        }
    }

    return 0;
}