#pragma once
#include "plugin.h"

class remove_blips_plugin : public plugin
{
public:
	std::string get_name() override { return "remove_blips_plugin"; }
	void on_tick() override;
};
