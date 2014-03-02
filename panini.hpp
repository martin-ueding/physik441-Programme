// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe mit Jan Weber

#ifndef PANINI_H
#define PANINI_H

#include <cstdlib>
#include <ctime>
#include <vector>

namespace nume {
	class Album {
		public:
			Album(int slots);

			virtual void add_card(int id);
			virtual void add_pack();
			virtual unsigned int fill_up();
			virtual std::vector<unsigned int> generate_pack();
			virtual bool has_card(int id);
			virtual bool is_full();

			unsigned int card_count;

		private:
			int empty_slots;
			std::vector<bool> slots_filled;
	};

	class AlbumSkewed: public Album {
		public:
			AlbumSkewed(int slots): Album(slots) {};

			virtual std::vector<unsigned int> generate_pack();
	};
}

#endif /* end of include guard: PANINI_H */
