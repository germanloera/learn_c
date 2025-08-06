#!/bin/bash

# Crear directorio build si no existe
mkdir -p build
cd build

# Configurar con cmake
cmake --debugger ..

# Compilar
make -j$(nproc)

# Ejecutar si la compilación fue exitosa
if [ $? -eq 0 ]; then
    echo "Compilación exitosa. Ejecutando..."
    ./studentRegistration
else
    echo "Error en la compilación"
fi