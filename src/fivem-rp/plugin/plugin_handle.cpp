#include "plugin_handle.h"

plugin_handle::plugin_handle(vector<plugin*> *plugins) 
{
	this->plugins_ = plugins;
	for (auto plugin : *this->plugins_)
		plugin->on_start();
}
void plugin_handle::plugin_on_tick() const
{
	for (auto plugin : *plugins_)
		plugin->on_tick();
}
void plugin_handle::plugin_shutdown() const
{
	for (auto plugin : *plugins_)
	{
		plugin->on_stop();
		delete plugin;
	}
}
plugin_handle::~plugin_handle()
{
	delete plugins_;
}
