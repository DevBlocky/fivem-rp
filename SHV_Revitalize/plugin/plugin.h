#pragma once
class plugin
{
public:
	virtual ~plugin() = default;
	virtual void on_start() {}
	virtual void on_tick() {}
	virtual void on_stop() {}
};
class reticle_plugin : public plugin
{
public:
	void on_tick() override;
};
class moto_control_plugin : public plugin
{
public:
	void on_tick() override;
};
class blips_plugin : public plugin
{
public:
	void on_tick() override;
};
class gamertag_plugin : public plugin
{
public:
	void on_tick() override;
};
