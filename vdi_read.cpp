#include "vdi_read.h"

using namespace std;

int vdiOpen(VDIFile* vdi, char *fn) {
    vdi->file = open(fn, O_RDWR);
    vdi->cursor = 0;
    if (vdi->file < 0) return 1;
    return vdi->file;
}

void vdiClose(struct VDIFile *f) {
    close(f->file);
}

off_t vdiSeek(VDIFile *f, off_t offset, int anchor) {
    off_t location;
    if (anchor == SEEK_SET) {
        location = lseek(f->file, offset, anchor);
        if (location < 0) {
            cout << "Seek failure" << endl;
            return 1;
        }
        f->cursor = location;
    }
    if (anchor == SEEK_CUR) {
        location = lseek(f->file, offset, anchor);
        if (location < 0) {
            cout << "Seek failure" << endl;
            return 1;
        }
        f->cursor += offset;
    }
    if (anchor == SEEK_END) {
        location = lseek(f->file, offset, anchor);
        if (location < 0) {
            cout << "Seek failure" << endl;
            return 1;
        }
        f->cursor = offset + f->fileSize;
    }
    return f-> cursor;
}


ssize_t vdiRead(VDIFile* f, void* buf, size_t count) {
    ssize_t numBytes = read(f->file, buf, count);
    if (numBytes != count) {
        cout << "Header read failure" << endl;
        return 1;
    }
    return 0;
}