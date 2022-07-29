#include <stdio.h>
#include <assert.h>
#include "even_count_color_code.h"

const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    printf(buffer, "%s %s", MajorColorNames[colorPair->majorColor], MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors + colorPair->minorColor + 1;
}

void testNumberToPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor){
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber){
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}

void printEvenCountColorCodeManual(void){
    int pairNumber=1;
    for(int MajorColor=0;MajorColor<numberOfMajorColors;MajorColor++)
    {
        for(int MinorColor=0;MinorColor<numberOfMinorColors;MinorColor++,pairNumber++)
        {
            printf("\n%d\t\t%s\t\t%s",pairNumber,MajorColorNames[MajorColor],MinorColorNames[MinorColor]); 
        }
    }
}