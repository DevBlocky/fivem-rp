#pragma once
#include "plugin.h"

class reticle_plugin : public plugin
{
public:
	std::string get_name() override { return "reticle_plugin"; }
	void on_tick() override;
};
