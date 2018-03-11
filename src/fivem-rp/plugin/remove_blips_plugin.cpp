#include <gta/natives.h>
#include "remove_blips_plugin.h"

#define FIND_BY_SPRITE

#ifdef FIND_BY_SPRITE
static int blipsprite_block[] = {
	1, // player
	16, // jet
	43, // heli
	56, // cop car
	198, // taxi??
	225, // common car
	226, // motocycle
	307, // common plane
	410, // sail boat
	421, // tank
	427, // boat
	460, // apc
	512, // atv
};
#endif

void remove_blips_plugin::on_tick()
{
	for (Player i = 0; i < 32; i++) // looping through players
	{
		// looping for every player
		const Ped player_ped = PLAYER::GET_PLAYER_PED(i); // getting ped from player
		if (!ENTITY::DOES_ENTITY_EXIST(player_ped)) // checking if player exist
			continue;

		const Blip entity_blip = UI::GET_BLIP_FROM_ENTITY(player_ped); // getting player blip
		if (UI::DOES_BLIP_EXIST(entity_blip))
		{
			UI::SET_BLIP_SHOW_CONE(entity_blip, false); // turning off blip cone
			UI::SET_BLIP_DISPLAY(entity_blip, 1); // turn off blip
		}
#ifdef FIND_BY_SPRITE
		for (int sprite : blipsprite_block)
		{
			const Blip pld_blip = UI::GET_FIRST_BLIP_INFO_ID(sprite);
			if (UI::DOES_BLIP_EXIST(pld_blip))
			{
				UI::SET_BLIP_SPRITE(pld_blip, 239); // changing blip sprite
				UI::SET_BLIP_DISPLAY(pld_blip, 1); // turn off blip
			}
		}
#endif
	}
}
