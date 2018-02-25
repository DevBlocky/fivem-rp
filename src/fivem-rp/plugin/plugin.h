#pragma once
class plugin
{
public:
	virtual ~plugin() = default;
	virtual void on_start() {}
	virtual void on_tick() {}
	virtual void on_stop() {}
};
