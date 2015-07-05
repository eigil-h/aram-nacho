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

#include "audioengine.h"
#include "../util/system.h"

#include <memory>

namespace aram {
	namespace device {
		namespace audio {
			using std::unique_ptr;
			using std::string;

			audioengine& audioengine::instance() {
				static unique_ptr<audioengine> asp(new_audioengine());
				return *asp;
			}

			audioengine* audioengine::new_audioengine() {
				for (string s : system::program_arguments()) {
					if (s == "--silence") {
						return new audioengine_silence();
					}
				}
				return new audioengine_jack2();
			}

			audioengine_silence::audioengine_silence() {
			}

			audioengine_jack2::audioengine_jack2() {
			}
		}
	}
}