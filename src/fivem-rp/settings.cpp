#include "settings.h"
#include <jsoncpp/json/json.h>
#include <fstream>
#include <numeric>
#include <memory>

using namespace std;

unique_ptr<settings> s;

void reload_settings(const std::string &path)
{
	try
	{
		Json::Value json;
		ifstream stream(path, ifstream::binary);
		stream >> json;

		s = make_unique<settings>();

		if (json.isNull())
		{
			s->problem = "file_not_read";
			return;
		}

		const Json::Value features = json.get("feature-enable", 0);
		if (!features.isInt())
		{
			if (features.isObject())
			{
				for (const auto &member : features.getMemberNames())
					s->enabled_features.insert(pair<string, bool>(member, features.get(member, false).asBool()));
			}
			else
			{
				s->problem = "feature_not_object";
			}
		}
		else
		{
			s->problem = "features_null";
		}

		const Json::Value keys = json.get("keys", 0);
		if (!keys.isInt())
		{
			if (keys.isObject())
			{
				for (const auto &member : keys.getMemberNames())
					s->keys.insert(pair<string, int>(member, keys.get(member, 0).asInt()));
			}
			else
			{
				s->problem = "keys_not_object";
			}
		}
		else
		{
			s->problem = "keys_null";
		}
	}
	catch (std::exception &e) 
	{
		s->enabled_features.clear();
		s->keys.clear();

		s->problem = e.what();
	}
}

settings& get_settings()
{
	return *s;
}
