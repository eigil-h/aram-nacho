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

#ifndef ARAM_AUDIOENGINE_H
#define ARAM_AUDIOENGINE_H

namespace aram {
	namespace device {
		namespace audio {

			/**
			 * The interface to underlying audio system.
			 */
			class audioengine {
			public:
				static audioengine& instance();

			private:
				static audioengine* new_audioengine();
			};

			class audioengine_silence : public audioengine {
			public:
				audioengine_silence();
			};

			class audioengine_jack2 : public audioengine {
			public:
				audioengine_jack2();
			};
		}
	}
}

#endif

