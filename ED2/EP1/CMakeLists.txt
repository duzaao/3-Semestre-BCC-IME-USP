cmake_minimum_required(VERSION 3.16)

project(EP2)

# Configuração do compilador
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Adiciona o executável e os arquivos fonte
add_executable(ep1 Ep1-ABB.cpp ABB.cpp texto.txt)

# Configuração dos testes
enable_testing()

# Adiciona um teste que executa o programa com um arquivo de entrada
add_test(NAME ep1_test COMMAND ep1 texto.txt)

# Define o diretório de saída para os testes
set_tests_properties(ep1_test PROPERTIES WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
