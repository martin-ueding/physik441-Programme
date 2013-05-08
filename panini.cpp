// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>

#include "panini.hpp"

void nume::Album::add_card(int id) {
	if (!slots_filled[id]) {
		slots_filled[id] = true;
		--empty_slots;
	}
}

void nume::Album::add_pack() {
	unsigned int pack_size = 5;
	for (unsigned int i = 0; i < pack_size; ++i) {
		int card_number = ((double) std::rand() / (RAND_MAX)) * card_count;
		add_card(card_number);
	}
}

nume::Album::Album(int slots) {
	card_count = slots;
	slots_filled = std::vector<bool>(card_count);

	for (unsigned int i = 0; i < slots_filled.size(); ++i) {
		slots_filled[i] = false;
	}

	empty_slots = card_count;
}

unsigned int nume::Album::fill_up() {
	unsigned int n = 0;

	do {
		add_pack();
		++n;
	} while (!is_full());

	return n;
}

bool nume::Album::is_full() {
	return empty_slots == 0;
}
