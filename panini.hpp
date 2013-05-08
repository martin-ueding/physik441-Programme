// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#ifndef PANINI_H
#define PANINI_H

#include <cstdlib>
#include <ctime>
#include <vector>

namespace nume {
	class Album {
		public:
			void add_card(int id);
			void add_pack();
			Album(int slots);
			unsigned int fill_up();
			unsigned int card_count;
			bool is_full();
		private:
			std::vector<bool> slots_filled;
			int empty_slots;
	};

	class AlbumDouble: public Album {
		public:
			void add_card(int id);
			AlbumDouble(int slots);
			bool is_full();
		private:
			std::vector<unsigned int> slots_filled;
			int empty_slots;
	};
}

#endif /* end of include guard: PANINI_H */
