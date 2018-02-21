#include "plugin.h"
#include "../inc/natives.h"

// toggles the ability to roll left and right
#define ROLL_LEFT_RIGHT

void moto_control_plugin::on_tick()
{
	const Ped ped = PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID());

	const Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(ped, false); // getting the vehicle
	if (!ENTITY::DOES_ENTITY_EXIST(veh)) // checking if in vehicle
		return;
	if (VEHICLE::GET_VEHICLE_CLASS(veh) != 8) // checking for motocylces
		return;
#ifdef ROLL_LEFT_RIGHT
	CONTROLS::ENABLE_CONTROL_ACTION(0, 59, true); // left/right travel
#endif
	CONTROLS::ENABLE_CONTROL_ACTION(0, 60, true); // up/down travel
}
