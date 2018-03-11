#include <gta/natives.h>
#include "show_speed_plugin.h"
#include "../settings.h"
#include "../common.h"

const double ms_to_mph_ratio = 2.2369;
const double ms_to_kph_ratio = 3.6;

struct
{
	double x = 0;
	double y = -0.001;
} ui;

void show_speed_plugin::on_tick()
{
	const Ped c_ped = PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID());
	const Vehicle c_veh = PED::GET_VEHICLE_PED_IS_IN(c_ped, FALSE);
	
	if (!ENTITY::DOES_ENTITY_EXIST(c_veh))
		return;

	double speed = ENTITY::GET_ENTITY_SPEED(c_veh);
	settings &s = get_settings();
	if (s.measurement == "imperial")
		speed *= ms_to_mph_ratio;
	else
		speed *= ms_to_kph_ratio;

	// drawing information
	draw_rect({ ui.x + 0.11, ui.y + 0.932 }, { 0.046, 0.03 }, { 0, 0, 0, 150 });
	draw_txt("~w~" + std::to_string(static_cast<int>(speed)), { ui.x + 0.61, ui.y + 1.42 }, { 1.0, 1.0 }, 0.64, { 255,255,255,255 });

	const string speed_type = s.measurement == "imperial" ? "mph" : "km/h";
	draw_txt("~w~ " + speed_type, { ui.x + 0.633, ui.y + 1.432 }, { 1.0, 1.0 }, 0.4, { 255,255,255,255 });
}
