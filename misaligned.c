#include <stdio.h>
#include <assert.h>
#include <string.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

struct ColorCode
{
    int pairNumber;
    char MajorColor[15];
    char MinorColor[15];
};

ColorCode Manual[25];

void printOnConsole(int MajorColorNumber, int MinorColorNumber);

int printColorMap() {
    int i = 0, j = 0,index=0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            Manual[index].pairNumber = i*5+j;
            strcpy(Manual[index].MajorColor, majorColor[i]);
            strcpy(Manual[index].MinorColor, minorColor[j]);
            printOnConsole(i,j);
            index++;
        }
    }
    return i * j;
}
void printOnConsole(int MajorColorNumber, int MinorColorNumber)
{
    printf("%d | %s | %s\n", MajorColorNumber * 5 + MinorColorNumber, majorColor[MajorColorNumber], minorColor[MajorColorNumber]);
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    assert(Manual[2].pairNumber == 2);
    assert(strcmp(Manual[2].MajorColor,"White") == 0);
    assert(strcmp(Manual[2].MinorColor,"Orange") == 0);
    printf("All is well (maybe!)\n");
    return 0;
}
