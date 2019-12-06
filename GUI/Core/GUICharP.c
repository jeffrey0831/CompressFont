/*
*********************************************************************************************************
*                                             uC/GUI V3.98
*                        Universal graphic software for embedded applications
*
*                       (c) Copyright 2002, Micrium Inc., Weston, FL
*                       (c) Copyright 2002, SEGGER Microcontroller Systeme GmbH
*
*              µC/GUI is protected by international copyright laws. Knowledge of the
*              source code may not be used to write a similar product. This file may
*              only be used in accordance with a license and should not be redistributed
*              in any way. We appreciate your understanding and fairness.
*
----------------------------------------------------------------------
File        : GUICharP.C
Purpose     : Implementation of Proportional fonts
---------------------------END-OF-HEADER------------------------------
*/
#include <stdio.h>
#include <stddef.h>           /* needed for definition of NULL */
#include "GUI.h"
// #include "GUI_Private.h"

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       GUIPROP_FindChar
*/
static const GUI_FONT_PROP GUI_UNI_PTR * GUIPROP_FindChar(const GUI_FONT_PROP GUI_UNI_PTR* pProp, U16P c) {
    for (; pProp; pProp = pProp->pNext)
    {
        if ((c >= pProp->First) && (c <= pProp->Last))
            break;
    }
    return pProp;
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       GUIPROP_DispChar
*
* Purpose:
*   This is the routine that displays a character. It is used by all
*   other routines which display characters as a subroutine.
*/
void GUIPROP_DispChar(U16P c) {
    const GUI_FONT_PROP GUI_UNI_PTR *pProp = GUIPROP_FindChar(pFont->p.pProp, c);

    if (pProp)
    {
        const GUI_CHARINFO GUI_UNI_PTR *pCharInfo = pProp->paCharInfo + (c - pProp->First);
        for (U16 i = 0; i < pFont->YSize; i++)
        {
            for (U16 j = 0; j < pCharInfo->BytesPerLine; j++)
            {
                U8 val = pCharInfo->pData[i * pCharInfo->BytesPerLine + j];
                for (U16 k = 0; k < 8/* pCharInfo->XSize - 8 * j */; k++)
                {
                    if (0x0 != (val & 0x80))
                    {
                        printf("X");
                    }
                    else
                    {
                        printf("_");
                    }
                    val = val << 1;
                }
            }
            printf("\n");
        }
    }
    printf("\n");
}

/*********************************************************************
*
*       GUIPROP_GetCharDistX
*/
int GUIPROP_GetCharDistX(U16P c) {
//   const GUI_FONT_PROP GUI_UNI_PTR * pProp = GUIPROP_FindChar(GUI_Context.pAFont->p.pProp, c);
//   return (pProp) ? (pProp->paCharInfo+(c-pProp->First))->XSize * GUI_Context.pAFont->XMag : 0;
}

/*********************************************************************
*
*       GUIPROP_GetFontInfo
*/
void GUIPROP_GetFontInfo(const GUI_FONT GUI_UNI_PTR * pFont, GUI_FONTINFO* pfi) {
  GUI_USE_PARA(pFont);
  pfi->Flags = GUI_FONTINFO_FLAG_PROP;
}

/*********************************************************************
*
*       GUIPROP_IsInFont
*/
char GUIPROP_IsInFont(const GUI_FONT GUI_UNI_PTR * pFont, U16 c) {
  const GUI_FONT_PROP GUI_UNI_PTR * pProp = GUIPROP_FindChar(pFont->p.pProp, c);
  return (pProp==NULL) ? 0 : 1;
}

/*************************** End of file ****************************/

