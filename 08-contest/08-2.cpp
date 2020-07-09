#include <iostream>

bool extractSubStr(int & zeroCnt, int & oneCnt, int & spareZero, bool & isEOF, bool & entryFlag){
    spareZero = 0;
    entryFlag = false;
    isEOF = false;
    char c;
    int i;
    bool isBelongsToLanguage = true;
    while(isspace(std::cin.peek())){
        std::cin.get();
    }
    for(i = 0; (c = std::cin.get()) != EOF && !isspace(c); i++) {
        entryFlag = true;
        if (c != '0' && c != '1') {
            isBelongsToLanguage = false;
        } else {
            if (c == '1') {
                oneCnt++;
            } else {
                if (oneCnt != 0) {
                    spareZero = 1;
                    break;
                } else {
                    zeroCnt++;
                }
            }
        }
    }
    if(c == EOF) {
        isEOF = true;
    }
    return isBelongsToLanguage;
}

int main()
{
    int isBelongsToLanguage;
    int subStrZeroCnt, subStrOneCnt;
    int curZeroCnt = 0, curOneCnt = 0, spareZero;
    bool isEOF = false, entryFlag;

    while(!isEOF){
        subStrZeroCnt = 0, subStrOneCnt = 0;
        curZeroCnt = 0, curOneCnt = 0, spareZero = 1;

        isBelongsToLanguage = extractSubStr(subStrZeroCnt, subStrOneCnt, spareZero, isEOF, entryFlag);
        if (subStrOneCnt == 0 || subStrZeroCnt == 0){
            isBelongsToLanguage = 0;
        }

        while (spareZero) {
            curZeroCnt = 0; curOneCnt = 0;
            curZeroCnt += spareZero;
            if(extractSubStr(curZeroCnt, curOneCnt, spareZero, isEOF, entryFlag)){
                if(curZeroCnt != subStrZeroCnt || curOneCnt != subStrOneCnt){
                    isBelongsToLanguage = 0;
                }
            } else {
                isBelongsToLanguage = 0;
            }
        }
        if(entryFlag) std::cout << isBelongsToLanguage << std::endl;
    }
}
