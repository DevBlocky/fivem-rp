#pragma once
#include "plugin.h"

class prevent_roll_plugin : public plugin
{
public:
	void on_tick() override;
};
