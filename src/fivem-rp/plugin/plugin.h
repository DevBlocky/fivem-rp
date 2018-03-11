#pragma once
#include "string"

class plugin
{
public:
	virtual ~plugin() = default;
	virtual std::string get_name() { return "default_plugin"; }
	virtual void on_start() {}
	virtual void on_tick() {}
	virtual void on_stop() {}
};
