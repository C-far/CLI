/*

	The MIT License (MIT)
	Copyright (c) 2016 - Timothé Dutheil : C_far

	Permission is hereby granted, free of charge, to any person obtaining a 
	copy of this software and associated documentation files (the "Software"), 
	to deal in the Software without restriction, including without limitation 
	the rights to use, copy, modify, merge, publish, distribute, sublicense, 
	and/or sell copies of the Software, and to permit persons to whom the 
	Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included 
	in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
	OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
	THE SOFTWARE.

*/

/**********************************
 *                                *
 *   @Author:      Dutheil        *
 *   @Version:     0.2		      *
 *   @Released:    30/06/2016     *
 *                                *
 **********************************/

#if defined _cli_speakdialog_included
	#endinput
#endif	
#define _cli_speakdialog_included

//-----------------------------
//-------------------------------------------------
//-----------------------------	

/*
	native ShowSpeakDialog(playerid, function[], caption[], info[], skin, s = sizeof(info));
	native HideSpeakDialog(playerid);
	
	native SpeakDialogOpened(playerid);
*/

//-----------------------------
//-------------------------------------------------
//-----------------------------	
	
#tryinclude <YSI\y_hooks>

#if defined HOOKS_MAX_UPDATES || defined _INC_y_hooks
	#define use_y_hooks
#endif 

//-----------------------------
//-------------------------------------------------
//-----------------------------

#define cli_CAPTION (0)
#define cli_INFO (1)
#define cli_SKIN (2)

//-----------------------------

#define cli_VALIDATE (13)
#define cli_CANCEL (14)

//-----------------------------

#define SpeakDialog:%0(%1) \
	forward sd_%0(%1); public sd_%0(%1)

//-----------------------------

#define ShowSpeakDialog(%0,%1,%2,%3,%4) \ 
	ShowSpeakDialog_(%0, #%1, %2, %3, %4)

//-----------------------------
//-------------------------------------------------
//-----------------------------

static stock 
	Text:cli_sd_td[15],
	PlayerText:cli_sd_ptd[MAX_PLAYERS][3],
	cli_sd_function[MAX_PLAYERS][32 char],
	bool:cli_sd_open[MAX_PLAYERS char],
	bool:cli_sd_canceltextdraw;

//-----------------------------
//-------------------------------------------------
//-----------------------------

#if defined use_y_hooks
hook OnGameModeInit()
#else
public OnGameModeInit()
#endif
{
	cli_sd_td[0] = TextDrawCreate(374.500000, 130.125000, "usebox");
	TextDrawLetterSize(cli_sd_td[0], 0.000000, 11.543053);
	TextDrawTextSize(cli_sd_td[0], 90.000000, 0.000000);
	TextDrawAlignment(cli_sd_td[0], 1);
	TextDrawColor(cli_sd_td[0], 0);
	TextDrawUseBox(cli_sd_td[0], true);
	TextDrawBoxColor(cli_sd_td[0], 255);
	TextDrawSetShadow(cli_sd_td[0], 0);
	TextDrawSetOutline(cli_sd_td[0], 0);
	TextDrawFont(cli_sd_td[0], 0);

	cli_sd_td[1] = TextDrawCreate(80.000000, 128.187500, "ld_pool:ball");
	TextDrawLetterSize(cli_sd_td[1], 0.000000, 0.000000);
	TextDrawTextSize(cli_sd_td[1], 29.500000, 24.500000);
	TextDrawAlignment(cli_sd_td[1], 1);
	TextDrawColor(cli_sd_td[1], 255);
	TextDrawSetShadow(cli_sd_td[1], 0);
	TextDrawSetOutline(cli_sd_td[1], 0);
	TextDrawFont(cli_sd_td[1], 4);

	cli_sd_td[2] = TextDrawCreate(80.000000, 211.437500, "ld_pool:ball");
	TextDrawLetterSize(cli_sd_td[2], 0.000000, 0.000000);
	TextDrawTextSize(cli_sd_td[2], 29.500000, 24.500000);
	TextDrawAlignment(cli_sd_td[2], 1);
	TextDrawColor(cli_sd_td[2], 255);
	TextDrawSetShadow(cli_sd_td[2], 0);
	TextDrawSetOutline(cli_sd_td[2], 0);
	TextDrawFont(cli_sd_td[2], 4);

	cli_sd_td[3] = TextDrawCreate(354.500000, 211.562500, "ld_pool:ball");
	TextDrawLetterSize(cli_sd_td[3], 0.000000, 0.000000);
	TextDrawTextSize(cli_sd_td[3], 29.500000, 24.500000);
	TextDrawAlignment(cli_sd_td[3], 1);
	TextDrawColor(cli_sd_td[3], 255);
	TextDrawSetShadow(cli_sd_td[3], 0);
	TextDrawSetOutline(cli_sd_td[3], 0);
	TextDrawFont(cli_sd_td[3], 4);

	cli_sd_td[4] = TextDrawCreate(354.500000, 128.125000, "ld_pool:ball");
	TextDrawLetterSize(cli_sd_td[4], 0.000000, 0.000000);
	TextDrawTextSize(cli_sd_td[4], 29.500000, 24.500000);
	TextDrawAlignment(cli_sd_td[4], 1);
	TextDrawColor(cli_sd_td[4], 255);
	TextDrawSetShadow(cli_sd_td[4], 0);
	TextDrawSetOutline(cli_sd_td[4], 0);
	TextDrawFont(cli_sd_td[4], 4);

	cli_sd_td[5] = TextDrawCreate(386.000000, 143.250000, "usebox");
	TextDrawLetterSize(cli_sd_td[5], 0.000000, 8.958332);
	TextDrawTextSize(cli_sd_td[5], 78.500000, 0.000000);
	TextDrawAlignment(cli_sd_td[5], 1);
	TextDrawColor(cli_sd_td[5], 255);
	TextDrawUseBox(cli_sd_td[5], true);
	TextDrawBoxColor(cli_sd_td[5], 255);
	TextDrawSetShadow(cli_sd_td[5], 0);
	TextDrawSetOutline(cli_sd_td[5], 0);
	TextDrawFont(cli_sd_td[5], 0);

	cli_sd_td[6] = TextDrawCreate(92.500000, 128.625000, "LD_SPAC:white");
	TextDrawLetterSize(cli_sd_td[6], 0.000000, 0.000000);
	TextDrawTextSize(cli_sd_td[6], 280.000000, 11.812500);
	TextDrawAlignment(cli_sd_td[6], 1);
	TextDrawColor(cli_sd_td[6], 1077952767);
	TextDrawSetShadow(cli_sd_td[6], 0);
	TextDrawSetOutline(cli_sd_td[6], 0);
	TextDrawFont(cli_sd_td[6], 4);
	
	cli_sd_td[7] = TextDrawCreate(357.500000, 214.375000, "ld_beat:downr");
	TextDrawLetterSize(cli_sd_td[7], 0.070997, 0.231874);
	TextDrawTextSize(cli_sd_td[7], 37.500000, 28.875000);
	TextDrawAlignment(cli_sd_td[7], 1);
	TextDrawColor(cli_sd_td[7], 255);
	TextDrawSetShadow(cli_sd_td[7], 0);
	TextDrawSetOutline(cli_sd_td[7], 0);
	TextDrawFont(cli_sd_td[7], 4);

	cli_sd_td[8] = TextDrawCreate(372.000000, 150.937500, "LD_SPAC:white");
	TextDrawLetterSize(cli_sd_td[8], 0.000000, 0.000000);
	TextDrawTextSize(cli_sd_td[8], -279.000000, 77.437500);
	TextDrawAlignment(cli_sd_td[8], 1);
	TextDrawColor(cli_sd_td[8], -2139062017);
	TextDrawSetShadow(cli_sd_td[8], 0);
	TextDrawSetOutline(cli_sd_td[8], 0);
	TextDrawFont(cli_sd_td[8], 4);

	cli_sd_td[9] = TextDrawCreate(362.000000, 220.062500, "ld_pool:ball");
	TextDrawLetterSize(cli_sd_td[9], 0.000000, 0.000000);
	TextDrawTextSize(cli_sd_td[9], 17.000000, 14.437500);
	TextDrawAlignment(cli_sd_td[9], 1);
	TextDrawColor(cli_sd_td[9], 255);
	TextDrawSetShadow(cli_sd_td[9], 0);
	TextDrawSetOutline(cli_sd_td[9], 0);
	TextDrawFont(cli_sd_td[9], 4);

	cli_sd_td[10] = TextDrawCreate(87.000000, 144.437500, "ld_pool:ball");
	TextDrawLetterSize(cli_sd_td[10], 0.000000, 0.000000);
	TextDrawTextSize(cli_sd_td[10], 17.000000, 14.437500);
	TextDrawAlignment(cli_sd_td[10], 1);
	TextDrawColor(cli_sd_td[10], 255);
	TextDrawSetShadow(cli_sd_td[10], 0);
	TextDrawSetOutline(cli_sd_td[10], 0);
	TextDrawFont(cli_sd_td[10], 4);

	cli_sd_td[11] = TextDrawCreate(85.500000, 219.750000, "ld_pool:ball");
	TextDrawLetterSize(cli_sd_td[11], 0.000000, 0.000000);
	TextDrawTextSize(cli_sd_td[11], 17.000000, 14.437500);
	TextDrawAlignment(cli_sd_td[11], 1);
	TextDrawColor(cli_sd_td[11], 255);
	TextDrawSetShadow(cli_sd_td[11], 0);
	TextDrawSetOutline(cli_sd_td[11], 0);
	TextDrawFont(cli_sd_td[11], 4);

	cli_sd_td[12] = TextDrawCreate(361.500000, 144.750000, "ld_pool:ball");
	TextDrawLetterSize(cli_sd_td[12], 0.000000, 0.000000);
	TextDrawTextSize(cli_sd_td[12], 17.000000, 14.437500);
	TextDrawAlignment(cli_sd_td[12], 1);
	TextDrawColor(cli_sd_td[12], 255);
	TextDrawSetShadow(cli_sd_td[12], 0);
	TextDrawSetOutline(cli_sd_td[12], 0);
	TextDrawFont(cli_sd_td[12], 4);		
	
	cli_sd_td[cli_VALIDATE] = TextDrawCreate(181.500000, 227.500000, "VALIDER");
	TextDrawTextSize(cli_sd_td[cli_VALIDATE], 230.0, 10.0);
	TextDrawLetterSize(cli_sd_td[cli_VALIDATE], 0.232999, 0.851875);
	TextDrawAlignment(cli_sd_td[cli_VALIDATE], 1);
	TextDrawColor(cli_sd_td[cli_VALIDATE], -1061109505);
	TextDrawSetShadow(cli_sd_td[cli_VALIDATE], 0);
	TextDrawSetOutline(cli_sd_td[cli_VALIDATE], 1);
	TextDrawBackgroundColor(cli_sd_td[cli_VALIDATE], 51);
	TextDrawFont(cli_sd_td[cli_VALIDATE], 2);
	TextDrawSetProportional(cli_sd_td[cli_VALIDATE], 1);
	TextDrawSetSelectable(cli_sd_td[cli_VALIDATE], true);

	cli_sd_td[cli_CANCEL] = TextDrawCreate(233.500000, 227.187500, "ANNULER");
	TextDrawTextSize(cli_sd_td[cli_CANCEL], 282.0, 10.0);
	TextDrawLetterSize(cli_sd_td[cli_CANCEL], 0.232999, 0.851875);
	TextDrawAlignment(cli_sd_td[cli_CANCEL], 1);
	TextDrawColor(cli_sd_td[cli_CANCEL], -1061109505);
	TextDrawSetShadow(cli_sd_td[cli_CANCEL], 0);
	TextDrawSetOutline(cli_sd_td[cli_CANCEL], 1);
	TextDrawBackgroundColor(cli_sd_td[cli_CANCEL], 51);
	TextDrawFont(cli_sd_td[cli_CANCEL], 2);
	TextDrawSetProportional(cli_sd_td[cli_CANCEL], 1);
	TextDrawSetSelectable(cli_sd_td[cli_CANCEL], true);		

	#if !defined use_y_hooks && defined cli_sd_OnGameModeInit
		cli_sd_OnGameModeInit();
	#endif
	
	return 1;
}

//-----------------------------

#if defined use_y_hooks
hook OnPlayerConnect(playerid)
#else
public OnPlayerConnect(playerid)
#endif
{	
	cli_sd_ptd[playerid][cli_CAPTION] = CreatePlayerTextDraw(playerid, 232.000000, 122.937500, "");
	PlayerTextDrawLetterSize(playerid, cli_sd_ptd[playerid][cli_CAPTION], 0.475499, 2.046247);
	PlayerTextDrawAlignment(playerid, cli_sd_ptd[playerid][cli_CAPTION], 2);
	PlayerTextDrawColor(playerid, cli_sd_ptd[playerid][cli_CAPTION], -1061109505);
	PlayerTextDrawSetShadow(playerid, cli_sd_ptd[playerid][cli_CAPTION], 0);
	PlayerTextDrawSetOutline(playerid, cli_sd_ptd[playerid][cli_CAPTION], 1);
	PlayerTextDrawBackgroundColor(playerid, cli_sd_ptd[playerid][cli_CAPTION], 1077952767);
	PlayerTextDrawFont(playerid, cli_sd_ptd[playerid][cli_CAPTION], 1);
	PlayerTextDrawSetProportional(playerid, cli_sd_ptd[playerid][cli_CAPTION], 1);

	cli_sd_ptd[playerid][cli_INFO] = CreatePlayerTextDraw(playerid, 97.000000, 160.125000, "");
	PlayerTextDrawTextSize(playerid, cli_sd_ptd[playerid][cli_INFO], 350.000000, 100.000000);
	PlayerTextDrawLetterSize(playerid, cli_sd_ptd[playerid][cli_INFO], 0.333499, 1.381250);
	PlayerTextDrawAlignment(playerid, cli_sd_ptd[playerid][cli_INFO], 1);
	PlayerTextDrawColor(playerid, cli_sd_ptd[playerid][cli_INFO], -1);
	PlayerTextDrawSetShadow(playerid, cli_sd_ptd[playerid][cli_INFO], 0);
	PlayerTextDrawSetOutline(playerid, cli_sd_ptd[playerid][cli_INFO], 1);
	PlayerTextDrawBackgroundColor(playerid, cli_sd_ptd[playerid][cli_INFO], 51);
	PlayerTextDrawFont(playerid, cli_sd_ptd[playerid][cli_INFO], 1);
	PlayerTextDrawSetProportional(playerid, cli_sd_ptd[playerid][cli_INFO], 1);
	
	cli_sd_ptd[playerid][cli_SKIN] = CreatePlayerTextDraw(playerid, 170.000000, 150.000000, "_");
	PlayerTextDrawTextSize(playerid, cli_sd_ptd[playerid][cli_SKIN], 500.000000, 600.000000);
	PlayerTextDrawFont(playerid, cli_sd_ptd[playerid][cli_SKIN], TEXT_DRAW_FONT_MODEL_PREVIEW);
	PlayerTextDrawUseBox(playerid, cli_sd_ptd[playerid][cli_SKIN], 1);
	PlayerTextDrawBoxColor(playerid, cli_sd_ptd[playerid][cli_SKIN], 0);
	PlayerTextDrawBackgroundColor(playerid, cli_sd_ptd[playerid][cli_SKIN], 0xFFFFFF00);
	PlayerTextDrawSetPreviewModel(playerid, cli_sd_ptd[playerid][cli_SKIN], 0);		

	#if !defined use_y_hooks && defined cli_sd_OnPlayerConnect
		cli_sd_OnPlayerConnect(playerid);
	#endif
	
	return 1;
}

//-----------------------------

#if defined use_y_hooks
hook OnPlayerDisconnect(playerid, reason)
#else
public OnPlayerDisconnect(playerid, reason)
#endif
{		
	cli_sd_open{playerid} = false;

	#if !defined use_y_hooks && defined cli_sd_OnPlayerDisconnect
		cli_sd_OnPlayerDisconnect(playerid, reason);
	#endif
	
	return 1;
}

//-----------------------------

#if defined use_y_hooks
hook OnPlayerClickTextDraw(playerid, Text:clickedid)
#else
public OnPlayerClickTextDraw(playerid, Text:clickedid)
#endif
{	
	if(SpeakDialogOpened(playerid))
	{
		if(_:clickedid == INVALID_TEXT_DRAW && !cli_sd_canceltextdraw)
		{		
			HideSpeakDialog(playerid);
			cli_sd_CallFunction(playerid, false);
		}
		if(clickedid == cli_sd_td[cli_VALIDATE] || clickedid == cli_sd_td[cli_CANCEL])
		{		
			HideSpeakDialog(playerid);			
			cli_sd_CallFunction(playerid, (clickedid == cli_sd_td[cli_VALIDATE]));
		}
	}
	
	cli_sd_canceltextdraw = false;
	
	#if !defined use_y_hooks && defined cli_sd_OnPlayerClickTextDraw
		cli_sd_OnPlayerClickTextDraw(playerid, clickedid);
	#endif
	
	return 1;
}

//-----------------------------
//-------------------------------------------------
//-----------------------------

#if !defined use_y_hooks

	/* HOOK OnGameModeInit */
	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit cli_sd_OnGameModeInit
	#if defined cli_sd_OnGameModeInit
		forward cli_sd_OnGameModeInit();
	#endif
	/* HOOK OnGameModeInit */

	/* HOOK OnPlayerConnect */
	#if defined _ALS_OnPlayerConnect
		#undef OnPlayerConnect
	#else
		#define _ALS_OnPlayerConnect
	#endif
	#define OnPlayerConnect cli_sd_OnPlayerConnect
	#if defined cli_sd_OnPlayerConnect
		forward cli_sd_OnPlayerConnect(playerid);
	#endif
	/* HOOK OnPlayerConnect */
	
	/* HOOK OnPlayerDisconnect */
	#if defined _ALS_OnPlayerDisconnect
		#undef OnPlayerDisconnect
	#else
		#define _ALS_OnPlayerDisconnect
	#endif
	#define OnPlayerConnect cli_sd_OnPlayerDisconnect
	#if defined cli_sd_OnPlayerDisconnect
		forward cli_sd_OnPlayerDisconnect(playerid, reason);
	#endif
	/* HOOK OnPlayerDisconnect */	
	
	/* HOOK OnPlayerClickTextDraw */
	#if defined _ALS_OnPlayerClickTextDraw
		#undef OnPlayerClickTextDraw
	#else
		#define _ALS_OnPlayerClickTextDraw
	#endif
	#define OnPlayerClickTextDraw cli_sd_OnPlayerClickTextDraw
	#if defined cli_sd_OnPlayerClickTextDraw
		forward cli_sd_OnPlayerClickTextDraw(playerid, clickedid);
	#endif
	/* HOOK OnPlayerClickTextDraw */
	
#endif

//-----------------------------
//-------------------------------------------------
//-----------------------------

stock ShowSpeakDialog_(playerid, function[], caption[], info[], skin)
{		
	PlayerTextDrawSetString(playerid, cli_sd_ptd[playerid][cli_CAPTION], caption);
	PlayerTextDrawSetString(playerid, cli_sd_ptd[playerid][cli_INFO], info);
	PlayerTextDrawSetPreviewModel(playerid, cli_sd_ptd[playerid][cli_SKIN], skin);
	
	for(new i = 0; i < sizeof(cli_sd_td); i++)
		TextDrawShowForPlayer(playerid, cli_sd_td[i]);	
	
	for(new i = 0; i < sizeof(cli_sd_ptd[]); i++)
		PlayerTextDrawShow(playerid, cli_sd_ptd[playerid][i]);
		
	cli_sd_open{playerid} = true;
	strpack(cli_sd_function[playerid], function);
		
	return SelectTextDraw(playerid, 0xFF4040AA);
}

//-----------------------------

stock HideSpeakDialog(playerid)
{
	if(!cli_sd_open{playerid}) return 1;
	
	cli_sd_open{playerid} = false;
	CancelSelectTextDraw(playerid);
	
	for(new i = 0; i < sizeof(cli_sd_td); i++)
		TextDrawHideForPlayer(playerid, cli_sd_td[i]);
	
	for(new i = 0; i < sizeof(cli_sd_ptd[]); i++)
		PlayerTextDrawHide(playerid, cli_sd_ptd[playerid][i]);
		
	return 1;
}

//-----------------------------

static stock cli_sd_CallFunction(playerid, bool:response)
{
	new
		func[40] = "sd_";

	strcat(func, cli_sd_function[playerid]);
	
	if(funcidx(func) != -1)
		CallLocalFunction(func, "dd", playerid, _:response);
	
	return 1;
}

//-----------------------------

stock SpeakDialogOpened(playerid)
	return (cli_sd_open{playerid});
	
//-----------------------------

stock cli_sd_CancelSelectTextDraw(playerid)
{
	cli_sd_canceltextdraw = true;

	return CancelSelectTextDraw(playerid);
}

#if defined _ALS_CancelSelectTextDraw
	#undef CancelSelectTextDraw
#else
	#define _ALS_CancelSelectTextDraw
#endif
#define CancelSelectTextDraw cli_sd_CancelSelectTextDraw