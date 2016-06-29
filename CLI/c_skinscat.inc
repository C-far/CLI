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

#if defined _cli_skinscat_included
	#endinput
#endif	
#define _cli_skinscat_included

//-----------------------------
//-------------------------------------------------
//-----------------------------

/*

	=== FUNCTIONS ===

	native IsValidSkin(const skinid);

	native IsSkinWhite(const skinid);
	native IsSkinBlack(const skinid);
	native IsSkinHispanic(const skinid);
	native IsSkinChinese(const skinid);

	native IsSkinMale(const skinid);
	native IsSkinFemale(const skinid);

	native IsSkinBeach(const skinid);
	native IsSkinAgriculture(const skinid);
	native IsSkinWhore(const skinid);
	native IsSkinSportive(const skinid);
	native IsSkinConstruction(const skinid);

	native IsSkinGrove(const skinid);
	native IsSkinBallas(const skinid);
	native IsSkinAztecas(const skinid);
	native IsSkinVagos(const skinid);
	native IsSkinDaNang(const skinid);
	native IsSkinRifa(const skinid);
	native IsSkinBiker(const skinid);

	native IsSkinGang(const skinid);

	native IsSkinTriad(const skinid);
	native IsSkinRussianMafia(const skinid);
	native IsSkinItalianMafia(const skinid);

	native IsSkinMafia(const skinid);

	native IsSkinSecurity(const skinid);
	native IsSkinSheriff(const skinid);
	native IsSkinPolice(const skinid);
	native IsSkinSWAT(const skinid);
	native IsSkinFBI(const skinid);
	native IsSkinArmy(const skinid);
	native IsSkinFireFighter(const skinid);
	native IsSkinParamedic(const skinid);

	native IsSkinPublicService(const skinid);

	=== MACROS ===

	cli_skin_WHITE - Using in -> switch YES, array YES with the Zeex's PAWN Compiler otherwise NO.
	cli_skin_BLACK - Using in -> switch YES, array YES.
	cli_skin_HISPANIC - Using in -> switch YES, array YES.
	cli_skin_CHINESE - Using in -> switch YES, array YES.

	cli_skin_MALE - Using in -> switch YES, array YES with the Zeex's PAWN Compiler otherwise NO.
	cli_skin_FEMALE - Using in -> switch YES, array YES.

	cli_skin_BEACH - Using in -> switch YES, array YES.
	cli_skin_AGRICULTURE - Using in -> switch YES, array YES.
	cli_skin_WHORE - Using in -> switch YES, array YES.
	cli_skin_SPORTIVE - Using in -> switch YES, array YES.
	cli_skin_CONSTRUCTION - Using in -> switch YES, array YES.

	cli_skin_GROVE - Using in -> switch YES, array YES.
	cli_skin_BALLAS - Using in -> switch YES, array YES.
	cli_skin_AZTECAS - Using in -> switch YES, array YES.
	cli_skin_VAGOS - Using in -> switch YES, array YES.
	cli_skin_DANANG - Using in -> switch YES, array YES.
	cli_skin_RIFA - Using in -> switch YES, array YES.
	cli_skin_BIKER - Using in -> switch YES, array YES.

	cli_skin_GANG - Using in -> switch YES, array YES.

	cli_skin_TRIAD - Using in -> switch YES, array YES.
	cli_skin_RUSSIANMAFIA - Using in -> switch YES, array YES.
	cli_skin_ITALIANMAFIA - Using in -> switch YES, array YES.

	cli_skin_MAFIA - Using in -> switch YES, array YES.

	cli_skin_SECURITY - Using in -> switch YES, array YES.
	cli_skin_SHERIFF - Using in -> switch YES, array YES.
	cli_skin_POLICE - Using in -> switch YES, array YES.
	cli_skin_SWAT - Using in -> switch YES, array YES.
	cli_skin_FBI - Using in -> switch YES, array YES.
	cli_skin_ARMY - Using in -> switch YES, array YES.
	cli_skin_FIREFIGHTER - Using in -> switch YES, array YES.
	cli_skin_PARAMEDIC - Using in -> switch YES, array YES.

	cli_skin_PUBLICSERVICE - Using in -> switch YES, array YES.
	
	With the macro "cli_ARRAY_SKINS" :
	
	cli_skins_white
	cli_skins_black
	cli_skins_hispanic
	cli_skins_chinese
	
	cli_skins_male
	cli_skins_female
	
	cli_skins_beach
	cli_skins_agriculture
	cli_skins_whore
	cli_skins_sportive
	cli_skins_construction
	
	cli_skins_grove
	cli_skins_ballas
	cli_skins_aztecas
	cli_skins_vagos
	cli_skins_danang
	cli_skins_rifa
	cli_skins_biker
	
	cli_skins_gang
	
	cli_skins_triad
	cli_skins_russianmafia
	cli_skins_italianmafia
	
	cli_skins_mafia
	
	cli_skins_security
	cli_skins_sheriff
	cli_skins_police
	cli_skins_swat
	cli_skins_fbi
	cli_skins_army
	cli_skins_firefighter
	cli_skins_paramedic
	
	cli_skins_publicservice	
	
	With the macro "cli_MAX_SKINS" :

	MAX_SKINS_WHITE
	MAX_SKINS_BLACK
	MAX_SKINS_HISPANIC
	MAX_SKINS_CHINESE
	
	MAX_SKINS_MALE
	MAX_SKINS_FEMALE
	
	MAX_SKINS_BEACH
	MAX_SKINS_AGRICULTURE
	MAX_SKINS_WHORE
	MAX_SKINS_SPORTIVE
	MAX_SKINS_CONSTRUCTION
	
	MAX_SKINS_GROVE
	MAX_SKINS_BALLAS
	MAX_SKINS_AZTECAS
	MAX_SKINS_VAGOS
	MAX_SKINS_DANANG
	MAX_SKINS_RIFA
	MAX_SKINS_BIKER
	
	MAX_SKINS_GANG
	
	MAX_SKINS_TRIAD
	MAX_SKINS_RUSSIANMAFIA
	MAX_SKINS_ITALIANMAFIA
	
	MAX_SKINS_MAFIA
	
	MAX_SKINS_SECURITY
	MAX_SKINS_SHERIFF
	MAX_SKINS_POLICE
	MAX_SKINS_SWAT
	MAX_SKINS_FBI
	MAX_SKINS_ARMY
	MAX_SKINS_FIREFIGHTER
	MAX_SKINS_PARAMEDIC
	
	MAX_SKINS_PUBLICSERVICE
	
*/

//-----------------------------
//-------------------------------------------------
//-----------------------------

#if !defined IsValidSkin
	#define IsValidSkin(%0) (1 <= %0 <= 311 && %0 != 74)
#endif

//-----------------------------



#if __Pawn == 0x030A
	#define cli_skin_WHITE 1,2,3,23,26,27,29,31,32,33,34,37,38,39,42,43,44,45,52,53,55,56,57,58,59,60,61,62,70,71,72,73,75,77,78,81,85,87,88,89,90,91,92,93,94,95,96,97,99,100,101,111,112,113,124,125,126,127,128,129,130,132,133,135,137,138,141,145,146,147,150,151,152,153,154,155,157,158,159,160,161,162,164,165,167,170,171,172,177,178,179,181,187,188,189,191,192,193,194,196,197,198,199,200,201,202,205,206,209,212,213,216,217,223,230,231,232,233,234,235,236,237,239,240,241,242,246,247,248,250,251,252,254,255,257,259,261,264,266,268,272,276,280,281,282,283,285,286,287,288,289,290,291,294,295,299,300,301,302,303,304,305,310,311
#else
	#define cli_skin_WHITE 1..3,23,26,27,29,31..34,37..39,42..45,52,53,55..57,59..62,58,70..73,75,77,78,81,85,87..97,99..101,111..113,124..130,132,133,135,137,138,141,145..147,150..154,155,157..162,164,165,167,170..172,177..179,181,187..189,191..194,196..202,205,206,209,212,213,216,217,223,230..237,239..242,246..248,250..252,254,255,257,259,261,264,266,268,272,276,280..283,285..291,294,295,299..305,310,311
#endif
	
stock IsSkinWhite(const skinid)
{
	switch(skinid)
	{
		case cli_skin_WHITE: return true;
	}
	
	return false;
}

//-----------------------------

#define cli_skin_BLACK 0,4,5,6,7,9,10,11,12,13,14,15,16,17,18,19,20,21,22,24,25,28,36,40,41,50,51,54,63,64,65,66,67,69,76,79,80,82,83,84,86,102,103,104,105,106,107,131,134,136,139,140,142,143,144,148,149,156,163,166,168,176,180,182,183,185,190,195,207,211,214,215,218,219,220,221,222,238,243,244,245,249,253,256,260,262,265,269,270,271,274,277,278,284,293,296,297,298,306,307,308,309
	
stock IsSkinBlack(const skinid)
{
	switch(skinid)
	{
		case cli_skin_BLACK: return true;
	}
	
	return false;
}

//-----------------------------

#define cli_skin_HISPANIC 8,30,35,46,47,48,98,108,109,110,114,115,116,173,174,175,184,258,267,273,275,279,292

stock IsSkinHispanic(const skinid)
{
	switch(skinid)
	{
		case cli_skin_HISPANIC: return true;
	}
	
	return false;
}

//-----------------------------

#define cli_skin_CHINESE 49,68,117,118,119,120,121,122,123,169,186,203,204,208,210,224,225,226,227,228,229,263

stock IsSkinChinese(const skinid)
{
	switch(skinid)
	{
		case cli_skin_CHINESE: return true;
	}
	
	return false;
}

//-----------------------------

#if __Pawn == 0x030A
	#define cli_skin_MALE 0,1,2,3,4,5,6,7,8,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,32,33,34,35,36,37,38,42,43,44,45,46,47,48,49,50,51,52,57,58,59,60,61,62,66,67,68,70,71,72,73,78,79,80,81,82,83,84,86,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,132,133,134,135,136,137,142,143,144,146,147,149,153,154,155,156,158,159,160,161,162,163,164,165,166,167,168,170,171,173,174,175,176,177,179,180,181,182,183,184,185,186,187,188,189,200,202,203,204,206,208,209,210,212,213,217,220,221,222,223,227,228,229,230,234,235,236,239,240,241,242,247,248,249,250,252,253,254,255,258,259,260,261,262,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,299,300,301
#else
	#define cli_skin_MALE 0..8,14..30,32..38,42..52,57..62,66..68,70..73,78..84,86,94..128,132..137,142..144,146,147,149,153..156,158..168,170,171,173..177,179..189,200,202..204,206,208..210,212,213,217,220..223,227..229,230,234..236,239..242,247..250,252..255,258..262,264..297,299..305,310,311
#endif
	
stock IsSkinMale(const skinid)
{
	switch(skinid)
	{
		case cli_skin_MALE: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_FEMALE 9,10,11,12,13,31,39,40,41,53,54,55,56,63,64,65,69,75,76,77,85,87,88,89,90,91,92,93,129,130,131,138,139,140,141,145,148,150,151,152,157,169,172,178,190,191,192,193,194,195,196,197,198,199,201,205,207,211,214,215,216,218,219,224,225,226,231,232,233,237,238,243,244,245,246,251,256,257,263,298,306,307,308,309
	
stock IsSkinFemale(const skinid)
{
	switch(skinid)
	{
		case cli_skin_FEMALE: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_BEACH 18,45,92,97,138,139,140,145,146,154,251

stock IsSkinBeach(const skinid)
{
	switch(skinid)
	{
		case cli_skin_BEACH: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_AGRICULTURE 31,32,33,34,128,129,130,131,132,133,157,158,159,160,161,162,196,197,198,199,200,201,202

stock IsSkinAgriculture(const skinid)
{
	switch(skinid)
	{
		case cli_skin_AGRICULTURE: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_WHORE 63,64,85,87,152,178,207,237,238,243,244,245,246,256,257

stock IsSkinWhore(const skinid)
{
	switch(skinid)
	{
		case cli_skin_WHORE: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_SPORTIVE 23,26,51,52,80,81,90,96,99,258,259

stock IsSkinSportive(const skinid)
{
	switch(skinid)
	{
		case cli_skin_SPORTIVE: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_CONSTRUCTION 16,27,260

stock IsSkinConstruction(const skinid)
{
	switch(skinid)
	{
		case cli_skin_CONSTRUCTION: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_GROVE 105,106,107

stock IsSkinGrove(const skinid)
{
	switch(skinid)
	{
		case cli_skin_GROVE: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_BALLAS 102,103,104

stock IsSkinBallas(const skinid)
{
	switch(skinid)
	{
		case cli_skin_BALLAS: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_AZTECAS 114,115,116

stock IsSkinAztecas(const skinid)
{
	switch(skinid)
	{
		case cli_skin_AZTECAS: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_VAGOS 108,109,110

stock IsSkinVagos(const skinid)
{
	switch(skinid)
	{
		case cli_skin_VAGOS: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_DANANG 121,122,123

stock IsSkinDaNang(const skinid)
{
	switch(skinid)
	{
		case cli_skin_DANANG: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_RIFA 173,174,175

stock IsSkinRifa(const skinid)
{
	switch(skinid)
	{
		case cli_skin_: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_BIKER 247,248,254

stock IsSkinBiker(const skinid)
{
	switch(skinid)
	{
		case cli_skin_BIKERS: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_GANG cli_skin_GROVE,cli_skin_BALLAS,cli_skin_AZTECAS,cli_skin_VAGOS,cli_skin_DANANG,cli_skin_RIFA,cli_skin_BIKER

stock IsSkinGang(const skinid)
{
	switch(skinid)
	{
		case cli_skin_GANG: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_TRIAD 117,118,120

stock IsSkinTriad(const skinid)
{
	switch(skinid)
	{
		case cli_skin_TRIAD: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_RUSSIANMAFIA 111,112,113

stock IsSkinRussianMafia(const skinid)
{
	switch(skinid)
	{
		case cli_skin_RUSSIANMAFIA: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_ITALIANMAFIA 124,125,126,127

stock IsSkinItalianMafia(const skinid)
{
	switch(skinid)
	{
		case cli_skin_ITALIANMAFIA: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_MAFIA cli_skin_TRIAD,cli_skin_RUSSIANMAFIA,cli_skin_ITALIANMAFIA

stock IsSkinMafia(const skinid)
{
	switch(skinid)
	{
		case cli_skin_MAFIA: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_SECURITY 163,164,165,166

stock IsSkinSecurity(const skinid)
{
	switch(skinid)
	{
		case cli_skin_SECURITY: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_SHERIFF 283,288

stock IsSkinSheriff(const skinid)
{
	switch(skinid)
	{
		case cli_skin_SHERIFF: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_SWAT 285
#define IsSkinSWAT(%0) (%0 == cli_skin_SWAT)

//-----------------------------

#define cli_skin_POLICE 71,280,281,282,284,cli_skin_SWAT,cli_skin_SHERIFF

stock IsSkinPolice(const skinid)
{
	switch(skinid)
	{
		case cli_skin_POLICE: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_FBI 286
#define IsSkinFBI(%0) (%0 == cli_skin_FBI)

//-----------------------------

#define cli_skin_ARMY 179,191,287

stock IsSkinArmy(const skinid)
{
	switch(skinid)
	{
		case cli_skin_ARMY: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_FIREFIGHTER 277,278,279

stock IsSkinFireFighter(const skinid)
{
	switch(skinid)
	{
		case cli_skin_FIREFIGHTER: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_PARAMEDIC 70,274,275,276

stock IsSkinParamedic(const skinid)
{
	switch(skinid)
	{
		case cli_skin_PARAMEDIC: return true;
	}
	
	return false;	
}

//-----------------------------

#define cli_skin_PUBLICSERVICE cli_skin_SECURITY,cli_skin_POLICE,cli_skin_FBI,cli_skin_ARMY,cli_skin_FIREFIGHTER,cli_skin_PARAMEDIC

stock IsSkinPublicService(const skinid)
{
	switch(skinid)
	{
		case cli_skin_PUBLICSERVICE: return true;
	}
	
	return false;	
}

//-----------------------------
//-------------------------------------------------
//-----------------------------

#if defined cli_ARRAY_SKINS

	stock const
		cli_skins_white[] = {cli_skin_WHITE},
		cli_skins_black[] = {cli_skin_BLACK},
		cli_skins_hispanic[] = {cli_skin_HISPANIC},
		cli_skins_chinese[] = {cli_skin_CHINESE},
		
		cli_skins_male[] = {cli_skin_MALE},
		cli_skins_female[] = {cli_skin_FEMALE},
		
		cli_skins_beach[] = {cli_skin_BEACH},
		cli_skins_agriculture[] = {cli_skin_AGRICULTURE},
		cli_skins_whore[] = {cli_skin_WHORE},
		cli_skins_sportive[] = {cli_skin_SPORTIVE},
		cli_skins_construction[] = {cli_skin_CONSTRUCTION},
		
		cli_skins_grove[] = {cli_skin_GROVE},
		cli_skins_ballas[] = {cli_skin_BALLAS},
		cli_skins_aztecas[] = {cli_skin_AZTECAS},
		cli_skins_vagos[] = {cli_skin_VAGOS},
		cli_skins_danang[] = {cli_skin_DANANG},
		cli_skins_rifa[] = {cli_skin_RIFA},
		cli_skins_biker[] = {cli_skin_BIKER},
		
		cli_skins_gang[] = {cli_skin_GANG},
		
		cli_skins_triad[] = {cli_skin_TRIAD},
		cli_skins_russianmafia[] = {cli_skin_RUSSIANMAFIA},
		cli_skins_italianmafia[] = {cli_skin_ITALIANMAFIA},
		
		cli_skins_mafia[] = {cli_skin_MAFIA},
		
		cli_skins_security[] = {cli_skin_SECURITY},
		cli_skins_sheriff[] = {cli_skin_SHERIFF},
		cli_skins_police[] = {cli_skin_POLICE},
		cli_skins_swat[] = {cli_skin_SWAT},
		cli_skins_fbi[] = {cli_skin_FBI},
		cli_skins_army[] = {cli_skin_ARMY},
		cli_skins_firefighter[] = {cli_skin_FIREFIGHTER},
		cli_skins_paramedic[] = {cli_skin_PARAMEDIC},
		
		cli_skins_publicservice[] = {cli_skin_PUBLICSERVICE};
	
	#if defined cli_MAX_SKINS
	
		#define MAX_SKINS_WHITE (sizeof(cli_skins_white))
		#define MAX_SKINS_BLACK (sizeof(cli_skins_black))
		#define MAX_SKINS_HISPANIC (sizeof(cli_skins_hispanic))
		#define MAX_SKINS_CHINESE (sizeof(cli_skins_chinese))
		
		#define MAX_SKINS_MALE (sizeof(cli_skins_male))
		#define MAX_SKINS_FEMALE (sizeof(cli_skins_female))
		
		#define MAX_SKINS_BEACH (sizeof(cli_skins_beach))
		#define MAX_SKINS_AGRICULTURE (sizeof(cli_skins_agriculture))
		#define MAX_SKINS_WHORE (sizeof(cli_skins_whore))
		#define MAX_SKINS_SPORTIVE (sizeof(cli_skins_sportive))
		#define MAX_SKINS_CONSTRUCTION (sizeof(cli_skins_construction))
		
		#define MAX_SKINS_GROVE (sizeof(cli_skins_grove))
		#define MAX_SKINS_BALLAS (sizeof(cli_skins_ballas))
		#define MAX_SKINS_AZTECAS (sizeof(cli_skins_aztecas))
		#define MAX_SKINS_VAGOS (sizeof(cli_skins_vagos))
		#define MAX_SKINS_DANANG (sizeof(cli_skins_danang))
		#define MAX_SKINS_RIFA (sizeof(cli_skins_rifa))
		#define MAX_SKINS_BIKER (sizeof(cli_skins_biker))
		
		#define MAX_SKINS_GANG (sizeof(cli_skins_gang))
		
		#define MAX_SKINS_TRIAD (sizeof(cli_skins_triad))
		#define MAX_SKINS_RUSSIANMAFIA (sizeof(cli_skins_russianmafia))
		#define MAX_SKINS_ITALIANMAFIA (sizeof(cli_skins_italianmafia))
		
		#define MAX_SKINS_MAFIA (sizeof(cli_skins_mafia))
		
		#define MAX_SKINS_SECURITY (sizeof(cli_skins_security))
		#define MAX_SKINS_SHERIFF (sizeof(cli_skins_sheriff))
		#define MAX_SKINS_POLICE (sizeof(cli_skins_police))
		#define MAX_SKINS_SWAT (sizeof(cli_skins_swat))
		#define MAX_SKINS_FBI (sizeof(cli_skins_fbi))
		#define MAX_SKINS_ARMY (sizeof(cli_skins_army))
		#define MAX_SKINS_FIREFIGHTER (sizeof(cli_skins_firefighter))
		#define MAX_SKINS_PARAMEDIC (sizeof(cli_skins_paramedic))
		
		#define MAX_SKINS_PUBLICSERVICE (sizeof(cli_skins_publicservice))	
		
	#endif
	
#elseif defined cli_MAX_SKINS

	#define MAX_SKINS_WHITE (164)
	#define MAX_SKINS_BLACK (102)
	#define MAX_SKINS_HISPANIC (23)
	#define MAX_SKINS_CHINESE (22)
	
	#define MAX_SKINS_MALE (221)
	#define MAX_SKINS_FEMALE (84)
	
	#define MAX_SKINS_BEACH (11)
	#define MAX_SKINS_AGRICULTURE (23)
	#define MAX_SKINS_WHORE (15)
	#define MAX_SKINS_SPORTIVE (11)
	#define MAX_SKINS_CONSTRUCTION (3)
	
	#define MAX_SKINS_GROVE (3)
	#define MAX_SKINS_BALLAS (3)
	#define MAX_SKINS_AZTECAS (3)
	#define MAX_SKINS_VAGOS (3)
	#define MAX_SKINS_DANANG (3)
	#define MAX_SKINS_RIFA (3)
	#define MAX_SKINS_BIKER (3)
	
	#define MAX_SKINS_GANG (21)
	
	#define MAX_SKINS_TRIAD (3)
	#define MAX_SKINS_RUSSIANMAFIA (3)
	#define MAX_SKINS_ITALIANMAFIA (4)
	
	#define MAX_SKINS_MAFIA (10)
	
	#define MAX_SKINS_SECURITY (4)
	#define MAX_SKINS_SHERIFF (2)
	#define MAX_SKINS_POLICE (8)
	#define MAX_SKINS_SWAT (1)
	#define MAX_SKINS_FBI (1)
	#define MAX_SKINS_ARMY (3)
	#define MAX_SKINS_FIREFIGHTER (3)
	#define MAX_SKINS_PARAMEDIC (4)
	
	#define MAX_SKINS_PUBLICSERVICE (23)
	
#endif 