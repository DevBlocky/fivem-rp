#pragma once
#include "plugin.h"
#include <vector>

using namespace std;

class plugin_handle
{
	vector<plugin*> plugins_;

public:
	explicit plugin_handle(const vector<plugin*>& plugins);
	void plugin_start();
	void plugin_on_tick() const;
	void plugin_shutdown() const;
};
