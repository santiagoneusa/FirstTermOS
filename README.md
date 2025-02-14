# FirstTermOS

## Manual Compilation

1. Create a bin dir:
    ```
    mkdir bin
    ```

2. Compile:
    ```
    g++ -I./include -o bin/compress src/main.cpp src/arg_parser.cpp src/encryption.cpp
    ```

3. Run:
    ```
    ./bin/compress -h
    ```