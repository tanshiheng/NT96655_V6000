//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "NVTToolCommand.h"
#include "UIMenuWndCalibrationRes.c"
//#include "UIFlow.h"
//#include "CalibrationTsk.h"
#include "CalibrationInt.h"
#include "../../../DRIVER/UIFlow.h"


//---------------------UIMenuWndCalibrationCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndCalibration)
CTRL_LIST_ITEM(UIMenuWndCalibration_Background)
CTRL_LIST_ITEM(UIMenuWndCalibration_TitleBar)
CTRL_LIST_ITEM(UIMenuWndCalibration_TipsBar)
CTRL_LIST_ITEM(UIMenuWndCalibration_Item)
CTRL_LIST_END

//----------------------UIMenuWndCalibrationCtrl Event---------------------------
INT32 UIMenuWndCalibration_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndCalibration_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndCalibration_OnChildClose(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndCalibration)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndCalibration_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndCalibration_OnClose)
EVENT_ITEM(NVTEVT_CHILD_CLOSE,UIMenuWndCalibration_OnChildClose)
EVENT_END

#define TM_ITEMS_PERPAGE    4

typedef struct _CAL_UIDATA
{
    INT32   SelItem;    // selected item number in total items
    INT32   FirstItem;  // first item number in current menu page
    INT32   Count;      // total item number
} CAL_UIDATA;

CAL_UIDATA g_CalData = { 0 };

char g_CalibrationTitle[20] = "Calibration";
char g_CalibrationItem[TM_ITEMS_PERPAGE][32];

void UIMenuWndCalibration_SelectItem(INT32 new_sel)
{
    INT32   old_sel, old_first;

    // original selected items
    old_sel = g_CalData.SelItem;
    old_first = g_CalData.FirstItem;

    // new item
    g_CalData.SelItem = new_sel;

    if (g_CalData.SelItem >= g_CalData.Count)
        g_CalData.SelItem = 0;
    else if (g_CalData.SelItem < 0)
        g_CalData.SelItem = g_CalData.Count - 1;

    g_CalData.FirstItem = (g_CalData.SelItem / TM_ITEMS_PERPAGE) * TM_ITEMS_PERPAGE;

    if (g_CalData.FirstItem != old_first)
    {
        UINT32  i, count = g_CalData.Count - g_CalData.FirstItem;

        if (count > TM_ITEMS_PERPAGE)
            count = TM_ITEMS_PERPAGE;

        UxMenu_SetData(&UIMenuWndCalibration_ItemCtrl, MNU_TOTITM, count);
        if (new_sel > old_sel)
            UxMenu_SetData(&UIMenuWndCalibration_ItemCtrl, MNU_CURITM, 0);
        else
            UxMenu_SetData(&UIMenuWndCalibration_ItemCtrl, MNU_CURITM, count - 1);

        for (i = 0; i < count; i++)
        {
            sprintf(g_CalibrationItem[i], "%ld. %s", i + g_CalData.FirstItem + 1, g_CalItem[i + g_CalData.FirstItem].pItemName);
            UxMenu_SetItemData(&UIMenuWndCalibration_ItemCtrl, UIMenuWndCalibration_Item_STRID_A1 + i, MNUITM_STRID, Txt_Pointer(g_CalibrationItem[i]));
        }
    }
    else if (g_CalData.SelItem != old_sel)
    {
    }
}

void UIMenuWndCalibration_ShiftItem(INT32 offset)
{
    UIMenuWndCalibration_SelectItem(g_CalData.SelItem + offset);
}

INT32 UIMenuWndCalibration_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  i;
    UINT32  count = TM_ITEMS_PERPAGE;

    Input_SetKeyMask(KEY_RELEASE, FLGKEY_KEY_MASK_NULL);

    g_CalData.SelItem = 0;
    g_CalData.FirstItem = 0;
    g_CalData.Count = (INT32)Cal_GetMaxItemNum() + 1;

    UxStatic_SetData(&UIMenuWndCalibration_TitleNameCtrl, STATIC_VALUE, Txt_Pointer(g_CalibrationTitle));
    UxCtrl_SetShow(&UIMenuWndCalibration_TitleNameCtrl, TRUE);

    if (g_CalData.Count < TM_ITEMS_PERPAGE)
    {
        count = g_CalData.Count;
        UxMenu_SetData(&UIMenuWndCalibration_ItemCtrl, MNU_TOTITM, count);
    }

    for (i = 0; i < count; i++)
    {
        sprintf(g_CalibrationItem[i], "%ld. %s", i + 1, g_CalItem[i].pItemName);
        UxMenu_SetItemData(&UIMenuWndCalibration_ItemCtrl, UIMenuWndCalibration_Item_STRID_A1 + i, MNUITM_STRID, Txt_Pointer(g_CalibrationItem[i]));
    }

    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndCalibration_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndCalibration_OnChildClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CHILD_CLOSE,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
//---------------------UIMenuWndCalibration_BackgroundCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndCalibration_Background)
CTRL_LIST_END

//----------------------UIMenuWndCalibration_BackgroundCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndCalibration_Background)
EVENT_END

//---------------------UIMenuWndCalibration_TitleBarCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndCalibration_TitleBar)
CTRL_LIST_ITEM(UIMenuWndCalibration_TitleName)
CTRL_LIST_END

//----------------------UIMenuWndCalibration_TitleBarCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndCalibration_TitleBar)
EVENT_END

//----------------------UIMenuWndCalibration_TitleNameCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndCalibration_TitleName)
EVENT_END

//---------------------UIMenuWndCalibration_TipsBarCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndCalibration_TipsBar)
CTRL_LIST_ITEM(UIMenuWndCalibration_UDOKTips)
CTRL_LIST_END

//----------------------UIMenuWndCalibration_TipsBarCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndCalibration_TipsBar)
EVENT_END

//---------------------UIMenuWndCalibration_UDOKTipsCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndCalibration_UDOKTips)
CTRL_LIST_END

//----------------------UIMenuWndCalibration_UDOKTipsCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndCalibration_UDOKTips)
EVENT_END

//----------------------UIMenuWndCalibration_ItemCtrl Event---------------------------
INT32 UIMenuWndCalibration_Item_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndCalibration_Item_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndCalibration_Item_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndCalibration_Item_OnKeyShutter2(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndCalibration_Item)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndCalibration_Item_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_UP,UIMenuWndCalibration_Item_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndCalibration_Item_OnKeyEnter)
EVENT_ITEM(NVTEVT_KEY_SHUTTER2,UIMenuWndCalibration_Item_OnKeyShutter2)
EVENT_END

INT32 UIMenuWndCalibration_Item_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
    UIMenuWndCalibration_ShiftItem(+1);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndCalibration_Item_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
    UIMenuWndCalibration_ShiftItem(-1);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndCalibration_Item_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if (g_CalItem[g_CalData.SelItem].ItemFunction != NULL)
    {
        g_CalItem[g_CalData.SelItem].ItemFunction();
    }

    Ux_FlushEventByRange(NVTEVT_KEY_EVT_START,NVTEVT_KEY_EVT_END);
    UxCtrl_SetShow(&UIMenuWndCalibrationCtrl, TRUE);
    Ux_Redraw();
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndCalibration_Item_OnKeyShutter2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    // the same behavior as ENTER key!
    return UIMenuWndCalibration_Item_OnKeyEnter(pCtrl, paramNum, paramArray);
}
