#pragma once
#include "plugin.h"

class give_weapon_plugin : public plugin
{
public:
	std::string get_name() override { return "give_weapon_plugin"; }
	void on_tick() override;
};
