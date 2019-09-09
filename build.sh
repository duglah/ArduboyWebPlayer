rm build/ -rf
mkdir build
cd build
#cmake ../cpp
#make
emcc -g4 ../cpp/helloworld.cpp ../cpp/Arduboy.cpp ../cpp/Arduino.cpp ../cpp/core/core.cpp ../cpp/Print.cpp ../cpp/audio/audio.cpp -s WASM=1 -s EXPORTED_FUNCTIONS="[_setup, _loop, _main]" -s TOTAL_MEMORY=16MB -s ASYNCIFY=1 --js-library ../js/library.js -o helloworld.js --source-map-base http://localhost:8080/../build/