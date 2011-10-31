#include "my_utils.h"

#include <string>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "stdint.h"

using namespace std;

int getFilesize(string filename) {
    struct stat filestatus;
    stat(filename.c_str(), &filestatus);
    return filestatus.st_size;
}

short convertTwoBytesToShort(char a, char b) {
    //little endian. a is the least significant byte.
    short res = b & 255;
    res = res << 8;
    res = res | (a&255);
    return res;
}

void printint(int n) {
    for (int i = 31; i >= 0; --i) {
	if ((n>>i) & 1) {
	    printf("%d",1);
	} else {
	    printf("%d",0);
	}
    }
    printf("\n");
}

void printchar(char n) {
    for (int i = 7; i >= 0; --i) {
	if ((n>>i) & 1) {
	    printf("%d",1);
	} else {
	    printf("%d",0);
	}
    }
    printf("\n");    
}

uint32_t convertFourBytesToInt(unsigned char a, unsigned char b, unsigned char c, unsigned char d) {
    uint32_t res = 0;
    int di = (0 | d) & 255;
    int ci = (0 | c) & 255;
    int bi = (0 | b) & 255;
    int ai = (0 | a) & 255;

    res = res | di;
    res = res << 8;
    res = res | ci;
    res = res << 8;
    res = res | bi;
    res = res << 8;
    res = res | ai;
    
    return res;
}

void convertCharArrayToShort(char* arr, short* arr2, int arraySize) {
    for (int i = 0; i < arraySize; i += 4) {
	arr2[i/2] = convertTwoBytesToShort(arr[i],arr[i+1]);
	arr2[i/2+1] = convertTwoBytesToShort(arr[i+2],arr[i+3]);
    }
}
