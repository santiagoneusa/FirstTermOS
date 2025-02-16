# File Encryption Tool

Una herramienta simple de línea de comandos para encriptar y desencriptar archivos usando cifrado XOR.

## Características

- Encriptación y desencriptación de archivos usando cifrado XOR
- Interfaz de línea de comandos simple
- Procesamiento eficiente de archivos de cualquier tamaño
- Implementación usando funciones POSIX para E/S de archivos

## Requisitos

- Compilador de C++ (g++ recomendado)
- Sistema operativo compatible con POSIX (Linux/Unix)
- Make (opcional, para compilación automatizada)

## Instalación

1. Clona el repositorio:
    ```
    git clone https://github.com/santiagoneusa/FirstTermOS.git
    ```
2. Entra a la nueva capeta que se creó:
    ```
    cd FirstTermOS
    ```

## Compilación
### Compilación Manual
1. Crea una carpeta `bin` donde va a quedar el ejecutable del programa:
    ```
    mkdir bin
    ```
2. Ejecuta el siguiente comando para compilar todo el código:
    ```
    g++ -I./include -o bin/encrypt src/main.cpp src/arg_parser.cpp src/encryption.cpp
    ```
3. Hacer que el programa sea una función del sistema operativo (dos alternativas):
    
    3.1. Modificar la variable de ambiente `PATH`:
    ```
    export PATH=$FIRST_TERM_OS/bin:$PATH
    ```
    Donde `$FIRST_TERM_OS` hace referencia a la ruta del directorio creado al hacer `git clone`.

    3.2. Crear un enlace simbolico (requiere permisos de superusuario):
    ```
    sudo ln -s $(pwd)/bin/encrypt /usr/local/bin/encrypt
    ```
4. Ejecuta el código:
    ```
    encrypt -h
    ```

### Compilación Automatizada
1. Ejecuta el siguiente comando que se va a encargar de compilar todo el programa:
    ```
    make
    ```
2. Hacer que el programa sea una función del sistema operativo (con permisos de superusuario):
    ```
    make install
    ```
    Si no cuentas con permisos de superusuario ve a la sección 3.2 de [Compilación Manual](#compilación-manual) y sigue ese paso.
3. Ejecuta el código:
    ```
    encrypt -h
    ```

## Uso

La herramienta soporta los siguientes comandos:

```
# Mostrar ayuda
encrypt -h, --help

# Mostrar versión
encrypt -v, --version

# Encriptar un archivo
encrypt -e, --encrypt <archivo_original> [archivo_salida]
# Resultado: archivo_salida o archivo_original.encrypted

# Desencriptar un archivo
encrypt -d, decrypt <archivo_encriptado> [archivo_salida]
# Resultado: archivo_salida o archivo_encriptad.decrypted
```

## Estructura del Proyecto

```
include/
├── arg_parser.h          
├── encryption.h
README.md
src/
├── arg_parser.cpp          
├── encryption.cpp        
├── main.cpp       
```

## Cómo Funciona

La herramienta utiliza un cifrado XOR simple donde:
1. Cada byte del archivo se procesa con una clave de encriptación
2. Los archivos se procesan en bloques de 1024 bytes para eficiencia
3. La misma operación se usa tanto para encriptar como para desencriptar

## Advertencia de Seguridad

Esta herramienta es para propósitos educativos y de demostración. No se recomienda para uso en producción o para datos sensibles porque:
- Usa un cifrado XOR simple
- La clave de encriptación es fija y está en el código
- No implementa verificación de integridad

## Autores

- Juan Manuel Gómez Piedrahita
- Luisa María Álvarez García
- Miguel Ángel Hoyos
- Santiago Neusa Ruiz
- Sebastián Restrepo Ortiz