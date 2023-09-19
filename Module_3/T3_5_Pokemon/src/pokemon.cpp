#include "pokemon.hpp"

PokemonCollection::PokemonCollection(PokemonCollection collection,
                                     PokemonCollection collection2) {
  std::copy(collection.pokemons_.begin(), collection.pokemons_.end(),
            std::back_inserter(pokemons_));
  std::copy(collection2.pokemons_.begin(), collection2.pokemons_.end(),
            std::back_inserter(pokemons_));
  SortById();
  SortByName();
  pokemons_.unique();
}

void PokemonCollection::Add(const std::string& name, size_t id) {
  pokemons_.push_back({name, id});
}

bool PokemonCollection::Remove(const std::string& name, size_t id) {
  for (auto pokemon = pokemons_.begin(); pokemon != pokemons_.end();
       pokemon++) {
    if (pokemon->first == name && pokemon->second == id) {
      pokemons_.erase(pokemon);
      return true;
    }
  }
  return false;
}

void PokemonCollection::Print() const {
  for (auto pokemon : pokemons_) {
    std::cout << "id: " << pokemon.second << ", name: " << pokemon.first
              << std::endl;
  }
}

bool compareNames(const std::pair<std::string, size_t> first,
                  const std::pair<std::string, size_t> second) {
  return first.first < second.first;
}

bool compareIDs(const std::pair<std::string, size_t> first,
                const std::pair<std::string, size_t> second) {
  return first.second < second.second;
}

void PokemonCollection::SortByName() { pokemons_.sort(compareNames); }

void PokemonCollection::SortById() { pokemons_.sort(compareIDs); }