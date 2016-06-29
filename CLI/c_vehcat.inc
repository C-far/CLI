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

#if defined _cli_vehcat_included
	#endinput
#endif	
#define _cli_vehcat_included

//-----------------------------
//-------------------------------------------------
//-----------------------------

/*

	=== FUNCTIONS ===

	native IsModelAirplane(const modelid);
	native IsModelHelicopter(const modelid);
	native IsModelScooter(const modelid);
	native IsModelBicycle(const modelid);
	native IsModelMoto(const modelid);
	native IsModelQuad(const modelid);
	native IsModelTwoWheels(const modelid);
	native IsModelConvertible(const modelid);
	native IsModelSport(const modelid);
	native IsModelLowrider(const modelid);
	native IsModelPolice(const modelid);
	native IsModelMilitary(const modelid);
	native IsModelRescue(const modelid);
	native IsModelBoat(const modelid);
	native IsModelTrailer(const modelid);
	native IsModelTruck(const modelid);
	native IsModel4x4(const modelid);
	native IsModelRC(const modelid);

	native HasModelValidHood(const modelid);
	native HasModelValidBoot(const modelid);

	=== MACROS ===

	cli_veh_AIRPLANES - Using in -> switch YES, array YES.
	cli_veh_HELICOPTERS - Using in -> switch YES, array YES.
	cli_veh_SCOOTERS - Using in -> switch YES, array YES.
	cli_veh_BICYCLES - Using in -> switch YES, array YES.
	cli_veh_MOTOS - Using in -> switch YES, array YES.
	cli_veh_QUADS - Using in -> switch YES, array YES.
	cli_veh_TWOWHEELS - Using in -> switch YES, array YES.
	cli_veh_CONVERTIBLES - Using in -> switch YES, array YES.
	cli_veh_SPORTS - Using in -> switch YES, array YES.
	cli_veh_LOWRIDERS - Using in -> switch YES, array YES.
	cli_veh_POLICES - Using in -> switch YES, array YES.
	cli_veh_MILITARIES - Using in -> switch YES, array YES.
	cli_veh_RESCUES - Using in -> switch YES, array YES.
	cli_veh_BOATS - Using in -> switch YES, array YES.
	cli_veh_TRAILERS - Using in -> switch YES, array YES.
	cli_veh_TRUCKS - Using in -> switch YES, array YES.
	cli_veh_4X4 - Using in -> switch YES, array YES.
	cli_veh_RCS - Using in -> switch YES, array YES.
	
*/

//-----------------------------
//-------------------------------------------------
//-----------------------------

#define cli_veh_AIRPLANES 460, 476, 511, 512, 513, 519, 520, 553, 577, 592, 593

//--------------

stock IsModelAirplane(const modelid)
{
	switch(modelid)
	{
		case cli_veh_AIRPLANES: return true;
	}

	return false;
}
	
//-----------------------------

#define cli_veh_HELICOPTERS 417, 425, 447, 469, 487, 488, 497, 548, 563

//--------------

stock IsModelHelicopter(const modelid)
{
	switch(modelid)
	{
		case cli_veh_HELICOPTERS: return true;
	}

	return false;
}

//-----------------------------

#define cli_veh_SCOOTERS 448, 462

//--------------

stock IsModelScooter(const modelid)
{
	switch(modelid)
	{
		case cli_veh_SCOOTERS: return true;
	}

	return false;
}

//-----------------------------

#define cli_veh_BICYCLES 481, 509, 510

//--------------

stock IsModelBicycle(const modelid)
{
	switch(modelid)
	{
		case cli_veh_BICYCLES: return true;
	}

	return false;
}

//-----------------------------

#define cli_veh_MOTOS 461, 463, 468, 521, 522, 523, 581, 586

//--------------

stock IsModelMoto(const modelid)
{
	switch(modelid)
	{
		case cli_veh_MOTOS: return true;
	}

	return false;
}

//-----------------------------

#define cli_veh_QUADS 471

//--------------

stock IsModelQuad(const modelid)
{
	switch(modelid)
	{
		case cli_veh_QUADS: return true;
	}

	return false;
}

//-----------------------------

#define cli_veh_TWOWHEELS cli_veh_SCOOTERS, cli_veh_BICYCLES, cli_veh_MOTOS

//--------------

stock IsModelTwoWheels(const modelid)
{
	switch(modelid)
	{
		case cli_veh_TWOWHEELS: return true;
	}

	return false;
}

//-----------------------------

#define cli_veh_CONVERTIBLES 439, 480, 533, 555

//--------------

stock IsModelConvertible(const modelid)
{
	switch(modelid)
	{
		case cli_veh_CONVERTIBLES: return true;
	}

	return false;
}

//-----------------------------

#define cli_veh_SPORTS 402, 411, 415, 429, 451, 475, 477, 494, 496, 502, 503, 506, 541, 558, 559, 565, 587, 589, 602, 603

//--------------

stock IsModelSport(const modelid)
{
	switch(modelid)
	{
		case cli_veh_SPORTS: return true;
	}

	return false;
}

//-----------------------------

#define cli_veh_LOWRIDERS 412, 534, 535, 536, 566, 567, 575, 576

//--------------

stock IsModelLowrider(const modelid)
{
	switch(modelid)
	{
		case cli_veh_LOWRIDERS: return true;
	}

	return false;
}

//-----------------------------

#define cli_veh_POLICES 427, 430, 490, 497, 596, 597, 598, 599, 523, 528, 601

//-------------

stock IsModelPolice(const modelid)
{
	switch(modelid)
	{
		case cli_veh_POLICES: return true;
	}

	return false;
}

//-----------------------------

#define cli_veh_MILITARIES 425, 432, 470, 520, 548

//--------------

stock IsModelMilitary(const modelid)
{
	switch(modelid)
	{
		case cli_veh_MILITARIES: return true;
	}

	return false;
}

//-----------------------------

#define cli_veh_RESCUES 407, 416, 544, 563

//--------------

stock IsModelRescue(const modelid)
{
	switch(modelid)
	{
		case cli_veh_RESCUES: return true;
	}

	return false;
}

//-----------------------------

#define cli_veh_BOATS 430, 446, 452, 453, 454, 472, 473, 484, 493, 595

//--------------

stock IsModelBoat(const modelid)
{
	switch(modelid)
	{
		case cli_veh_BOATS: return true;
	}

	return false;
}


//-----------------------------

#define cli_veh_TRAILERS 435, 450, 584, 591, 606, 607, 608, 610, 611

//--------------

stock IsModelTrailer(const modelid)
{
	switch(modelid)
	{
		case cli_veh_TRAILERS: return true;
	}

	return false;
}

//-----------------------------

#define cli_veh_TRUCKS 403, 406, 407, 408, 414, 416, 423, 427, 428, 433, 443, 455, 456, 498, 499, 514, 515, 524, 544, 573, 578, 609

//--------------

stock IsModelTruck(const modelid)
{
	switch(modelid)
	{
		case cli_veh_TRUCKS: return true;
	}

	return false;
}

//-----------------------------

#define cli_veh_4X4 400, 422, 444, 479, 489, 490, 495, 505, 554, 556, 557, 579

//--------------

stock IsModel4x4(const modelid)
{
	switch(modelid)
	{
		case cli_veh_4X4: return true;
	}

	return false;
}

//-----------------------------

#define cli_veh_RCS 441, 464, 465, 501, 564, 594

//--------------

stock IsModelRC(const modelid)
{
	switch(modelid)
	{
		case cli_veh_RCS: return true;
	}

	return false;
}


//-----------------------------

// HOOD (EN) -> CAPOT (FR)

stock HasModelValidHood(const modelid)
{
	static const 
			hoods[] = 
					{
						1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1,
						1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0
					};

	return (400 <= modelid <= 611 ? hoods[modelid-400] : 0);
}


//-----------------------------

// BOOT/TRUNK (EN) -> COFFRE (FR)

stock HasModelValidBoot(const modelid)
{
	static const 
			boots[] = 
					{
						1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0,
						1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0
					};
					
	return (400 <= modelid <= 611 ? boots[modelid-400] : 0);
}