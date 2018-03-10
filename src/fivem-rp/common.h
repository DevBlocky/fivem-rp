#pragma once
#include "inc/types.h"

int show_notification(const char *text, BOOL blink = FALSE, BOOL in_brief = FALSE);
void show_subtitle(const char *message, int duration = 2500, BOOL draw_immediately = TRUE);
