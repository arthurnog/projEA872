# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

# Nome do meu projeto
project(MeuJogo)

#
add_executable(MeuJogo src/main.cpp)

# Especificar onde estao os header files
include_directories(include)

# Bibliotecas locais (estaticas)
add_library(func src/func.cpp)
add_library(Model src/Model.cpp)
add_library(View src/View.cpp)
add_library(Controller src/Controller.cpp)

target_link_libraries(MeuJogo func)
target_link_libraries(MeuJogo Model)
target_link_libraries(MeuJogo View)
target_link_libraries(MeuJogo Controller)


# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Bibliotecas linkadas externamente
target_link_libraries(MeuJogo SDL2)
target_link_libraries(MeuJogo SDL2_image)
