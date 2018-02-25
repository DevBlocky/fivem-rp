#include "../inc/natives.h"
#include "prevent_roll_plugin.h"

// ReSharper disable once IdentifierTypo
#define ALLOW_MOTO_CONTROL

void prevent_roll_plugin::on_tick()
{
	const Ped ped = PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID());

	const Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(ped, false); // getting the vehicle
	if (!ENTITY::DOES_ENTITY_EXIST(veh)) // checking if in vehicle
		return;
#ifdef ALLOW_MOTO_CONTROL
	if (VEHICLE::GET_VEHICLE_CLASS(veh) == 8) // checking for motocylces
	{
		// enabling controls just in the case that server disables them
		CONTROLS::ENABLE_CONTROL_ACTION(0, 59, true); // left/right travel
		CONTROLS::ENABLE_CONTROL_ACTION(0, 60, true); // up/down travel

		return;
	}
#endif

	if (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(veh))
	{
		CONTROLS::DISABLE_CONTROL_ACTION(0, 59, true); // left/right travel
		CONTROLS::DISABLE_CONTROL_ACTION(0, 60, true); // up/down travel
	}
}
