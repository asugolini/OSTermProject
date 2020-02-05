#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void displayBufferPage(uint8_t *buf, uint32_t count, uint32_t start, uint64_t offset) {
    for(int i = 0; i < 16; i++) {
        cout << setfill('0') << setw(2) << right << hex << hex(j) << "|";
        for(int j = (i*16); j < ((i*16) + 16); j++) {
            if(start) //finish
        }
    }
}

void displayBuffer(uint8_t *buf, uint32_t count, uint64_t offset) {

}

int main() {
    ifstream is ("Test-fixed-4k.vdi", std::ifstream::binary);

    is.seekg(0, is.end);
    int length = is.tellg();
    is.seekg(0, is.beg);

    char * buffer = new char[length];

    is.read(buffer, length);

    displayBuffer((uint8_t*) buffer, 400,0);
}

