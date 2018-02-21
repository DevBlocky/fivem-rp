#include "script.h"

plugin_handle handler;

void initialize_plugins()
{
	const std::vector<plugin*> arr
	{
		new reticle_plugin(),
		new moto_control_plugin(),
		new blips_plugin(),
		new gamertag_plugin(),
	};
	handler.plugin_init(arr);
}
int main() {
	initialize_plugins();
	while (true)
	{
		handler.plugin_on_tick();
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
	handler.plugin_shutdown();
}
