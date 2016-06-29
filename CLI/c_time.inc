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

#if defined _cli_time_included
	#endinput
#endif	
#define _cli_time_included

enum
{
	FR, // French
	EN, // English
	PT, // Portuguese
	PL, // Polish
	ES, // Spanish
	DE // German
}

#define LANGUAGE FR

#if LANGUAGE == FR

	#define SECOND ('s')
	#define MINUTE ('m')
	#define HOUR ('h')
	#define DAY ('j')

#elseif LANGUAGE == EN || LANGUAGE == PT || LANGUAGE == ES
	
	#define SECOND ('s')
	#define MINUTE ('m')
	#define HOUR ('h')
	#define DAY ('d')
	
#elseif LANGUAGE == PL
	
	#define SECOND ('s')
	#define MINUTE ('m')
	#define HOUR ('g')
	#define DAY ('d')
	
#elseif LANGUAGE == DE
	
	#define SECOND ('s')
	#define MINUTE ('m')
	#define HOUR ('s')
	#define DAY ('t')
	
#endif

// native ReturnSecondByDate(const duration[]);
stock ReturnSecondByDate(const duration[])
{
	if('0' <= duration[strlen(duration)-1] <= '9') return -1;

	new
		l = strlen(duration),
		time,
		number[5];
		
	for(new i = 0; i < l; i++)
	{		
		if(('A' <= duration[i] <= 'Z') || ('a' <= duration[i] <= 'z'))
		{			
			switch(duration[i])
			{
				case SECOND, SECOND + 32: time += strval(number);
				case MINUTE, MINUTE + 32: time += 60*strval(number);
				case HOUR, HOUR + 32: time += 3600*strval(number);
				case DAY, DAY + 32: time += 86400*strval(number);
				default: return -1;
			}
			
			for(new t = 0; t < sizeof(number); t++)
				number[t] = EOS;
		}
		
		else
		{
			for(new t = 0; t != sizeof(number)-1 && '0' <= duration[i] <= '9';)
				number[t++] = duration[i++];
			
			i--;
		}
	}
	
	return time;
}

// native ReturnDateBySecond(time);
stock ReturnDateBySecond(time)
{
	new
		str[30],
		str2[6];
		
	static const
		val[4] = {86400, 3600, 60, 60},
		let[4] = {DAY, HOUR, MINUTE, SECOND};
		
	for(new i = 0; i < 4; i++)
	{
		if(time == 0) break;
	
		if(time/val[i] != 0 || (i == 3 && time%val[i] != 0))
		{		
			valstr(str2, i != 3 ? time/val[i] : time%val[i]);
			strcat(str, str2);
			str[strlen(str)] = let[i];
			time -= (time/val[i])*val[i];
		}
	}
	
	return str;
}