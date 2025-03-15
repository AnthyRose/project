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

void openImages(int* count, const char* path) {
    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA(path, &findData);
    if (hFind == INVALID_HANDLE_VALUE) {
        return;
    }
    void *loadedGraphic = malloc(128 * 128);
    do {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            continue;
        }
        char fullPath[256];
        sprintf(fullPath, "%s%s", "./images/miku/", findData.cFileName);
        printf("%s\n", fullPath);
        FILE* loadedGraphic = fopen(fullPath, "r");
    } while (FindNextFileA(hFind, &findData));
    FindClose(hFind);
}

int main() {
    // Make our variables.
    const char* images = "./images/miku/*"; // Remember to use the *.
    int countingFiles = CountFiles(images);
    printf("%d", countingFiles);
    openImages(&countingFiles, images);
}