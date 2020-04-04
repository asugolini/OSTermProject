#ifndef VDI_READ
#define VDI_READ
#include <cstdint>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


using namespace std;

int VDIFile *vdiOpen(char* fn);
void vdiClose(VDIFile* f);
off_t vdiSeek(VDIFile* f, off_t offset, int anchor);
size_t vdiRead(VDIFile* f, void* buf, size_t n);
size_t vdiWrite(VDIFile* f, void* buf, size_t n);

#endif