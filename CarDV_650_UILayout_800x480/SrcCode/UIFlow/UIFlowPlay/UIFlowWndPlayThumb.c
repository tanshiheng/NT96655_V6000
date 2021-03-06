//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIFlowWndPlayThumbRes.c"
#include "UIFlowWndPlayThumb.h"
#include "PrjCfg.h"

//---------------------UIFlowWndPlayThumbCtrl Debug Definition -----------------------------
#define _UIFLOWWNDPLAYTHUMB_ERROR_MSG        1
#define _UIFLOWWNDPLAYTHUMB_TRACE_MSG        0

#if (_UIFLOWWNDPLAYTHUMB_ERROR_MSG&(PRJ_DBG_LVL>=PRJ_DBG_LVL_ERR))
#define UIFlowWndPlayThumbErrMsg(...)            debug_msg ("^R UIFlowWndPlayThumb: "__VA_ARGS__)
#else
#define UIFlowWndPlayThumbErrMsg(...)
#endif

#if (_UIFLOWWNDPLAYTHUMB_TRACE_MSG&(PRJ_DBG_LVL>=PRJ_DBG_LVL_TRC))
#define UIFlowWndPlayThumbTraceMsg(...)          debug_msg ("^B UIFlowWndPlayThumb: "__VA_ARGS__)
#else
#define UIFlowWndPlayThumbTraceMsg(...)
#endif

//---------------------UIFlowWndPlayThumbCtrl Global Variables -----------------------------

//---------------------UIFlowWndPlayThumbCtrl Prototype Declaration  -----------------------

//---------------------UIFlowWndPlayThumbCtrl Public API  ----------------------------------

//---------------------UIFlowWndPlayThumbCtrl Private API  ---------------------------------
//---------------------UIFlowWndPlayThumbCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndPlayThumb)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_Panel0)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_Panel1)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_Panel2)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_Panel3)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_Panel4)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_Panel5)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_Panel6)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_Panel7)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_Panel8)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_Protect0)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_Protect1)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_Protect2)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_Protect3)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_Protect4)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_Protect5)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_Protect6)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_Protect7)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_Protect8)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_FileFilm0)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_FileFilm1)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_FileFilm2)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_FileFilm3)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_FileFilm4)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_FileFilm5)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_FileFilm6)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_FileFilm7)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_StaticICN_FileFilm8)
CTRL_LIST_ITEM(UIFlowWndPlayThumb_ThumbID)
CTRL_LIST_END

//----------------------UIFlowWndPlayThumbCtrl Event---------------------------
INT32 UIFlowWndPlayThumb_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndPlayThumb_OnClose(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIFlowWndPlayThumb)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIFlowWndPlayThumb_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIFlowWndPlayThumb_OnClose)
EVENT_END

INT32 UIFlowWndPlayThumb_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndPlayThumb_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
//---------------------UIFlowWndPlayThumb_Panel0Ctrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndPlayThumb_Panel0)
CTRL_LIST_END

//----------------------UIFlowWndPlayThumb_Panel0Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_Panel0)
EVENT_END

//---------------------UIFlowWndPlayThumb_Panel1Ctrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndPlayThumb_Panel1)
CTRL_LIST_END

//----------------------UIFlowWndPlayThumb_Panel1Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_Panel1)
EVENT_END

//---------------------UIFlowWndPlayThumb_Panel2Ctrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndPlayThumb_Panel2)
CTRL_LIST_END

//----------------------UIFlowWndPlayThumb_Panel2Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_Panel2)
EVENT_END

//---------------------UIFlowWndPlayThumb_Panel3Ctrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndPlayThumb_Panel3)
CTRL_LIST_END

//----------------------UIFlowWndPlayThumb_Panel3Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_Panel3)
EVENT_END

//---------------------UIFlowWndPlayThumb_Panel4Ctrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndPlayThumb_Panel4)
CTRL_LIST_END

//----------------------UIFlowWndPlayThumb_Panel4Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_Panel4)
EVENT_END

//---------------------UIFlowWndPlayThumb_Panel5Ctrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndPlayThumb_Panel5)
CTRL_LIST_END

//----------------------UIFlowWndPlayThumb_Panel5Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_Panel5)
EVENT_END

//---------------------UIFlowWndPlayThumb_Panel6Ctrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndPlayThumb_Panel6)
CTRL_LIST_END

//----------------------UIFlowWndPlayThumb_Panel6Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_Panel6)
EVENT_END

//---------------------UIFlowWndPlayThumb_Panel7Ctrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndPlayThumb_Panel7)
CTRL_LIST_END

//----------------------UIFlowWndPlayThumb_Panel7Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_Panel7)
EVENT_END

//---------------------UIFlowWndPlayThumb_Panel8Ctrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndPlayThumb_Panel8)
CTRL_LIST_END

//----------------------UIFlowWndPlayThumb_Panel8Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_Panel8)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_Protect0Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_Protect0)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_Protect1Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_Protect1)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_Protect2Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_Protect2)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_Protect3Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_Protect3)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_Protect4Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_Protect4)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_Protect5Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_Protect5)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_Protect6Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_Protect6)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_Protect7Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_Protect7)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_Protect8Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_Protect8)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_FileFilm0Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_FileFilm0)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_FileFilm1Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_FileFilm1)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_FileFilm2Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_FileFilm2)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_FileFilm3Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_FileFilm3)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_FileFilm4Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_FileFilm4)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_FileFilm5Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_FileFilm5)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_FileFilm6Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_FileFilm6)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_FileFilm7Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_FileFilm7)
EVENT_END

//----------------------UIFlowWndPlayThumb_StaticICN_FileFilm8Ctrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_StaticICN_FileFilm8)
EVENT_END

//----------------------UIFlowWndPlayThumb_ThumbIDCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayThumb_ThumbID)
EVENT_END

