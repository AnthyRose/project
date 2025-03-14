// for simplicity this will all the one big file.
#include <stdio.h>
#include <windows.h>

int CountFiles(const char* path) {
    int count = 0;
    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA(path, &findData);
    if (hFind == INVALID_HANDLE_VALUE) {
        return 0;
    }
    do {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            continue;
        }
        count++;
    } while (FindNextFileA(hFind, &findData));
    FindClose(hFind);
    return count;
}

void openImages(int* totalImages, const char* path) {
    for (int i = 0; i < *totalImages; i++) {
        char buffer[256];
        
    }

}

int main() {
    // Make our variables.
    const char* images = "./images/*"; // Remember to use the *.
    int countingFiles = CountFiles(images);
    printf("%d", countingFiles);
    openImages(&countingFiles, images);
}