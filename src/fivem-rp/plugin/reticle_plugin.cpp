#include "../inc/natives.h"
#include "reticle_plugin.h"
#include "../common.h"

void reticle_plugin::on_tick()
{
	const Player player = PLAYER::PLAYER_ID();
	const Ped ped = PLAYER::GET_PLAYER_PED(player);

	const Hash weapon_hash = WEAPON::GET_SELECTED_PED_WEAPON(ped); // getting current weapon
	const BOOL is_aim = PLAYER::IS_PLAYER_FREE_AIMING(player); // getting aim status
	if (weapon_hash != 2725352035 && is_aim) // checking for aiming and not hands
	{
		UI::SHOW_HUD_COMPONENT_THIS_FRAME(14); // showing the reticle
#if defined(_DEBUG)
		show_subtitle("fivem_rp: given reticle", 5, TRUE);
#endif
	}
}
