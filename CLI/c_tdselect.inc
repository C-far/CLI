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
 *   @Version:     0.6		      *
 *   @Released:    30/06/2016     *
 *                                *
 **********************************/

//-----------------------------
//-------------------------------------------------
//-----------------------------

#if defined cli_tdselect_included
	#endinput
#endif
#define cli_tdselect_included

//-----------------------------
//-------------------------------------------------
//-----------------------------

#define MAXTD 500
#define MAXPTD 2000

//-----------------------------

#define TDS:%0(%1) \
	forward tds_%0(%1); public tds_%0(%1)

//-----------------------------
	
#define PTDS:%0(%1) \
	forward ptds_%0(%1); public ptds_%0(%1)	

//-----------------------------	
	
#define cli_TextDrawSetSelectable(%0,%1,%2) \ 
	TDSS(%0, bool:%1, #%2)	

//-----------------------------	
	
#define cli_PlayerTextDrawSetSelectable(%0,%1,%2,%3) \ 
	PTDSS(%0, %1, bool:%2, #%3)		
	
//-----------------------------
//-------------------------------------------------
//-----------------------------	
	
static stock
	cli_tdselect_Name[MAXTD][32 char],
	bool:cli_tdselect_Used[MAXTD char],
	
	cli_ptdselect_Name[MAXPTD][32 char],
	bool:cli_ptdselect_Used[MAXPTD char],
	
	bool:cli_canceltextdraw[MAX_PLAYERS char];
	
//-----------------------------
//-------------------------------------------------
//-----------------------------	
	
stock TDSS(Text:text, bool:set, function[])
{
	if(set) strpack(cli_tdselect_Name[_:text], function);
	cli_tdselect_Used{_:text} = set;
	return TextDrawSetSelectable(text, set);
}

//-----------------------------

stock PTDSS(playerid, PlayerText:text, bool:set, function[])
{
	if(set) strpack(cli_ptdselect_Name[_:text], function);
	cli_ptdselect_Used{_:text} = set;
	return PlayerTextDrawSetSelectable(playerid, text, set);
}

//-----------------------------

stock cli_tds_CancelSelectTextDraw(playerid)
{
	cli_canceltextdraw{playerid} = true;

	return CancelSelectTextDraw(playerid);
}

#if defined _ALS_CancelSelectTextDraw
	#undef CancelSelectTextDraw
#else
	#define _ALS_CancelSelectTextDraw
#endif
#define CancelSelectTextDraw cli_tds_CancelSelectTextDraw

//-----------------------------
//-------------------------------------------------
//-----------------------------

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{		
	if(_:clickedid == INVALID_TEXT_DRAW)
	{
		if(cli_canceltextdraw{playerid}) 
		{
			cli_canceltextdraw{playerid} = false; 
			
			#if defined tds_OnPlayerClickTextDraw
				return tds_OnPlayerClickTextDraw(playerid, clickedid);
			#else
				return 1;
			#endif
		}
		
		#if defined OnPlayerCancelSelectByEchap
			OnPlayerCancelSelectByEchap(playerid);
		#endif
		
		#if defined tds_OnPlayerClickTextDraw
			return tds_OnPlayerClickTextDraw(playerid, clickedid);
		#else
			return 1;
		#endif
	}
	
	if(_:clickedid >= MAXTD) return SendClientMessage(playerid, -1, "Include cli_tdselect : Il faut augmenter la valeur de MAXTD");
	
	if(cli_tdselect_Used{_:clickedid})
	{
		new
			func[40] = "tds_";

		strcat(func, cli_tdselect_Name[_:clickedid]);
		
		if(funcidx(func) != -1)
			CallLocalFunction(func, "d", playerid);
	}
	
	#if defined tds_OnPlayerClickTextDraw
		return tds_OnPlayerClickTextDraw(playerid, clickedid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerClickTextDraw
	#undef OnPlayerClickTextDraw
#else
	#define _ALS_OnPlayerClickTextDraw
#endif

#define OnPlayerClickTextDraw tds_OnPlayerClickTextDraw
 
#if defined tds_OnPlayerClickTextDraw
	forward tds_OnPlayerClickTextDraw(playerid, Text:clickedid);
#endif

//-----------------------------

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
	if(_:playertextid == INVALID_TEXT_DRAW)
	{
		if(cli_canceltextdraw{playerid}) 
		{
			cli_canceltextdraw{playerid} = false; 
			
			#if defined ptds_OPCPT
				return ptds_OPCPT(playerid, playertextid);
			#else
				return 1;
			#endif
		}
		
		#if defined OnPlayerCancelSelectByEchap
			OnPlayerCancelSelectByEchap(playerid);
		#endif
		
		#if defined ptds_OPCPT
			return ptds_OPCPT(playerid, playertextid);
		#else
			return 1;
		#endif
	}
	
	if(_:playertextid >= MAXTD) return SendClientMessage(playerid, -1, "Include cli_tdselect : Il faut augmenter la valeur de MAXPTD");

	if(cli_ptdselect_Used{_:playertextid})
	{
		new
			func[40] = "ptds_";

		strcat(func, cli_ptdselect_Name[_:playertextid]);
		
		if(funcidx(func) != -1)
			CallLocalFunction(func, "d", playerid);
	}
	
	#if defined ptds_OPCPT
		return ptds_OPCPT(playerid, playertextid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerClickPlayerTD
	#undef OnPlayerClickPlayerTextDraw
#else
	#define _ALS_OnPlayerClickPlayerTD
#endif

#define OnPlayerClickPlayerTextDraw ptds_OPCPT
 
#if defined ptds_OPCPT
	forward ptds_OPCPT(playerid, PlayerText:playertextid);
#endif

//-----------------------------
//-------------------------------------------------
//-----------------------------

#if defined OnPlayerCancelSelectByEchap
	forward OnPlayerCancelSelectByEchap(playerid);
#endif 