#include "common.h"
#include <gta/natives.h>

void draw_txt(
	const std::string& text,
	const point pos,
	const point size,
	const double scale,
	const color color
)
{
	UI::SET_TEXT_FONT(4);
	UI::SET_TEXT_PROPORTIONAL(0);
	UI::SET_TEXT_SCALE(static_cast<float>(scale), static_cast<float>(scale));
	UI::SET_TEXT_COLOUR(color.r, color.g, color.b, color.a);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 255);
	UI::SET_TEXT_EDGE(2, 0, 0, 0, 255);
	UI::SET_TEXT_DROP_SHADOW();
	UI::SET_TEXT_OUTLINE();
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT(const_cast<char*>("STRING"));
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(const_cast<char*>(text.c_str()));
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(static_cast<float>(pos.x - size.x / 2), static_cast<float>(pos.y - size.y / 2 + 0.005));
}
void draw_rect(const point pos, const point size, const color color)
{
	GRAPHICS::DRAW_RECT(
		static_cast<float>(pos.x + size.x / 2),
		static_cast<float>(pos.y + size.y / 2),
		static_cast<float>(size.x),
		static_cast<float>(size.y),
		color.r,
		color.g,
		color.b,
		color.a);
}


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
