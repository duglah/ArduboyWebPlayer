rm build/ -rf
mkdir build
cd build
#cmake ../cpp
#make
emcc ../cpp/helloworld.cpp ../cpp/Arduboy.cpp -s WASM=1 -s EXPORTED_FUNCTIONS="[_setup, _loop]" -s TOTAL_MEMORY=16MB --js-library ../js/library.js -o helloworld.js
mv helloworld.js ../web/gen/
mv helloworld.wasm ../web/gen/