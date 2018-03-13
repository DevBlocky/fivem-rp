#include "settings.h"
#include <json/json.hpp>
#include <fstream>
#include <memory>

using namespace std;
using json_value = nlohmann::basic_json<>;

unique_ptr<settings> s;

void reload_settings(const std::string &path)
{
	json_value json;
	ifstream stream(path, ifstream::binary);
	if (stream.good())
		stream >> json;

	s = make_unique<settings>();

	if (json.is_null())
	{
		s->problem = "file_not_read";
		return;
	}

	json_value features = json["feature-enable"];
	if (!features.is_null())
	{
		if (features.is_object())
			for (auto it = features.begin(); it != features.end(); ++it)
				s->enabled_features.insert(pair<string, bool>(it.key(), it.value()));
		else
			s->problem = "feature_not_object";
	}
	else
		s->problem = "features_null";

	const json_value keys = json["keys"];
	if (!keys.is_null())
	{
		if (keys.is_object())
			for (auto it = keys.begin(); it != keys.end(); ++it)
				s->keys.insert(pair<string, int>(it.key(), it.value()));
		else
			s->problem = "keys_not_object";
	}
	else
		s->problem = "keys_null";

	const json_value m = json["measurement"];
	if (!m.is_null())
	{
		if (m.is_string())
		{
			const string str = m;
			if (str != "imperial" && str != "metric")
				s->problem = "measurement_not_measurement";
			else
				s->measurement = str;
		}
		else
			s->problem = "measurement_not_string";
	}
	else
		s->problem = "measurement_null";
}

settings& get_settings()
{
	return *s;
}
