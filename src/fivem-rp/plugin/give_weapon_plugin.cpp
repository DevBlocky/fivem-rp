#include "give_weapon_plugin.h"
#include "../keyboard.h"
#include "../inc/natives.h"
#include "../common.h"
#include <cstdint>
#include <vector>

using namespace std;

struct weapon_info
{
	vector<Hash> attachments;
	Hash weapon;

	weapon_info(const Hash weapon, const std::vector<Hash>& attachments)
	{
		this->attachments = attachments;
		this->weapon = weapon;
	}
};

weapon_info give_w[] = {
	weapon_info(0x5EF9FEC4, // combat pistol
		vector<Hash> { 0x359B7AAE /* flashlight*/ }),
	weapon_info(0x3656C8C1, // stun gun
		vector<Hash> {}),
	weapon_info(0x1D073A89, // pump shotgun
		vector<Hash> { 0x7BC4CDDC /* flashlight */ }),
	weapon_info(0x83BF0278, // carbine rifle
		vector<Hash> { 0xC164F53 /* grip */, 0x7BC4CDDC /* flashlight */, 0x91109691 /* extendo mags */ }),
	weapon_info(0x678B81B1, // nightstick
		vector<Hash> {}),
	weapon_info(0x8BB05FD7, // flashlight
		vector<Hash> {}),
	weapon_info(0x060EC506, // fire extinguisher
		vector<Hash> {}),
	weapon_info(0x497FACC3, // flare
		vector<Hash> {})
};

void give_weapons()
{
	const Ped ped = PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID());

	// remove all of the weapons prior
	WEAPON::REMOVE_ALL_PED_WEAPONS(ped, FALSE);

	for (const auto& weapon_info : give_w)
	{
		WEAPON::GIVE_WEAPON_TO_PED(ped, weapon_info.weapon, 9999, FALSE, FALSE);
		for (const auto& attachment : weapon_info.attachments)
		{
			WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(ped, weapon_info.weapon, attachment);
		}
	}
}
void give_weapon_plugin::on_tick()
{
	if (IsKeyJustUp(VK_F10))
	{
		give_weapons();
		show_subtitle("Weapons Given", 5000);
	}
}
