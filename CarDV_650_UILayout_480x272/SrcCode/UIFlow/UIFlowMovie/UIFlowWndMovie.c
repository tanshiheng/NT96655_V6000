//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIFlowWndMovieRes.c"
#include "UIFlowWndMovie.h"
#include "PrjCfg.h"

//---------------------UIFlowWndMovieCtrl Debug Definition -----------------------------
#define _UIFLOWWNDMOVIE_ERROR_MSG        1
#define _UIFLOWWNDMOVIE_TRACE_MSG        0

#if (_UIFLOWWNDMOVIE_ERROR_MSG&(PRJ_DBG_LVL>=PRJ_DBG_LVL_ERR))
#define UIFlowWndMovieErrMsg(...)            debug_msg ("^R UIFlowWndMovie: "__VA_ARGS__)
#else
#define UIFlowWndMovieErrMsg(...)
#endif

#if (_UIFLOWWNDMOVIE_TRACE_MSG&(PRJ_DBG_LVL>=PRJ_DBG_LVL_TRC))
#define UIFlowWndMovieTraceMsg(...)          debug_msg ("^B UIFlowWndMovie: "__VA_ARGS__)
#else
#define UIFlowWndMovieTraceMsg(...)
#endif

//---------------------UIFlowWndMovieCtrl Global Variables -----------------------------

//---------------------UIFlowWndMovieCtrl Prototype Declaration  -----------------------

//---------------------UIFlowWndMovieCtrl Public API  ----------------------------------

//---------------------UIFlowWndMovieCtrl Private API  ---------------------------------
//---------------------UIFlowWndMovieCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndMovie)
CTRL_LIST_ITEM(UIFlowWndMovie_Static_camera)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_CyclicRec)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_MotionDet)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_battery)
CTRL_LIST_ITEM(UIFlowWndMovie_YMD_Static)
CTRL_LIST_ITEM(UIFlowWndMovie_HMS_Static)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_Storage)
CTRL_LIST_ITEM(UIFlowWndMovie_Static_time)
CTRL_LIST_ITEM(UIFlowWndMovie_Static_maxtime)
CTRL_LIST_ITEM(UIFlowWndMovie_Static_resolution)
CTRL_LIST_ITEM(UIFlowWndMovie_Zoom_Static)
CTRL_LIST_ITEM(UIFlowWndMovie_StatusICN_EV)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_HDR)
CTRL_LIST_ITEM(UIFlowWndMovie_StaticIcon_PIMC)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_GPS)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_LED)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_GSENSOR)
CTRL_LIST_ITEM(UIFlowWndMovie_Static_Lock)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_Audio)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_REC)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_TimeLapes)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_ParkingMonitor)
CTRL_LIST_ITEM(UIFlowWndMovie_CarNo_Static)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_ZHCarNo)
CTRL_LIST_ITEM(UIFlowWndMovie_Static_Guide)
CTRL_LIST_END

//----------------------UIFlowWndMovieCtrl Event---------------------------
INT32 UIFlowWndMovie_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnClose(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIFlowWndMovie)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIFlowWndMovie_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIFlowWndMovie_OnClose)
EVENT_END

INT32 UIFlowWndMovie_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
//----------------------UIFlowWndMovie_Static_cameraCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Static_camera)
EVENT_END

//----------------------UIFlowWndMovie_Status_CyclicRecCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_CyclicRec)
EVENT_END

//----------------------UIFlowWndMovie_Status_MotionDetCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_MotionDet)
EVENT_END

//----------------------UIFlowWndMovie_Status_batteryCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_battery)
EVENT_END

//----------------------UIFlowWndMovie_YMD_StaticCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_YMD_Static)
EVENT_END

//----------------------UIFlowWndMovie_HMS_StaticCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_HMS_Static)
EVENT_END

//----------------------UIFlowWndMovie_Status_StorageCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_Storage)
EVENT_END

//----------------------UIFlowWndMovie_Static_timeCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Static_time)
EVENT_END

//----------------------UIFlowWndMovie_Static_maxtimeCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Static_maxtime)
EVENT_END

//----------------------UIFlowWndMovie_Static_resolutionCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Static_resolution)
EVENT_END

//----------------------UIFlowWndMovie_Zoom_StaticCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Zoom_Static)
EVENT_END

//----------------------UIFlowWndMovie_StatusICN_EVCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_StatusICN_EV)
EVENT_END

//----------------------UIFlowWndMovie_Status_HDRCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_HDR)
EVENT_END

//----------------------UIFlowWndMovie_StaticIcon_PIMCCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_StaticIcon_PIMC)
EVENT_END

//----------------------UIFlowWndMovie_Status_GPSCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_GPS)
EVENT_END

//----------------------UIFlowWndMovie_Status_LEDCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_LED)
EVENT_END

//----------------------UIFlowWndMovie_Status_GSENSORCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_GSENSOR)
EVENT_END

//----------------------UIFlowWndMovie_Static_LockCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Static_Lock)
EVENT_END

//----------------------UIFlowWndMovie_Status_AudioCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_Audio)
EVENT_END

//----------------------UIFlowWndMovie_Status_RECCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_REC)
EVENT_END

//----------------------UIFlowWndMovie_Status_TimeLapesCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_TimeLapes)
EVENT_END

//----------------------UIFlowWndMovie_Status_ParkingMonitorCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_ParkingMonitor)
EVENT_END

//----------------------UIFlowWndMovie_CarNo_StaticCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_CarNo_Static)
EVENT_END

//----------------------UIFlowWndMovie_Status_ZHCarNoCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_ZHCarNo)
EVENT_END

//----------------------UIFlowWndMovie_Static_GuideCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Static_Guide)
EVENT_END

