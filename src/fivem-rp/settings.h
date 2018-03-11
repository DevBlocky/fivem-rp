#pragma once
#include <string>
#include <map>
using namespace std;

typedef struct
{
	map<string, bool> enabled_features;
	map<string, int> keys;
	string problem = "none";
} settings;

void reload_settings(const string &path);
settings& get_settings();

inline pair<bool, int> get_settings_key(settings &s, const string &key)
{
	const auto iter = s.keys.find(key);
	return
	{
		iter == s.keys.end(),
		iter == s.keys.end() ? 0 : iter->second
	};
}
inline pair<bool, bool> get_settings_feature(settings &s, const string &key)
{
	const auto iter = s.enabled_features.find(key);
	return
	{
		iter == s.enabled_features.end(),
		iter == s.enabled_features.end() ? 0 : iter->second
	};
}
