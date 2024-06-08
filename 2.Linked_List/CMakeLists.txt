cmake_minimum_required(VERSION 3.10)
project(linked_list)

# C++ standardını belirtin
set(CMAKE_CXX_STANDARD 11)

# include dizinini ekleyin
include_directories(./include)

# src dizinindeki tüm cpp dosyalarını kaynak dosyaları olarak belirleyin
file(GLOB SOURCES "src/*.cpp")

# my_prog adlı yürütülebilir dosyayı oluşturun
add_executable(linked_list ${SOURCES})


