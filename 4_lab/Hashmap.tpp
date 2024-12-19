// #include "Hashmap.h"

// template <typename K, typename V>
// long Hashmap<K, V>::hash(K key) const {
//     return std::hash<K>()(key) % capacity; 
// }

// template <typename K, typename V>
// Hashmap<K, V>::Hashmap() : capacity(32), count(0) {
//     elements = new Item[capacity]{};
// }

// template <typename K, typename V>
// Hashmap<K, V>::Hashmap(const Hashmap& other) : capacity(other.capacity), count(other.count) {
//     elements = new Item[capacity];
//     for (int i = 0; i < capacity; ++i) {
//         elements[i] = other.elements[i];
//     }
// }

// template <typename K, typename V>
// Hashmap<K, V>::~Hashmap() {
//     delete[] elements;
// }

// template <typename K, typename V>
// void Hashmap<K, V>::clear() {
//     delete[] elements;
//     capacity = 32;
//     count = 0;
//     elements = new Item[capacity]{};
// }

// template <typename K, typename V>
// int Hashmap<K, V>::size() const {
//     return count;
// }

// template <typename K, typename V>
// void Hashmap<K, V>::saveTo(const string& filepath) {
//     ofstream file(filepath);
//     for (int i = 0; i < capacity; ++i) {
//         if (!elements[i].key.empty()) {
//             file << elements[i].key << " " << elements[i].value << endl;
//         }
//     }
//     file.close();
// }

// template <typename K, typename V>
// void Hashmap<K, V>::loadFrom(const string& filepath) {
//     ifstream file(filepath);
//     K key;
//     V value;
//     while (file >> key >> value) {
//         add(key, value);
//     }
//     file.close();
// }

// template <typename K, typename V>
// void Hashmap<K, V>::add(K key, V value) {
//     realloc();
//     long hashed = hash(key);
//     while (!elements[hashed].key.empty()) {
//         if (elements[hashed].key == key) {
//             return; 
//         }
//         hashed = (hashed + 1) % capacity; 
//     }
//     elements[hashed].key = key;
//     elements[hashed].value = value;
//     count++;
// }

// template <typename K, typename V>
// bool Hashmap<K, V>::remove(K key) {
//     long hashed = hash(key);
//     while (!elements[hashed].key.empty()) {
//         if (elements[hashed].key == key) {
//             elements[hashed].key = ""; 
//             count--;
//             return true;
//         }
//         hashed = (hashed + 1) % capacity; 
//     }
//     return false; 
// }

// template <typename K, typename V>
// V Hashmap<K, V>::operator[](K key) {
//     long hashed = hash(key);
//     while (!elements[hashed].key.empty()) {
//         if (elements[hashed].key == key) {
//             return elements[hashed].value;
//         }
//         hashed = (hashed + 1) % capacity; 
//     }
//     throw std::out_of_range("the key not found");
// }

// template <typename K, typename V>
// bool Hashmap<K, V>::contains(K key) const {
//     long hashed = hash(key);
//     while (!elements[hashed].key.empty()) {
//         if (elements[hashed].key == key) {
//             return true;
//         }
//         hashed = (hashed + 1) % capacity; 
//     }
//     return false;
// }

// template <typename K, typename V>
// Hashmap<K, V> Hashmap<K, V>::operator&&(const Hashmap<K, V>& other) const {
//     Hashmap<K, V> result;
//     for (int i = 0; i < capacity; ++i) {
//         if (!elements[i].key.empty() && other.contains(elements[i].key)) {
//             result.add(elements[i].key, elements[i].value);
//         }
//     }
//     return result;
// }

// template <typename K, typename V>
// bool Hashmap<K, V>::operator==(const Hashmap<K, V>& other) const {
//     if (count != other.count) return false;
//     for (int i = 0; i < capacity; ++i) {
//         if (!elements[i].key.empty() && !other.contains(elements[i].key)) {
//             return false;
//         }
//     }
//     return true;
// }

// template <typename K, typename V>
// bool Hashmap<K, V>::operator!=(const Hashmap<K, V>& other) const {
//     return !(*this == other);
// }

// template <typename K, typename V>
// void Hashmap<K, V>::getWinners() const {
//     vector<pair<K, V>> winners;
//     for (int i = 0; i < capacity; ++i) {
//         if (!elements[i].key.empty()) {
//             winners.emplace_back(elements[i].key, elements[i].value);
//         }
//     }
//     sort(winners.begin(), winners.end(), [](const pair<K, V>& a, const pair<K, V>& b) {
//         return a.second > b.second; 
//     });
//     cout << "Winners:" << endl;
//     for (int i = 0; i < min(3, (int)winners.size()); ++i) {
//         cout << winners[i].first << " - " << winners[i].second << endl;
//     }
// }

// template <typename K, typename V>
// void Hashmap<K, V>::realloc() {
//     if ((count * 100) / capacity >= 75) { 
//         int oldCapacity = capacity;
//         capacity *= 2;
//         Item* newElements = new Item[capacity]{};
//         for (int i = 0; i < oldCapacity; ++i) {
//             if (!elements[i].key.empty()) {
//                 long hashed = hash(elements[i].key);
//                 while (!newElements[hashed].key.empty()) {
//                     hashed = (hashed + 1) % capacity; 
//                 }
//                 newElements[hashed] = elements[i];
//             }
//         }
//         delete[] elements;
//         elements = newElements;
//     }
// }
