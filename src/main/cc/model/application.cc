/*
	ARAM, the audio recorder and music nacho
	Copyright (C) 2014-2015  Eigil Hysvær

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <map>
#include <string>

#include "application.h"
#include "../device/database.h"

#define APPLICATION_ID "LfWcYN40SD" //Generated at random.org @ 2015-07-04 16:35:47 UTC

namespace aram {
	using device::kc_db;

	application::application(const string& name, const string& project_id, const string& audioclip_id) :
					id_(APPLICATION_ID), name_(name), project_id_(project_id), audioclip_id_(audioclip_id) {
	}

	const string& application::name() {
		return name_;
	}

	const string& application::id() {
		return id_;
	}

	const string& application::project_id() {
		return project_id_;
	}

	const string& application::audioclip_id() {
		return audioclip_id_;
	}

	const std::map<const char*, string> application::to_map() {
		std::map<const char*, string> m;
		m["name"] = name();
		m["project_id"] = project_id();
		m["audioclip_id"] = audioclip_id();

		return m;
	}

	const std::vector<const char*> application::keys() {
		std::vector<const char*> vec;
		vec.push_back("name");
		vec.push_back("project_id");
		vec.push_back("audioclip_id");
		return vec;
	}

	void application::save() {
		kc_db::application().save_entity(id(), to_map());
	}
	
	application application::load() {
		std::map<const char*, string> m = kc_db::application().load_entity(APPLICATION_ID, keys());
		application application(m["name"], m["project_id"], m["audioclip_id"]);
		return application;
	}
}