#include "settings.h"
#include <jsoncpp/json/json.h>
#include <fstream>
#include <numeric>
#include <memory>

using namespace std;

unique_ptr<settings> s;

void reload_settings(const std::string &path)
{
	Json::Value json;
	ifstream stream(path, ifstream::binary);
	if (stream.good())
		stream >> json;

	s = make_unique<settings>();

	if (json.isNull())
	{
		s->problem = "file_not_read";
		return;
	}

	const Json::Value features = json.get("feature-enable", Json::Value());
	if (!features.isNull())
	{
		if (features.isObject())
			for (const auto &member : features.getMemberNames())
				s->enabled_features.insert(pair<string, bool>(member, features.get(member, false).asBool()));
		else
			s->problem = "feature_not_object";
	}
	else
		s->problem = "features_null";

	const Json::Value keys = json.get("keys", Json::Value());
	if (!keys.isNull())
	{
		if (keys.isObject())
			for (const auto &member : keys.getMemberNames())
				s->keys.insert(pair<string, int>(member, keys.get(member, 0).asInt()));
		else
			s->problem = "keys_not_object";
	}
	else
		s->problem = "keys_null";

	const Json::Value m = json.get("measurement", Json::Value());
	if (!m.isNull())
	{
		if (m.isString())
		{
			const string str = m.asString();
			if (str != "imperial" && str != "metric")
			{
				s->problem = "measurement_not_measurement";
			}
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
