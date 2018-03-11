#pragma once
#include "plugin.h"

class show_speed_plugin : public plugin
{
public:
	std::string get_name() override { return "show_speed_plugin"; }
	void on_tick() override;
};
