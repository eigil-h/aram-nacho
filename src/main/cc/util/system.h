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

#ifndef ARAM_SYSTEM_H
#define ARAM_SYSTEM_H

#include <string>
#include <vector>

namespace aram {
	/** Here goes stuff that are not portable between systems.
	 */
	class system {
	public:
		static const std::string home_path();
		static void mkdir(const std::string& path);
		static std::vector<std::string> program_arguments();
	};
}

#endif
