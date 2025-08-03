cmake_minimum_required(VERSION 3.10)
project(StudentRegistration)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Encontrar ncurses
find_package(PkgConfig REQUIRED)
pkg_check_modules(NCURSES REQUIRED ncurses)

# Agregar el subdirectorio de imtui
add_subdirectory(imtui)


# RECOPILAR AUTOMÁTICAMENTE todos los archivos .cpp en src y subdirectorios
file(GLOB_RECURSE SOURCES "src/**/*.cpp" "src/*.cpp")

# También puedes incluir headers si quieres (opcional para organización)
file(GLOB_RECURSE HEADERS "src/**/*.h" "src/*.h")

# Mostrar archivos encontrados (opcional, para debug)
message(STATUS "Archivos fuente encontrados:")
foreach(source ${SOURCES})
    message(STATUS "  ${source}")
endforeach()


# Tu ejecutable
add_executable(studentRegistration ${SOURCES})

# Enlazar con imtui
target_link_libraries(studentRegistration 
    imtui-ncurses
   # imtui-common
    ${NCURSES_LIBRARIES}
)

# Incluir headers
target_include_directories(studentRegistration PRIVATE 
    imtui/include
    src
    ${NCURSES_INCLUDE_DIRS}
)

# Flags de compilación
target_compile_options(studentRegistration PRIVATE ${NCURSES_CFLAGS_OTHER})