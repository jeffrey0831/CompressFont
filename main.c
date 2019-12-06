#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "GUI.h"

#define MAX_FONT_WIDTH  24
GUI_CONST_STORAGE GUI_FONT *pFont = &GUI_FontHZ24x24;

static void DispLine(const char GUI_UNI_PTR *s, int MaxNumChars)
{
    if (pFont->pafEncode)
    {
        pFont->pafEncode->pfDispLine(s, MaxNumChars);
    }
}

int checkFontFile(void)
{
    const char *content = "我";
    pFont = &GUI_FontFlash24x24;

    DispLine(content, strlen(content));

    return 0;
}

uint8_t outputFile(FILE *fp, const void *data, const size_t dataLen)
{
    uint8_t ret = 1;
    size_t writeLen = 0;

    writeLen = fwrite(data, dataLen, 1, fp);
    if (1 != writeLen)
    {
        ret = 0;
        printf("outputFile err, %d\n", writeLen);
    }
    return ret;
}

int main(int argc, char *args[])
{
    uint32_t propCount = 0;
    FILE *fp = NULL;
    GUI_CONST_STORAGE GUI_FONT_PROP * pProp = pFont->p.pProp;

    checkFontFile();
    return 0;

    // 打开文件
    fp = fopen("./Bin/font.dat", "wb+");
    if (NULL == fp)
    {
        printf("open file err");
        return 0;
    }

    while (0 != pProp)
    {
        U16P c = pProp->First;

        propCount++;
        while (c <= pProp->Last)
        {
            const GUI_CHARINFO GUI_UNI_PTR * pCharInfo = pProp->paCharInfo + (c - pProp->First);
            outputFile(fp, pCharInfo->pData, (MAX_FONT_WIDTH + 8 - 1) / 8 * pFont->YSize);
            c++;
        }
        pProp = pProp->pNext;
        // pProp = NULL;
    }

    // 关闭文件
    fclose(fp);
    fp = NULL;

    checkFontFile();
    return 0;
}
