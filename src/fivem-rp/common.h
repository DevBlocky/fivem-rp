#pragma once
#include <gta/types.h>
#include <string>

typedef struct
{
	int r, g, b, a;
} color;
typedef struct
{
	double x, y;
} point;

void draw_txt(
	const std::string& text,
	const point pos,
	const point size,
	const double scale,
	const color color
);
void draw_rect(
	const point pos,
	const point size,
	const color color
);

int show_notification(const std::string &message, BOOL blink = FALSE, BOOL in_brief = FALSE);
void show_subtitle(const std::string &message, int duration = 2500, BOOL draw_immediately = TRUE);
void message_user(const std::string &message, int duration = 2500);
void debug_message_user(const std::string &message, int duration = 2500);
