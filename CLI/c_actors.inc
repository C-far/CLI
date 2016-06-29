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

#if defined _cli_actors_included
	#endinput
#endif	
#define _cli_actors_included

//-----------------------------
//-------------------------------------------------
//-----------------------------

#if !defined IsValidSkin
	#define IsValidSkin(%0) (1 <= %0 <= 311 && %0 != 74)
#endif

//-----------------------------
//-------------------------------------------------
//-----------------------------

/*
	native SetActorSkin(actorid, skinid);
	native GetActorSkin(actorid);

	native GetActorDistanceFromPoint(actorid, Float:x, Float:y, Float:z);
	native GetNearestActor(playerid, Float:range);
*/

//-----------------------------
//-------------------------------------------------
//-----------------------------	

enum cli_Actor_Informations
{
	cli_aModelid,
	Float:cli_aPos[3],
	Float:cli_aAngle
}

static
	cli_aInfo[MAX_ACTORS][cli_Actor_Informations];

//-----------------------------
//-------------------------------------------------
//-----------------------------	

stock cli_CreateActor(modelid, Float:x, Float:y, Float:z, Float:Rotation)
{
	if(!IsValidSkin(modelid)) modelid = 0;

	new
		actorid = CreateActor(modelid, x, y, z, Rotation);

	cli_aInfo[actorid][cli_aModelid] = modelid;
	cli_aInfo[actorid][cli_aPos][0] = x;
	cli_aInfo[actorid][cli_aPos][1] = y;
	cli_aInfo[actorid][cli_aPos][2] = z;
	cli_aInfo[actorid][cli_aAngle] = Rotation;
	
	return actorid;
}

#if defined _ALS_CreateActor
    #undef CreateActor
#else
    #define _ALS_CreateActor
#endif
#define CreateActor cli_CreateActor

//-----------------------------

stock SetActorSkin(actorid, skinid)
{
	if(!IsValidSkin(skinid)) skinid = 0;

	new
		ActorToDestroy[MAX_ACTORS],
		i = 0,
		Float:pos[3];
		
	GetActorPos(actorid, pos[0], pos[1], pos[2]);	
		
	DestroyActor(actorid);
		
	do 
	{
		ActorToDestroy[i] = CreateActor(skinid, cli_aInfo[actorid][cli_aPos][0], cli_aInfo[actorid][cli_aPos][1], cli_aInfo[actorid][cli_aPos][2], cli_aInfo[actorid][cli_aAngle]);
		
		if(ActorToDestroy[i] != actorid) SetActorPos(ActorToDestroy[i], cli_aInfo[ActorToDestroy[i]][cli_aPos][0]+1000, cli_aInfo[ActorToDestroy[i]][cli_aPos][1], cli_aInfo[ActorToDestroy[i]][cli_aPos][2]);
		
		i++;
	}
	while(ActorToDestroy[i-1] != actorid);		
		
	i--;	
		
	for(new j = 0; j < i; j++)
		DestroyActor(ActorToDestroy[j]);
		
	SetActorPos(actorid, pos[0], pos[1], pos[2]);	
		
	return 1;
}

//-----------------------------

stock GetActorSkin(actorid)
	return (!IsValidActor(actorid) ? 0 : cli_aInfo[actorid][cli_aModelid]);

//-----------------------------

stock GetActorDistanceFromPoint(actorid, Float:x, Float:y, Float:z)
{
	static
		Float:pos[3];
		
	GetActorPos(actorid, pos[0], pos[1], pos[2]);
	
	return VectorSize(x-pos[0], y-pos[1], z-pos[2]);
}

//-----------------------------

stock GetNearestActor(playerid, Float:range)
{
	static
		Float:pos[3];
	
	new
		Float:distance,
		Float:precedent_distance = range + 1.0,
		precedent = -1;
		
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	
    for(new actorid = 0; actorid < MAX_ACTORS; actorid++)
    {
		if(!IsValidActor(actorid)) continue;
		if(!IsActorStreamedIn(actorid, playerid)) continue;
	
        distance = GetActorDistanceFromPoint(actorid, pos[0], pos[1], pos[2]);

        if(distance <= range && distance <= precedent_distance)
        {
            precedent = actorid;
            precedent_distance = distance;
        }
    }

	return precedent;
}