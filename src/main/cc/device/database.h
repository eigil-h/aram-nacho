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

#ifndef ARAM_DATABASE_H
#define ARAM_DATABASE_H

#include <map>
#include <vector>
#include <string>
#include <kchashdb.h>

namespace aram {
	namespace device {
		using std::map;
		using std::vector;
		using std::string;
		using kyotocabinet::TreeDB;

		class kc_db {
		public:
			static kc_db& application();
			static kc_db& project();

			void save_entity(const string& entity_id, const map<const char*, string>& map);
			const map<const char*, string> load_entity(const string& entity_id, const vector<const char*>& keys);

		private:
			TreeDB db_;

			kc_db(const string& name);
			kc_db(const kc_db&) = delete;
			void operator=(const kc_db&) = delete;
			~kc_db();
			
			TreeDB& db();
			const string error_message();

			class kc_transaction {
			public:
				kc_transaction(TreeDB& db);
				~kc_transaction();

				void fail();
			private:
				TreeDB& db_;
				bool commit_;
			};
		};
	}
}

#endif
