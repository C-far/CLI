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
 *   @Author:      C_far          *
 *   @Version:     0.4		      *
 *   @Released:    30/06/2016     *
 *                                *
 **********************************/

#if defined _cli_doorswindows_included
	#endinput
#endif	
#define _cli_doorswindows_included

//-----------------------------
//-------------------------------------------------
//-----------------------------

#define P_CNTD:%0(%1) \
	forward pcntd_%0(%1); public pcntd_%0(%1)
	
#if !defined isnull
	#define isnull(%1) \
				((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif	

#define StartCountdownForPlayer(%0,%1,%2) \ 
	SCFP(%0, #%1, %2)

#if defined MAX_PLAYERS
	#define MAX_COUNTDOWN MAX_PLAYERS
#else
	#define MAX_COUNTDOWN 500
#endif

#define INVALID_COUNTDOWN (-1)
#define IsValidCountdown(%0) (CountdownInfo[%0][cli_cntd_enabled])

//-----------------------------
//-------------------------------------------------
//-----------------------------

enum
{
	GAMETEXT // 0
	MESSAGE // 1
	TEXTDRAW1 // 2
	TEXTDRAW2 // 3
}

enum Countdown_Informations
{
	cli_cntd_Playerid,
	cli_cntd_Time,
	cli_cntd_Timer,
	PlayerText:cli_cntd_Textdraw,
	bool:cli_cntd_enabled
}

//-----------------------------
//-------------------------------------------------
//-----------------------------

new 
	CountdownInfo[MAX_COUNTDOWN][Countdown_Informations];

static stock
	cli_cntd_Name[MAX_COUNTDOWN][32 char],
	cli_cntd_Text[MAX_COUNTDOWN][128 char];

//-----------------------------
//-------------------------------------------------
//-----------------------------
	
stock SCFP(playerid, function[], time, text[], type, bool:sound = false)
{
	new
		l = strlen(text);

	if(1 > time || time > 999) return INVALID_COUNTDOWN;
	if(isnull(text) || l > 120) return INVALID_COUNTDOWN;
	if(type == TEXTDRAW1 && l > 60) return INVALID_COUNTDOWN;
	if(type == TEXTDRAW2 && l > 22) return INVALID_COUNTDOWN;
	
	new 
		p = strfind(text, "[XX]");
	
	if(p == -1) return INVALID_COUNTDOWN;
	
	new
		countdownid;
		
	while(countdownid++ < MAX_COUNTDOWN)
		if(!IsValidCountdown(countdownid)) break;

	if(countdownid == MAX_COUNTDOWN) return INVALID_COUNTDOWN;
	
	#if defined OnPlayerCountdownStarted
		OnPlayerCountdownStarted(playerid, countdownid, time);
	#endif
	
	new 
		str[128];
		
	strins(str, text, 0), strdel(str, p, p+4);
	
	strpack(cli_cntd_Name[countdownid], function);
	strpack(cli_cntd_Text[countdownid], str);
	CountdownInfo[countdownid][cli_cntd_Playerid] = playerid;
	CountdownInfo[countdownid][cli_cntd_Time] = time;
	CountdownInfo[countdownid][cli_cntd_enabled] = true;
	
	new
		str2[4];
		
	valstr(str2, time), strins(str, str2, p);
	
	if(sound) PlayerPlaySound(playerid, 1056, 0, 0, 0);
	
	switch(type)
	{
		case GAMETEXT: GameTextForPlayer(playerid, str, 1100, 6);
		case MESSAGE: SendClientMessage(playerid, -1, str);
		case TEXTDRAW1:
		{
			CountdownInfo[countdownid][cli_cntd_Textdraw] = CreatePlayerTextDraw(playerid, 322.000000, 427.000000, str);
			PlayerTextDrawAlignment(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 2);
			PlayerTextDrawBackgroundColor(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 255);
			PlayerTextDrawFont(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 1);
			PlayerTextDrawLetterSize(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 0.500000, 2.000000);
			PlayerTextDrawColor(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], -1);
			PlayerTextDrawSetOutline(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 0);
			PlayerTextDrawSetProportional(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 1);
			PlayerTextDrawSetShadow(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 0);
			PlayerTextDrawUseBox(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 1);
			PlayerTextDrawBoxColor(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 255);
			PlayerTextDrawTextSize(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 0.000000, 640.000000);				
			PlayerTextDrawShow(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw]);
		}
		case TEXTDRAW2:
		{
			CountdownInfo[countdownid][cli_cntd_Textdraw] = CreatePlayerTextDraw(playerid, 315.000000, 153.000000, str);
			PlayerTextDrawAlignment(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 2);
			PlayerTextDrawBackgroundColor(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 255);
			PlayerTextDrawFont(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 1);
			PlayerTextDrawLetterSize(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 1.040000, 13.300001);
			PlayerTextDrawColor(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], -1);
			PlayerTextDrawSetOutline(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 0);
			PlayerTextDrawSetProportional(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 1);
			PlayerTextDrawSetShadow(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 1);
			PlayerTextDrawUseBox(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 1);
			PlayerTextDrawBoxColor(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 255);
			PlayerTextDrawTextSize(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], 0.000000, 657.000000);
			PlayerTextDrawShow(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw]);
		}		
	}
	
	CountdownInfo[countdownid][cli_cntd_Timer] = SetTimerEx("cli_cntd_TimerPCNTD", 1000, true, "ddddd", playerid, countdownid, p, type, sound);
	
	return countdownid;
}

stock StopCountdown(countdownid, type=-1)
{
	if(!IsValidCountdown(countdownid)) return 0;
	
	switch(type)
	{
		case TEXTDRAW1, TEXTDRAW2: PlayerTextDrawDestroy(CountdownInfo[countdownid][cli_cntd_Playerid], CountdownInfo[countdownid][cli_cntd_Textdraw]);
	}
	
	KillTimer(CountdownInfo[countdownid][cli_cntd_Timer]);
	
	static 
		null[Countdown_Informations];
		
	CountdownInfo[countdownid] = null;
	return 1;
}

//-----------------------------
//-------------------------------------------------
//-----------------------------

forward cli_cntd_TimerPCNTD(playerid, countdownid, p, type, sound);
public cli_cntd_TimerPCNTD(playerid, countdownid, p, type, sound)
{
	if(CountdownInfo[countdownid][cli_cntd_Time] == 0)
	{				
		StopCountdown(countdownid);
		
		PlayerPlaySound(playerid, 1057, 0, 0, 0);
		
		new
		    func[40] = "pcntd_";
		
		strcat(func, cli_cntd_Name[countdownid]);
		
		#if defined OnPlayerCountdownFinished
			OnPlayerCountdownFinished(playerid, countdownid);
		#endif
		
		if(funcidx(func) != -1)
			CallLocalFunction(func, "d", playerid);
		
		return 1;
	}
	
	CountdownInfo[countdownid][cli_cntd_Time]--;
	
	new
		str[128],
		str2[4];
	
	strcat(str, cli_cntd_Text[countdownid]);
	valstr(str2, CountdownInfo[countdownid][cli_cntd_Time]), strins(str, str2, p);
	
	if(sound) PlayerPlaySound(playerid, 1056, 0, 0, 0);
	
	switch(type)
	{
		case GAMETEXT: GameTextForPlayer(playerid, str, 1100, 6);
		case MESSAGE: SendClientMessage(playerid, -1, str);
		case TEXTDRAW1, TEXTDRAW2: PlayerTextDrawSetString(playerid, CountdownInfo[countdownid][cli_cntd_Textdraw], str);
	}
	
	return 1;
}

//-----------------------------
//-------------------------------------------------
//-----------------------------

#if defined OnPlayerCountdownStarted
	forward OnPlayerCountdownStarted(playerid, countdownid, time);
#endif

#if defined OnPlayerCountdownFinished
	forward OnPlayerCountdownFinished(playerid, countdownid);
#endif 