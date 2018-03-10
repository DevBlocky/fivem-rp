#include "common.h"
#include "inc/natives.h"

int show_notification(const char *text, const BOOL blink, const BOOL in_brief)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY(const_cast<char*>("STRING"));
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(const_cast<char*>(text));
	return UI::_DRAW_NOTIFICATION(blink, in_brief);
}
void show_subtitle(const char *message, const int duration, const BOOL draw_immediately)
{
	UI::BEGIN_TEXT_COMMAND_PRINT(const_cast<char*>("STRING"));
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(const_cast<char*>(message));
	UI::END_TEXT_COMMAND_PRINT(duration, draw_immediately);
}
