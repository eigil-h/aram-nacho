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

#ifndef ARAM_CURSOR_H
#define ARAM_CURSOR_H

namespace aram {
	namespace device {

		/**
		 * System wide cursor. IE playback position within the project and 
		 * playback/recording position within the audioclip.
		 */
		class cursor {
		public:
			cursor();
			cursor(const cursor&) = delete;
			void operator=(const cursor&) = delete;

			static cursor& project_cursor();
			static cursor& audioclip_cursor();

			void index(long idx);
			long index();
			void delta(long delta);

		private:
			long idx_;
		};
	}
}

#endif
