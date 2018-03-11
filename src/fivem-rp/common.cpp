#include "common.h"
#include <natives.h>

int show_notification(const std::string& message, const BOOL blink, const BOOL in_brief)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY(const_cast<char*>("STRING"));
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(const_cast<char*>(message.c_str()));
	return UI::_DRAW_NOTIFICATION(blink, in_brief);
}
void show_subtitle(const std::string& message, const int duration, const BOOL draw_immediately)
{
	UI::BEGIN_TEXT_COMMAND_PRINT(const_cast<char*>("STRING"));
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(const_cast<char*>(message.c_str()));
	UI::END_TEXT_COMMAND_PRINT(duration, draw_immediately);
}
void message_user(const std::string& message, const int duration)
{
	show_subtitle("fivem_rp: " + message, duration, TRUE);
}
void debug_message_user(const std::string& message, const int duration)
{
#if defined(_DEBUG)
	message_user(message, duration);
#endif
}
