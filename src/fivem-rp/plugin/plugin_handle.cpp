#include "plugin_handle.h"

plugin_handle::plugin_handle(const vector<plugin*>& plugins) 
{
	this->plugins_ = plugins;
}
void plugin_handle::plugin_start()
{
	for (auto plugin : this->plugins_)
		if (plugin->enabled)
			plugin->on_start();
}
void plugin_handle::plugin_on_tick() const
{
	for (auto plugin : plugins_)
		if (plugin->enabled)
			plugin->on_tick();
}
void plugin_handle::plugin_shutdown() const
{
	for (auto plugin : plugins_)
	{
		if (plugin->enabled)
		{
			plugin->on_stop();
			delete plugin;
		}
	}
}
