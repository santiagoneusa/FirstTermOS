#include "../include/arg_parser.h"

const char* VERSION = "1.0.0";

Arguments parseArguments(int argc, char* argv[]) {
    Arguments args;
    args.valid = false;

    if (argc < 2) {
        std::cerr << "Error: Missing arguments. Use -h for help." << std::endl;
        return args;
    }

    std::string option = argv[1];

    if (option == "-h" || option == "--help") {
        showHelp();
        return args;
    }

    if (option == "-v" || option == "--version") {
        showVersion();
        return args;
    }

    if (argc < 3) {
        std::cerr << "Error: Input file argument required." << std::endl;
        return args;
    }

    args.inputFile = argv[2];

    if (option == "-e" || option == "--encrypt") {
        args.mode = Mode::ENCRYPT;
        args.outputFile = (argc >= 4) ? argv[3] : args.inputFile + ".encrypted";
        args.valid = true;
    }
    else if (option == "-d" || option == "--decrypt") {
        args.mode = Mode::DECRYPT;
        args.outputFile = (argc >= 4) ? argv[3] : args.inputFile + ".decrypted";
        args.valid = true;
    }
    else {
        std::cerr << "Error: Invalid option." << std::endl;
    }

    return args;
}

void showHelp() {
    std::cout << "Usage: ./encrypt [option] <input_file> [output_file]\n"
              << "Options:\n"
              << "  -h, --help              Show this help message\n"
              << "  -v, --version           Show program version\n"
              << "  -e, --encrypt <input_file> [output_file]   Encrypt specified file\n"
              << "  -d, --decrypt <input_file> [output_file]   Decrypt specified file\n";
}

void showVersion() {
    std::cout << "Version: " << VERSION << std::endl;
}