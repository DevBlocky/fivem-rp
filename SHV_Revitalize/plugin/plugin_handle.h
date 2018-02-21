#pragma once
#include "plugin.h"
#include "plugin_handle.h"
#include <vector>

class plugin_handle
{
	std::vector<plugin*> plugins_;

public:
	void plugin_init(std::vector<plugin*> plugins)
	{
		this->plugins_ = plugins;
		for (auto plugin : this->plugins_)
			plugin->on_start();
	}
	void plugin_on_tick() const
	{
		for (auto plugin : plugins_)
			plugin->on_tick();
	}
	void plugin_shutdown() const
	{
		for (auto plugin : plugins_)
		{
			plugin->on_stop();
			delete plugin;
		}
	}
};
