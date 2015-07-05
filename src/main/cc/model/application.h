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

#ifndef ARAM_APPLICATION_H
#define ARAM_APPLICATION_H

#include <string>
#include <map>
#include <vector>

namespace aram {
	using std::string;

	class application {
	public:
		application(const string& name, const string& project_id, const string& audioclip_id);

		const string& name();
		const string& project_id();
		const string& audioclip_id();

		void save();
		static application load();

	private:
		string id_;
		string name_;
		string project_id_;
		string audioclip_id_;

		const string& id();
		const std::map<const char*, string> to_map();

		static const std::vector<const char*> keys();
	};
}
#endif
