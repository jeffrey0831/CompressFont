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
File        : GUIChar.C
Purpose     : Implementation of character and string services
---------------------------END-OF-HEADER------------------------------
*/

#include <stddef.h>           /* needed for definition of NULL */
#include <stdio.h>
#include "GUI.h"

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       GUI_DispNextLine
*/
void GUI_DispNextLine(void) {
}

/*********************************************************************
*
*       GL_DispChar
*/
void GL_DispChar(U16 c) {
  /* check for control characters */
  if (c == '\n') {
    GUI_DispNextLine();
  } else {
    if (c != '\r') {
      pFont->pfDispChar(c);
    }
  }
}

/*********************************************************************
*
*       GUI_GetYAdjust
*
* Returns adjustment in vertical (Y) direction
*
* Note: The return value needs to be subtracted from
*       the y-position of the character.
*/
int GUI_GetYAdjust(void) {
  int r = 0;
  return r;
}

/*********************************************************************
*
*       GUI_GetFontDistY
*/
int GUI_GetFontDistY(void) {
  int r;
  r = pFont->YDist;
  return r;
}

/*********************************************************************
*
*       GUI_GetCharDistX
*/
int GUI_GetCharDistX(U16 c) {
  int r;
  r = pFont->pfGetCharDistX(c);
  return r;
}

/*************************** End of file ****************************/

