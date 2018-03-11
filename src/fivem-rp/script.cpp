// needed
#include "script.h"

// main stuff
#include <gta/main.h>
#include <typeinfo>
#include "plugin/plugin.h"
#include "plugin/plugin_handle.h"
#include "common.h"
#include "settings.h"
#include "keyboard.h"

// plugin types
#include "plugin/reticle_plugin.h"
#include "plugin/prevent_roll_plugin.h"
#include "plugin/remove_blips_plugin.h"
#include "plugin/remove_gamertag_plugin.h"
#include "plugin/give_weapon_plugin.h"

#define SETTINGS_FILE string("fivem_rp.settings.json")

using namespace std;

plugin_handle *handler;

void initialize_plugins()
{
	vector<plugin*> arr
	{
		new reticle_plugin(),
		new prevent_roll_plugin(),
		new remove_blips_plugin(),
		new remove_gamertag_plugin(),
		new give_weapon_plugin()
	};
	settings &settings = get_settings();
	for (auto& plugin : arr)
	{
		const string name = plugin->get_name();
		const auto feat_info = get_settings_feature(settings, name);
		plugin->enabled = feat_info.second;
	}
	
	handler = new plugin_handle(arr);
	handler->plugin_start();

	debug_message_user("initialized");
}
int main() {
	reload_settings(SETTINGS_FILE);
	initialize_plugins();
	while (true)
	{
		handler->plugin_on_tick();

		// settings stuff
		settings &settings = get_settings();
		const auto key1 = get_settings_key(settings, "show_problem");
		if (IsKeyJustUp(key1.first ? VK_F12 : key1.second))
		{
			message_user(settings.problem, 5000);
		}
		const auto key2 = get_settings_key(settings, "reload_settings");
		if (IsKeyJustUp(key2.first ? VK_F9 : key2.second))
		{
			reload_settings(SETTINGS_FILE);
			delete handler;
			initialize_plugins();
			message_user("reloaded settings");
		}

		WAIT(1);
	}
	return 0;
}
void script_main() {
	srand(GetTickCount());
	throw main();  // NOLINT
}
void script_end()
{
	handler->plugin_shutdown();
}
