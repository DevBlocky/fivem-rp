#pragma once
#include "plugin.h"

class remove_gamertag_plugin : public plugin
{
public:
	std::string get_name() override { return "remove_gamertag_plugin"; }
	void on_tick() override;
};
