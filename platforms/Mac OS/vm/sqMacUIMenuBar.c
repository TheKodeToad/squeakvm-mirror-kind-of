/****************************************************************************
*   PROJECT: Mac menu bar logic
*   FILE:    sqMacUIMenuBar.c
*   CONTENT: 
*
*   AUTHOR:  John Maloney, John McIntosh, and others.
*   ADDRESS: 
*   EMAIL:   johnmci@smalltalkconsulting.com
*   RCSID:   $Id: sqMacUIMenuBar.c,v 1.2 2002/02/23 11:26:06 johnmci Exp $
*
*   NOTES: 
*  Feb 22nd, 2002, JMM moved code into 10 other files, see sqMacMain.c for comments
*****************************************************************************/

#include "sqMacUIMenuBar.h"
#include "sqMacMain.h"
#include "sqMacWindow.h"

MenuHandle	appleMenu = nil;
MenuHandle	editMenu = nil;
int		menuBarHeight = 20;
RgnHandle	menuBarRegion = nil;  /* if non-nil, then menu bar has been hidden */
MenuHandle	fileMenu = nil;

 
#if TARGET_API_MAC_CARBON
    #define EnableMenuItemCarbon(m1,v1)  EnableMenuItem(m1,v1);
    #define DisableMenuItemCarbon(m1,v1)  DisableMenuItem(m1,v1);
#else
    #define EnableMenuItemCarbon(m1,v1)  EnableItem(m1,v1);
    #define DisableMenuItemCarbon(m1,v1)  DisableItem(m1,v1);
#endif

#if TARGET_API_MAC_CARBON

void MenuBarHide(void) {
 	if (menuBarRegion != nil) return;  /* saved state, so menu bar is already hidden */
    menuBarRegion = (RgnHandle) 1;
    HideMenuBar();
}
void MenuBarRestore(void) {
	if (menuBarRegion == nil) return;  /* no saved state, so menu bar is not hidden */
    ShowMenuBar();
    menuBarRegion = nil;
}

#else
void MenuBarHide(void) {
  /* Remove the menu bar, saving its old state. */
  /* Many thanks to John McIntosh for this code! */
	Rect screenRect, mBarRect;

	if (menuBarRegion != nil) return;  /* saved state, so menu bar is already hidden */
	screenRect = (**GetMainDevice()).gdRect;
	menuBarHeight = GetMBarHeight();
	SetRect(&mBarRect, screenRect.left, screenRect.top, screenRect.right, screenRect.top + menuBarHeight);
	menuBarRegion = NewRgn();
	if (menuBarRegion != nil) {
		LMSetMBarHeight(0);
		RectRgn(menuBarRegion, &mBarRect);
		UnionRgn(GetGrayRgn(), menuBarRegion, GetGrayRgn());
		PaintOne(NULL,menuBarRegion);
		CalcVisBehind(getSTWindow(),menuBarRegion);
	}
}

void MenuBarRestore(void) {
  /* Restore the menu bar from its saved state. Do nothing if it isn't hidden. */
  /* Many thanks to John McIntosh for this code! */
 
 	WindowPtr win;
 	
	if (menuBarRegion == nil) return;  /* no saved state, so menu bar is not hidden */
	DiffRgn(GetGrayRgn(), menuBarRegion, GetGrayRgn());
	LMSetMBarHeight(menuBarHeight);
	
	win = FrontWindow();
	if (win) {
		CalcVis(win);
		CalcVisBehind(win,menuBarRegion);
	}
	HiliteMenu(0);
	DisposeRgn(menuBarRegion);
	
	menuBarRegion = nil;
	DrawMenuBar();
}

#endif

void SetUpMenus(void) {
	long decideOnQuitMenu;
	
	InsertMenu(appleMenu = NewMenu(appleID, "\p\024"), 0);
	InsertMenu(fileMenu  = NewMenu(fileID,  "\pFile"), 0);
	InsertMenu(editMenu  = NewMenu(editID,  "\pEdit"), 0);
	DrawMenuBar();
#if TARGET_API_MAC_CARBON
    Gestalt( gestaltMenuMgrAttr, &decideOnQuitMenu);
    if (!(decideOnQuitMenu & gestaltMenuMgrAquaLayoutMask) || true)	
        AppendMenu(fileMenu, "\pQuit do not save");
    if (RunningOnCarbonX())
        DisableMenuCommand(NULL,'quit');
        
#else
	AppendResMenu(appleMenu, 'DRVR');
    AppendMenu(fileMenu, "\pQuit do not save");
#endif
 	AppendMenu(editMenu, "\pUndo/Z;(-;Cut/X;Copy/C;Paste/V;Clear");
}

 void AdjustMenus(void) {
	WindowRef		wp;
	int				isDeskAccessory;

	wp = FrontWindow();
	if (wp != NULL) {
		isDeskAccessory = GetWindowKind(wp) < 0;
	} else {
		isDeskAccessory = false;
	}

	if (isDeskAccessory) {
		/* Enable items in the Edit menu */
		EnableMenuItemCarbon(editMenu, 1);
		EnableMenuItemCarbon(editMenu, 3);
		EnableMenuItemCarbon(editMenu, 4);
		EnableMenuItemCarbon(editMenu, 5);
		EnableMenuItemCarbon(editMenu, 6);
	} else {
		/* Disable items in the Edit menu */
		DisableMenuItemCarbon(editMenu, 1);
		DisableMenuItemCarbon(editMenu, 3);
		DisableMenuItemCarbon(editMenu, 4);
		DisableMenuItemCarbon(editMenu, 5);
		DisableMenuItemCarbon(editMenu, 6);
	}
}
