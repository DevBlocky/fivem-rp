#include "../inc/natives.h"
#include "gamertag_plugin.h"

void gamertag_plugin::on_tick()
{
	const Player player = PLAYER::PLAYER_ID();

	for (Player i = 0; i < 32; i++)
	{
		int gamer_tag_id = 0;
		const Ped player_ped = PLAYER::GET_PLAYER_PED(i);

		// find / create gamer tag id
		if (i != player)
			gamer_tag_id = UI::_CREATE_MP_GAMER_TAG(player_ped, PLAYER::GET_PLAYER_NAME(i), false, false, const_cast<char*>(""), 0);

		// remove gamer tag
		UI::REMOVE_MP_GAMER_TAG(gamer_tag_id);
	}
}
