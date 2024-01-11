//---------------------------------------------------------------------------

#ifndef SendTypeH
#define SendTypeH
//---------------------------------------------------------------------------

enum SendType
{
	SEND_WHOLE_BUFFER = 0,
	SEND_RANDOM_BUFFER_FRAGMENT,

	SEND_TYPE__LIMITER
};

const char* GetSendTypeDescription(enum SendType type);

#endif
