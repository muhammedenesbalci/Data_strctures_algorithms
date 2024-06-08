cd ..
# Build dizinini oluştur ve içine geç
mkdir -p ./build
cd ./build

# CMake ile derleme sistemini oluştur
cmake ..

# Projeyi derle
make