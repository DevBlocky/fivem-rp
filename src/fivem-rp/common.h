#pragma once
#include <gta/types.h>
#include <string>

int show_notification(const std::string &message, BOOL blink = FALSE, BOOL in_brief = FALSE);
void show_subtitle(const std::string &message, int duration = 2500, BOOL draw_immediately = TRUE);
void message_user(const std::string &message, int duration = 2500);
void debug_message_user(const std::string &message, int duration = 2500);
