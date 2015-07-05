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

#include "database.h"
#include "../util/system.h"

#include <exception>
#include <algorithm>
#include <utility>


namespace aram {
	namespace device {
		using std::runtime_error;
		using std::for_each;
		using std::pair;

		kc_db& kc_db::application() {
			static kc_db instance("application");
			return instance;
		}

		kc_db& kc_db::project() {
			static kc_db instance("project");
			return instance;
		}

		kc_db::kc_db(const string& name) {
			if (!db().open(system::home_path() + "/.aram2/" + name + ".kch", TreeDB::OWRITER | TreeDB::OCREATE)) {
				throw runtime_error(error_message());
			}
		}

		kc_db::~kc_db() {
			if (!db().close()) {
				//Undefined behavior, but what does it take to have 'close' fail ...?
				throw runtime_error(error_message());
			}
		}

		TreeDB& kc_db::db() {
			return db_;
		}

		const string kc_db::error_message() {
			string s;
			return s + db().error().name() + ": " + db().error().message();
		}

		void kc_db::save_entity(const string& entity_id, const map<const char*, string>& map) {

			kc_transaction transaction(db());

			for_each(map.begin(), map.end(), [&](const pair<const char*, string> entry){
				if (!db().set(entity_id + "." + entry.first, entry.second)) {
					transaction.fail();
					throw runtime_error(error_message());
				}
			});
		}

		const map<const char*, string> kc_db::load_entity(const string& entity_id,
						const vector<const char*>& keys) {

			map<const char*, string> map;

			for_each(keys.begin(), keys.end(), [&](const char* key) {
				string val;
				if (!db().get(entity_id + "." + key, &val)) {
					throw runtime_error(error_message());
				}
				map[key] = val;
			});

			return map;
		}


		kc_db::kc_transaction::kc_transaction(TreeDB& db) : db_(db), commit_(true){
			db_.begin_transaction();
		}

		kc_db::kc_transaction::~kc_transaction() {
			db_.end_transaction(commit_);
		}
		
		void kc_db::kc_transaction::fail() {
			commit_ = false;
		}
	}
}
