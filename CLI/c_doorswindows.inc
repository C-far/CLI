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
 *   @Version:     0.3		      *
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

enum
{
	WINDOW_DRIVER // 0
	WINDOW_PASSENGER // 1
	WINDOW_BACKLEFT // 2
	WINDOW_BACKRIGHT // 3
}

enum
{
	DOOR_DRIVER // 0
	DOOR_PASSENGER // 1
	DOOR_BACKLEFT // 2
	DOOR_BACKRIGHT // 3
}

//-----------------------------
//-------------------------------------------------
//-----------------------------

#define IsOpenWindow(%0,%1) (cli_dw_windows[%0]{%1})
#define IsOpenDoor(%0,%1) (cli_dw_doors[%0]{%1})

//-----------------------------
//-------------------------------------------------
//-----------------------------

new
	bool:cli_dw_windows[MAX_VEHICLES][4 char],
	bool:cli_dw_doors[MAX_VEHICLES][4 char];

//-----------------------------
//-------------------------------------------------
//-----------------------------	
	
stock UpdateVehicleWindow(vehicleid, window)
{
	#if defined OnVehicleWindowClosed || defined OnVehicleWindowOpened
		if(IsOpenDoor(vehicleid, window))
			#if defined OnVehicleWindowClosed
				OnVehicleWindowClosed(vehicleid, window);
			#elseif
				{}
			#endif
			
		else
			#if defined OnVehicleWindowOpened
				OnVehicleWindowOpened(vehicleid, window);
			#elseif
				{}
			#endif
	#endif
	
	cli_dw_windows[vehicleid]{window} = !IsOpenWindow(vehicleid, window) ? true : false;
	
	return SetVehicleParamsCarWindows(vehicleid, cli_dw_windows[vehicleid]{0}, cli_dw_windows[vehicleid]{1}, cli_dw_windows[vehicleid]{2}, cli_dw_windows[vehicleid]{3});
}

stock UpdateVehicleDoor(vehicleid, door)
{
	#if defined OnVehicleDoorClosed || defined OnVehicleDoorOpened
		if(IsOpenDoor(vehicleid, door)) 
			#if defined OnVehicleDoorClosed
				OnVehicleDoorClosed(vehicleid, door);
			#elseif
				{}
			#endif
		else
			#if defined OnVehicleDoorOpened
				OnVehicleDoorOpened(vehicleid, door);
			#elseif
				{}
			#endif
	#endif
		
	cli_dw_doors[vehicleid]{door}= !IsOpenDoor(vehicleid, door) ? true : false;
	
	return SetVehicleParamsCarDoors(vehicleid, cli_dw_doors[vehicleid]{0}, cli_dw_doors[vehicleid]{1}, cli_dw_doors[vehicleid]{2}, cli_dw_doors[vehicleid]{3});
}

//-----------------------------
//-------------------------------------------------
//-----------------------------

#if defined OnVehicleWindowOpened
	forward OnVehicleWindowOpened(vehicleid, window);
#endif

#if defined OnVehicleWindowClosed
	forward OnVehicleWindowClosed(vehicleid, window);
#endif

#if defined OnVehicleDoorOpened
	forward OnVehicleDoorOpened(vehicleid, door);
#endif
	
#if defined OnVehicleDoorClosed
	forward OnVehicleDoorClosed(vehicleid, door);
#endif 