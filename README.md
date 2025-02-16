# File Encryption Tool

Una herramienta simple de línea de comandos para encriptar y desencriptar archivos usando cifrado XOR.

## Características

- Encriptación y desencriptación de archivos usando cifrado XOR
- Interfaz de línea de comandos simple
- Procesamiento eficiente de archivos de cualquier tamaño
- Implementación usando funciones POSIX para E/S de archivos

## Requisitos

- Compilador C++ (g++ recomendado)
- Sistema operativo compatible con POSIX (Linux/Unix)
- Make (opcional, para compilación automatizada)

## Instalación

1. Clona el repositorio:
```bash
git clone https://github.com/santiagoneusa/FirstTermOS.git
cd file-encryption
```

2. Compila el proyecto:
```bash
g++ -o encrypt main.cpp
```

## Uso

La herramienta soporta los siguientes comandos:

```bash
# Mostrar ayuda
./encrypt -h
./encrypt --help

# Mostrar versión
./encrypt -v
./encrypt --version

# Encriptar un archivo
./encrypt -e archivo.txt
# Resultado: archivo.txt.encrypted

# Desencriptar un archivo
./encrypt -d archivo.txt.encrypted
# Resultado: archivo.txt.encrypted.decrypted
```

## Estructura del Proyecto

```
file-encryption/
├── main.cpp           # Código fuente principal
├── compress.h         # Archivo de cabecera
├── README.md         # Este archivo
└── LICENSE           # Licencia del proyecto
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

- Juan Manuel Gomez Piedrahita
- Luisa María Álvarez García
- Miguel Ángel Hoyos
- Santiago Neusa
- Sebastián Restrepo Ortiz
