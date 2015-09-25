////////////////////////////////////////////////////////////////////////////////
#include "SysCommon.h"
#include "AppCommon.h"
#include "UICommon.h"
////////////////////////////////////////////////////////////////////////////////
#include "UIMode.h"
//#include "UIInfo.h"
#if(UI_RESOLUTION==UI_RESOLUTION_D800x480)
#include "../UIWnd/D800x480/UIInfo/UIInfo.h"
#elif(UI_RESOLUTION==UI_RESOLUTION_D480x272)
#include "../UIWnd/D480x272/UIInfo/UIInfo.h"
#elif(UI_RESOLUTION==UI_RESOLUTION_TOUCH_800x480)
#include "../UIWnd/T800x480/UIInfo/UIInfo.h"
#else
#include "../UIWnd/DRIVER/UIInfo/UIInfo.h"
#endif
#include "UIGraphics.h"
#if (_CALIBRATION_MODE_ == ENABLE)
#include "EngineerMode.h"
#endif

//global debug level: PRJ_DBG_LVL
#include "PrjCfg.h"
//local debug level: THIS_DBGLVL
#define THIS_DBGLVL         1 //0=OFF, 1=ERROR, 2=TRACE
///////////////////////////////////////////////////////////////////////////////
#define __MODULE__          uimode
#define __DBGLVL__          ((THIS_DBGLVL>=PRJ_DBG_LVL)?THIS_DBGLVL:PRJ_DBG_LVL)
#define __DBGFLT__          "*" //*=All, [mark]=CustomClass
#include "DebugModule.h"
///////////////////////////////////////////////////////////////////////////////

#define UIDebug_usb    debug_ind

//Using USB Plug-In + ZOOMOUT Key to enter to Msdc Vendor Spy Mode
#if(RTSP_LIVEVIEW_FUNC==ENABLE)
//RTSP is always using msdc vendor for niven to debug.
#define IS_USB_VENDOR() (1)
#else
#define IS_USB_VENDOR() (GxKey_GetData(GXKEY_NORMAL_KEY)==FLGKEY_ZOOMOUT) //!< set to (1) to Force always
#endif

//#NT#2010/10/28#JeahYen -begin
//Unify mode type during power-on process
UINT32 guiPwrOnMode = DSC_MODE_PHOTO_AUTO;
int guiPwrOnAskModeCnt = 0;
//#NT#2010/10/28#JeahYen -end
//#NT#2010/03/11#[0010940]Lily Kao -begin
//USB plug-in pwr-on check;quickly-unplug shall lead to pwr-down
extern BOOL gChkUSBPwrOn;
//#NT#2010/03/11#[0010940]Lily Kao -end

//#NT#2011/04/19#Photon Lin -begin
static BOOL bisEnterPowerOff = FALSE;
//#NT#2011/04/19#Photon Lin -end
//#NT#2010/07/14#Jeah Yen -begin
/////////////////////////////////////////////////////////////////////////////

//#NT#2010/09/02#Steven feng -begin
BOOL gbIsPlayBackModePowerOn = 0;

//#NT#2010/09/17#Jeah Yen -begin
//extern UISysInfo sysInfo;
extern UIMenuStoreInfo  currentInfo;
//#NT#2010/09/17#Jeah Yen -end
//#NT#2010/09/02#Steven feng -end

//#NT#2010/10/28#Jeah Yen -begin
BOOL FlowMode_IsPowerOnPlayback(void)
{
#if _MIPS_TODO
    if (GxSystem_GetPowerOnSource() == RTC_PWRON_SRC_PWR_SW2)
    {
        gbIsPlayBackModePowerOn = 1;
        return TRUE;
    }
    else
#endif
    {
        return FALSE;
    }
    return FALSE;
}
BOOL FlowMode_IsPowerOnUpdateFW(void)
{
    #if _DEMO_TODO
    if (CopyRest_IsUpdateFW())
    {
        debug_msg("PowerOn with update FW\r\n");
        return TRUE;
    }
    else
    #endif
    {
        return FALSE;
    }
}
//#NT#2010/10/28#Jeah Yen -end

//#NT#2010/04/15#Jeah Yen -FASTBOOT- -begin
INT32 FlowMode_IsPowerOnPreview(void)
{
    UINT32 uiDscMode = 0xffffffff;
    INT32 uiMode = 1;//photo mode
    DBG_IND("^BFlowMode_IsPowerOnPreview begin\r\n");
    uiDscMode = FlowMode_GetPowerOnMode();
    if(uiDscMode < DSC_MODE_MOVIE)
    {
        //#NT#2010/07/14#Lincy Lin -begin
        //#NT#Fix panorama mode init cache buffer set error when panorama mode power on
        UI_SetData(FL_NextMode, uiDscMode);
        //#NT#2010/07/14#Lincy Lin -end
        uiMode = 1; //photo mode
    }
    if(uiDscMode == DSC_MODE_MOVIE)
    {
        uiMode = 2;
    }
    if(uiDscMode == DSC_MODE_PLAYBACK)
    {
        uiMode = 0; //playback mode
    }
    if(uiDscMode >= DSC_MODE_USB_APP)
    {
        uiMode = 3; //USB mode (maybe~)
    }
    DBG_IND("^BUI Mode=%d\r\n", uiMode);
    DBG_IND("^BFlowMode_IsPowerOnPreview end\r\n");
    return uiMode;
}
//#NT#2010/04/15#Jeah Yen -FASTBOOT- -end

/////////////////////////////////////////////////////////////////////////////
//#NT#2010/07/14#Jeah Yen -end


static UINT32       FlowWndPrevMode = 0;

void UI_SetPrevMode(UINT32 value)
{
    FlowWndPrevMode = value;
}

UINT32 UI_GetPrevMode(void)
{
    return FlowWndPrevMode;
}

void UI_Switch_DscMode(UINT32 uiModeTransTo, UINT32 uiTransParam, UINT32 uiTransDir)
{
    DBG_IND("UI_Switch_DscMode: DSC mode switched to %d\r\n", uiModeTransTo);

    /*
     * Set next DSC mode index.
     * Note that, DSC mode index can NOT be changed until previous mode AppInit_Close completed!!!
     */
    //SetNextDscMode(uiModeTransTo);
    //#NT#2010/03/02#Lincy Lin -begin
    /*
    if (uiModeTransTo == UI_GetData(FL_NextMode))
    {
        debug_err(("No change: FL_NextMode =%d\r\n", UI_GetData(FL_NextMode)));
        return;
    }
    */
    //#NT#2010/03/02#Lincy Lin -end

    //#NT#2011/04/19#Photon Lin -begin
    //Does not change mode if enters flow of power off
    if (bisEnterPowerOff&&(UI_GetData(FL_MovieAutoRecLastMode)!=DSC_MODE_MOVIE)&&(UI_GetData(FL_ModeIndex)==DSC_MODE_MOVIE))
    {
        UI_SetData(FL_ModeIndex,UI_GetData(FL_MovieAutoRecLastMode));
        return;
    }
    //#NT#2011/04/19#Photon Lin -end
    //#NT#2010/09/02#Steven feng -begin
    if(gbIsPlayBackModePowerOn == 1)
    {
//#NT#2010/09/17#Jeah Yen -begin
        //UI_SetData(FL_PreMode,sysInfo.ulmodeIndex);
        UI_SetData(FL_PreMode,currentInfo.ulmodeIndex);
//#NT#2010/09/17#Jeah Yen -end
        gbIsPlayBackModePowerOn = 0;
    }
    else
        UI_SetData(FL_PreMode,UI_GetData(FL_ModeIndex));
    //#NT#2010/09/02#Steven feng -end
    //debug_msg("set pre mode =%d",UI_GetData(FL_ModeIndex));

    UI_SetData(FL_NextMode,uiModeTransTo);
    //debug_msg("set Next mode =%d",uiModeTransTo);

    /* Set DSC mode switch parameters */
    //SetModeTransParam(uiTransParam);
    UI_SetData(FL_ModeTransParam,uiTransParam);

    /* Set DSC mode switch direction */
    //SetModeTransDir(uiTransDir);
    UI_SetData(FL_ModeTransDir,uiTransDir);

    /* Switch DSC mode */
    switch(uiModeTransTo)
    {
        case DSC_MODE_PHOTO_AUTO:
            Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_PHOTO);
            //ImgCapture_SetParameter(_DSCMode, _DSC_Auto);
            break;

        case DSC_MODE_PHOTO_MANUAL:
            Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_PHOTO);
            //ImgCapture_SetParameter(_DSCMode, _DSC_Manual);
            break;

        case DSC_MODE_PHOTO_ASCN:
            Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_PHOTO);
            //ImgCapture_SetParameter(_DSCMode, _DSC_Manual);
            break;


        case DSC_MODE_PHOTO_PANORAMA:
            Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_PHOTO);
            //ImgCapture_SetParameter(_DSCMode, _DSC_Panorama);
            break;

        case DSC_MODE_PHOTO_SCENE:
            Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_PHOTO);
            //ImgCapture_SetParameter(_DSCMode, _DSC_Scene);
            break;

        case DSC_MODE_PHOTO_STAB:
            Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_PHOTO);
            //ImgCapture_SetParameter(_DSCMode, _DSC_Stabilization);
            break;

        case DSC_MODE_MOVIE:
            Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_MOVIE);
            //ImgCapture_SetParameter(_DSCMode, _DSC_Movie);
            break;

        case DSC_MODE_PHOTO_PORTRAIT:
            Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_PHOTO);
            //ImgCapture_SetParameter(_DSCMode, _DSC_AutoScene);
            break;

        case DSC_MODE_PLAYBACK:
            Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_PLAYBACK);
            //ImgCapture_SetParameter(_DSCMode, _DSC_Playback);
            break;

        default:
            DBG_ERR("UI_Switch_DscMode: Unknown DSC mode 0x%x\r\n", uiModeTransTo);
            break;
    }
}



INT32 FlowMode_GetPowerOnMode(void)
{
    static UINT32 uiDscMode = DSC_MODE_PHOTO_AUTO;
    DBG_IND("^BFlowMode_GetPowerOnMode begin\r\n");

    if (guiPwrOnAskModeCnt > 0)
    {
        guiPwrOnAskModeCnt++;
        DBG_IND("^BPower-On DscMode=%d\r\n", uiDscMode);
        DBG_IND("^BFlowMode_GetPowerOnMode end\r\n");

        return uiDscMode;
    }

    if (FlowMode_IsPowerOnPlayback())
    {
        //Boot from Playback Key pressed

        uiDscMode = DSC_MODE_PLAYBACK;
        DBG_IND("^B  PB mode\r\n");
    }
    //USB_VENDOR is Spy Mechanism, do not change any USB mode
    else if(GxUSB_GetIsUSBPlug()
        && !IS_USB_VENDOR())
    {
        //Boot from USB port plugin

        UINT32 uiConfigUSBMode = UI_GetData(FL_USB_MODE);

        uiDscMode = DSC_MODE_USB_APP_MSDC; //Default
        DBG_IND("^B  USB mode\r\n");

        if (USB_MODE_MSDC == uiConfigUSBMode)
        {
            uiDscMode = DSC_MODE_USB_APP_MSDC;
        }
        else if (USB_MODE_PTP == uiConfigUSBMode)
        {
            uiDscMode = DSC_MODE_USB_APP_SIDC;
        }
        else if (USB_MODE_PICTBRIDGE == uiConfigUSBMode)
        {
            uiDscMode = DSC_MODE_USB_APP_PRINTER;
        }
        else if (USB_MODE_PCC == uiConfigUSBMode)
        {
            uiDscMode = DSC_MODE_USB_APP_PCC;
        }
#if _DEMO_TODO
        else if (USB_MODE_YOUTUBE == uiConfigUSBMode)
        {
            uiDscMode = DSC_MODE_USB_APP_YOUTUBE;
        }
#endif
    }
    else //Not USB Mode or USB Vendor Spy Mode
    {
        //Boot from Power Key pressed
        #if (MODEKEY_FUNCTION == ENABLE)
        UINT32 uiLastPowerOffMode = UI_GetData(FL_ModeIndex);

        DBG_IND("^B  Photo or Movie mode\r\n");

        if( uiLastPowerOffMode== DSC_MODE_PHOTO_AUTO ||
            uiLastPowerOffMode== DSC_MODE_PHOTO_MANUAL ||
            uiLastPowerOffMode== DSC_MODE_PHOTO_ASCN ||
            uiLastPowerOffMode== DSC_MODE_PHOTO_PANORAMA ||
            uiLastPowerOffMode== DSC_MODE_PHOTO_SCENE ||
            uiLastPowerOffMode== DSC_MODE_PHOTO_STAB ||
            uiLastPowerOffMode== DSC_MODE_MOVIE ||
            uiLastPowerOffMode== DSC_MODE_PHOTO_PORTRAIT)
        {
            uiDscMode = uiLastPowerOffMode;
        }
        #else
        DBG_IND("^B  Photo or Movie mode\r\n");

        uiDscMode = Input_Key2Mode(GxKey_GetData(GXKEY_STS_KEY1));
        #endif
    }

    guiPwrOnMode = uiDscMode;
    guiPwrOnAskModeCnt++;
    DBG_IND("^BPower-On DscMode=%d\r\n", uiDscMode);
    DBG_IND("^BFlowMode_GetPowerOnMode end\r\n");

    return uiDscMode;
}


INT32 FlowMode_GetPowerOnMode_FromChargeMode(void)
{
    static UINT32 uiDscMode = DSC_MODE_PHOTO_AUTO;
    return uiDscMode;
}

void FlowMode_OnPowerOn(void)
{
    UINT32 uiDscMode = 0xffffffff;
    FlowWndPrevMode = 0;

    DBG_IND("^BFlowMode_OnPowerOn begin\r\n");
    uiDscMode = FlowMode_GetPowerOnMode();
    UI_SetData(FL_ModeIndex,uiDscMode);
    switch(uiDscMode)
    {
        case DSC_MODE_USB_APP:
            {
            UIDebug_usb(("^BAlready unplug usb, skip change to USB mode\r\n"));
            DBG_IND("^BFlowMode_OnPowerOn end\r\n");
            return;
            }
            break;
        case DSC_MODE_USB_APP_MSDC:
        case DSC_MODE_USB_APP_SIDC:
        case DSC_MODE_USB_APP_PRINTER:
        case DSC_MODE_USB_APP_PCC:
        case DSC_MODE_USB_FAST_CHARGE:
            //all USB modes
            UIDebug_usb(("^BUSB is plug before first time check power-on mode!\r\n"));
            UIDebug_usb(("^BStill plug usb, USB PC\r\n"));
            GxUSB_DetConnect(); //dummy detect
            UI_UnlockEvent(); //>>> Not change to any mode, just start to detect USB plug
            break;
        default:
            //all other modes
            {
                //>>> start to change mode
                UI_Switch_DscMode(uiDscMode,DSCMODE_SWITCH_FORCE,DSCMODE_SWITCHDIR_DONT_CARE);
                #if (WAITPHOTO_FUNCTION == ENABLE)
                //skip wait
                #else
                InitIPL_WaitFinish();
                InitLens_WaitFinish();
                #endif
            }
            break;
    }
    DBG_IND("^BFlowMode_OnPowerOn end\r\n");
}

void FlowMode_OnPowerOff(void)
{
    bisEnterPowerOff = TRUE;
    Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, SYS_MODE_UNKNOWN); //close last app mode
}

UINT32 uiPreDSCMode = SYS_MODE_UNKNOWN;

void FlowMode_OnKeyMode(UINT32 uiDscMode)
{
    //#NT#2009/11/30#Photon Lin -begin
    static BOOL FirstStatusKeyCB = TRUE;
    //#NT#2009/11/30#Photon Lin -end

    //#NT#2009/11/30#Photon Lin -begin
    if (FirstStatusKeyCB)
    {
        //press Mode key (first time)

        //#NT#2010/01/20#Lincy Lin -begin
        FirstStatusKeyCB = FALSE;
        //#NT#2010/01/21#Niven Cho -begin
        //#NT#Modified., Enter Msdc DbgSys by Zoom Out Key
        if(!GxUSB_GetIsUSBPlug() || IS_USB_VENDOR())
        {
            if (uiDscMode == UI_GetData(FL_ModeIndex))
            {
                //mode is not changed (from FlowMode_OnPowerOn)
                uiPreDSCMode = uiDscMode;
            }
            else
            {
                //mode is changed (from FlowMode_OnPowerOn)
                if (!FlowMode_IsPowerOnPlayback())
                {
                    //#NT#2010/03/02#Lincy Lin -begin
                    if (uiDscMode != UI_GetData(FL_NextMode))
                    {
                        UI_Switch_DscMode(uiDscMode,DSCMODE_SWITCH_FORCE,DSCMODE_SWITCHDIR_DONT_CARE);
                    }
                    //#NT#2010/03/02#Lincy Lin -end
                }
            }
        }
        //#NT#2010/01/21#Niven Cho -end
        //#NT#2010/01/20#Lincy Lin -end
    }
    else
    {
        UINT32 uiTransDir;

        //press Mode key

        /*
        if (uiPreDSCMode != uiDscMode)
        {
            uiPreDSCMode = uiDscMode;
            Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, uiDscMode);
        }
        CBPostEvent(NVTEVT_MODE_CHANGE, NVTEVT_MODE_CHANGE, 0);
        */
        if (uiDscMode > uiPreDSCMode)
            uiTransDir = DSCMODE_SWITCHDIR_L_R;
        else
            uiTransDir = DSCMODE_SWITCHDIR_R_L;
        UI_Switch_DscMode(uiDscMode,DSCMODE_SWITCH_ANI,uiTransDir);
    }
    //#NT#2009/11/30#Photon Lin -end
}


void FlowMode_OnUsbPlug(void)
{
    UINT32 usbMode = UI_GetData(FL_USB_MODE);

    UIDebug_usb(("^BFlowMode_OnUsbPlug begin\r\n"));
    UIDebug_usb(("USB_CB:PlugIn,cur mode=%d,usb mode=%d\r\n",System_GetState(SYS_STATE_CURRMODE),usbMode));

    //#NT#2010/11/26#Jeah Yen -begin
    if (UI_GetData(FL_ModeIndex) == DSC_MODE_USB_FAST_CHARGE)
    {
        return;
    }
    //#NT#2010/11/26#Jeah Yen -end

    //#NT#2010/11/17#Lily Kao -begin
    if (usbMode == USB_MODE_PTP)
    {
#if (UI_STYLE!=UI_STYLE_DRIVER)
        UI_SetData(FL_NextMode, DSC_MODE_USB_APP_SIDC);
        Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_USBSIDC);
#endif
    }
    else if (usbMode == USB_MODE_PICTBRIDGE)
    {
#if (UI_STYLE!=UI_STYLE_DRIVER)
        UI_SetData(FL_NextMode, DSC_MODE_USB_APP_PRINTER);
        Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_PRINTER);
#endif
    }
    else if (usbMode == USB_MODE_PCC)
    {
        UI_SetData(FL_NextMode, DSC_MODE_USB_APP_PCC);
        Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_USBPCC);
    }
#if _DEMO_TODO
    else if (usbMode == USB_MODE_YOUTUBE)
    {
        UI_SetData(FL_NextMode, DSC_MODE_USB_APP_MSDC);
        Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_USBYOUTUBE);
    }

#endif
    else //if (usbMode == USB_MODE_MSDC)
    {
        UI_SetData(FL_NextMode, DSC_MODE_USB_APP_MSDC);
        Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_USBMSDC);
    }
    //#NT#2010/11/17#Lily Kao -end
    UIDebug_usb(("^BFlowMode_OnUsbPlug end\r\n"));
}


void FlowMode_OnUsbUnplug(void)
{
    UINT32 filesize ;
    char * uiBuffer ;
    //ER status ;
    UIDebug_usb(("^BFlowMode_OnUsbUnplug begin\r\n"));
    //#NT#2010/03/16#Lincy Lin -begin
    //#NT# For Calibration
    #if 1
    if(IS_USB_VENDOR())
    {
            FST_FILE filehdl = NULL;
            INT32 ret = FST_STA_ERROR;
#if _DEMO_TODO
            GxFile_GetStorageObj(PRIMARY_STGTYPE_CARD)->Close();
            //GxFile_ChangeStorage(PRIMARY_STGTYPE_CARD);
            GxFile_ChangeStorage(PRIMARY_STGTYPE_CARD);
#endif
            uiBuffer = (char *)OS_GetMempoolAddr(POOL_ID_GFX_IMAGE);
            debug_err(("\n[IMG] Pool size read %d \r\n", OS_GetMempoolSize(POOL_ID_GFX_IMAGE)));
            // Update English Language begin
            filesize = 0x4;
            // Disable IDE video1/video2 output
            //UI_Show(UI_SHOW_INFO, TRUE); //OSD2
            //UI_Show(UI_SHOW_WINDOW, TRUE);  //OSD1
            //UI_Show(UI_SHOW_BACKGND, TRUE); //VDO2
            //UI_Show(UI_SHOW_PREVIEW, TRUE); //VDO1
            GxVideo_SetDeviceCtrl(DOUT1, DISPLAY_DEVCTRL_BRIGHTLVL, 5);
            filehdl = FileSys_OpenFile("A:\\FO.txt",FST_OPEN_READ);
            ret = FileSys_ReadFile(filehdl,(UINT8*)uiBuffer,&filesize, 0, 0);
            FileSys_CloseFile(filehdl);
            if(ret==FST_STA_OK)
            {
                Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_PHOTO);
                #if (_CALIBRATION_MODE_ == ENABLE)
                //g_IsautoMTF = TRUE;
                g_bCalbirationOpened = FALSE;
                #endif
                SwTimer_DelayMs(1500);
                Ux_PostEvent(NVTEVT_STORAGE_INIT, 0, 0);
                //FocusOffsetAdjust();
                //debug_err(("^R status = 0x%x 0x%x \r\n" , status , *(UINT32 *)uiBuffer));
            }
            else
            {
                UIDebug_usb(("^B USB PlugOff,PwrOff 1\r\n"));
                System_PowerOff(SYS_POWEROFF_NORMAL);
            }
    }
    else
    {
        UIDebug_usb(("^B USB PlugOff,PwrOff 2\r\n"));
#if (_MODEL_DSC_ == _MODEL_DUAL_BMWCABLE_)	     
        System_PowerOff(SYS_POWEROFF_NORMAL);
#else	
    //-------------jack lan begin-------------
    if((System_GetState(SYS_STATE_CURRMODE) == PRIMARY_MODE_USBPCC)||
		(System_GetState(SYS_STATE_CURRMODE) == PRIMARY_MODE_USBMSDC)||
             (System_GetState(SYS_STATE_CURRMODE) == PRIMARY_MODE_USBMENU))//||
             //(UI_GetData(FL_DELAYOFF)==DELAYOFF_OFF))
    {
         System_PowerOff(SYS_POWEROFF_NORMAL);
    }    
#endif	
    //-------------jack lan end-------------		
        //System_PowerOff(SYS_POWEROFF_NORMAL);//jack lan mark 
    }
    #else
    #if (MODEKEY_FUNCTION == ENABLE)
    Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, System_GetState(SYS_STATE_PREVMODE));
    //#NT#2009/12/24#Lily Kao - begin
    debug_msg("USB_CB:PlugOff,PrevMode=%d\r\n",System_GetState(SYS_STATE_PREVMODE));
    //System_PowerOff();
    //#NT#2010/01/14#Lincy Lin -begin
//#NT#2010/02/03#Brad Chen -begin
//#NT# add USB unplug then change to photo mode
    {
        UINT32 uiDscMode;
        //#NT#2010/01/20#JeahYen -begin
        uiDscMode = Input_Key2Mode(GxKey_GetData(GXKEY_STS_KEY1));
        //#NT#2010/01/20#JeahYen -end
        UI_SetData(FL_ModeIndex,uiDscMode);
        UI_Switch_DscMode(uiDscMode,DSCMODE_SWITCH_FORCE,DSCMODE_SWITCHDIR_DONT_CARE);
    }
//#NT#2010/02/03#Brad Chen -end
    #else
    {
        UINT32 uiDscMode;
        //#NT#2010/01/20#JeahYen -begin
        uiDscMode = Input_Key2Mode(GxKey_GetData(GXKEY_STS_KEY1));
        //#NT#2010/01/20#JeahYen -end
        UI_SetData(FL_ModeIndex,uiDscMode);
        UI_Switch_DscMode(uiDscMode,DSCMODE_SWITCH_FORCE,DSCMODE_SWITCHDIR_DONT_CARE);
    }
    #endif
    #endif
    //#NT#2010/03/16#Lincy Lin -end
    UIDebug_usb(("^BFlowMode_OnUsbUnplug end\r\n"));
}



