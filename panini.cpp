// Copyright © 2013 Martin Ueding <dev@martin-ueding.de>
// Abgabe mit Jan Weber

#include "panini.hpp"

void nume::Album::add_card(int id) {
	if (!slots_filled[id]) {
		slots_filled[id] = true;
		--empty_slots;
	}
}

void nume::Album::add_pack() {
	std::vector<unsigned int> pack = generate_pack();
	for (unsigned int &card: pack) {
		add_card(card);
	}
}

std::vector<unsigned int> nume::Album::generate_pack() {
	std::vector<unsigned int> pack(5);
	for (unsigned int &card: pack) {
		card = ((double) std::rand() / (RAND_MAX)) * card_count;
	}
	return pack;
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

bool nume::Album::has_card(int id) {
	return slots_filled[id];
}

bool nume::Album::is_full() {
	return empty_slots == 0;
}

std::vector<unsigned int> nume::AlbumSkewed::generate_pack() {
	std::vector<unsigned int> pack(5);
	for (unsigned int &card: pack) {
		card = ((double) std::rand() / (RAND_MAX)) * card_count;
		if (208 <= card && card <= 227 && std::rand() > RAND_MAX/2) {
			card = ((double) std::rand() / (RAND_MAX)) * card_count;
		}
	}
	return pack;
}
