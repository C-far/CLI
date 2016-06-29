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
 *   @Version:     0.2		      *
 *   @Released:    30/06/2016     *
 *                                *
 **********************************/

//-----------------------------
//-------------------------------------------------
//-----------------------------
 
#if defined _cli_uid_included
	#endinput
#endif	
#define _cli_uid_included

//-----------------------------
//-------------------------------------------------
//-----------------------------

/*

	native IsUIDValid(uid);
	native GenerateUID(playerid);
	native GetPlayerUID(playerid);
	native GetPlayerIDByUID(uid);


	INVALID_UID = -1
	
*/

//-----------------------------
//-------------------------------------------------
//-----------------------------

#define INVALID_UID (-1)
#define IsUIDValid(%0) (GetPlayerIDByUID(%0) != INVALID_PLAYER_ID)

//-----------------------------
//-------------------------------------------------
//-----------------------------

static stock
	cli@uid[MAX_PLAYERS] = {INVALID_UID, ...};

//-----------------------------
//-------------------------------------------------
//-----------------------------

stock GenerateUID(playerid)
{
	if(!IsPlayerConnected(playerid)) return INVALID_UID;
	
	static
		uid;

	do uid = random(9999-1111)+1111;
	while(IsUIDValid(uid));
		
	cli@uid[playerid] = uid;
		
	return uid;
}

//-----------------------------

stock GetPlayerUID(playerid) return cli@uid[playerid];

//-----------------------------

stock GetPlayerIDByUID(uid)
{
	if(!(1111 <= uid <= 9999)) return INVALID_PLAYER_ID;
	
#if defined Iterator@Player
	foreach(new i : Player)
	{
#else
	for(new i = GetPlayerPoolSize(); i != -1; i--)
	{
		if(!IsPlayerConnected(i)) continue;
#endif
		if(cli@uid[i] == uid) return i;
	}

	return INVALID_PLAYER_ID;
}

//-----------------------------
//-------------------------------------------------
//-----------------------------

public OnPlayerConnect(playerid)
{
	GenerateUID(playerid);

	#if defined cli_uid_OPC
		return cli_uid_OPC(playerid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect cli_uid_OPC

#if defined cli_uid_OPC
	forward cli_uid_OPC(playerid);
#endif

//-----------------------------

public OnPlayerDisconnect(playerid, reason)
{
	cli@uid[playerid] = INVALID_UID;

	#if defined cli_uid_OPD
		return cli_uid_OPD(playerid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect cli_uid_OPD

#if defined cli_uid_OPD
	forward cli_uid_OPD(playerid);
#endif 