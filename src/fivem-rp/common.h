#pragma once
#include <types.h>
#include <string>

inline int show_notification(const std::string &message, BOOL blink = FALSE, BOOL in_brief = FALSE);
inline void show_subtitle(const std::string &message, int duration = 2500, BOOL draw_immediately = TRUE);
void message_user(const std::string &message, int duration = 2500);
void debug_message_user(const std::string &message, int duration = 2500);
