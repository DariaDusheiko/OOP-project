// #ifndef HASHMAP_H
// #define HASHMAP_H

// #include <iostream>
// #include <string>
// #include <cstdlib>
// #include <cassert>
// #include <fstream>
// #include <unordered_map>
// #include <vector>
// #include <algorithm>

// using namespace std;

// template <typename K, typename V>
// class Hashmap {
// private:
//     struct Item {
//         K key;
//         V value;
//     };

//     Item* elements;
//     int capacity; 
//     int count;

//     long hash(K key) const;

// public:
//     Hashmap();
//     Hashmap(const Hashmap& other);
//     ~Hashmap();

//     void clear();
//     int size() const;
//     void saveTo(const string& filepath);
//     void loadFrom(const string& filepath);
//     void add(K key, V value);
//     bool remove(K key);
//     V operator[](K key);
//     bool contains(K key) const;
//     Hashmap<K, V> operator&&(const Hashmap<K, V>& other) const;
//     bool operator==(const Hashmap<K, V>& other) const;
//     bool operator!=(const Hashmap<K, V>& other) const;
//     void getWinners() const;

// private:
//     void realloc();
// };

// #include "Hashmap.tpp" 

// #endif 
