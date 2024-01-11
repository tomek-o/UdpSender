//---------------------------------------------------------------------------


#pragma hdrstop

#include "SendType.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


const char* GetSendTypeDescription(enum SendType type)
{
	switch (type)
	{
	case SEND_WHOLE_BUFFER:
		return "whole buffer";
	case SEND_RANDOM_BUFFER_FRAGMENT:
		return "random buffer fragment";
	default:
		return "???";
	}
}
