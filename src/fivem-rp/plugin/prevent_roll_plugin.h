#pragma once
#include "plugin.h"

class prevent_roll_plugin : public plugin
{
public:
	std::string get_name() override { return "prevent_roll_plugin"; }
	void on_tick() override;
};
