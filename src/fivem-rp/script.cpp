// needed
#include "script.h"

// main stuff
#include "inc/main.h"
#include <vector>
#include "plugin/plugin.h"
#include "plugin/plugin_handle.h"

// plugin types
#include "plugin/reticle_plugin.h"
#include "plugin/prevent_roll_plugin.h"
#include "plugin/blips_plugin.h"
#include "plugin/gamertag_plugin.h"

plugin_handle *handler;

void initialize_plugins()
{
	std::vector<plugin*> *arr = new std::vector<plugin*>
	{
		new reticle_plugin(),
		new prevent_roll_plugin(),
		new blips_plugin(),
		new gamertag_plugin(),
	};
	handler = new plugin_handle(arr);
}
int main() {
	initialize_plugins();
	while (true)
	{
		handler->plugin_on_tick();
		WAIT(1);
	}
	return 0;
}
void script_main() {
	srand(GetTickCount());
	throw main();
}
void script_end()
{
	handler->plugin_shutdown();
	delete handler;
}
