//
// Created by Hakim Bajim on 15.02.23.
//

#ifndef SWE_BAJIM_UE08_HUFFMAN_STRUCTURE_H
#define SWE_BAJIM_UE08_HUFFMAN_STRUCTURE_H

#include <iostream>
#include <vector>

namespace huffman {
    //nodes datastructures
    template<typename T>
    class huffman_node_t {
    private:
        T payload;
        double perc;
        std::pair<huffman_node_t<T> *, huffman_node_t<T> *> next_nodes;

    public:
        huffman_node_t() {
            payload = 0;
            perc = 0;
            next_nodes.first = nullptr;
            next_nodes.second = nullptr;
        }

        explicit huffman_node_t(const T &value = 0, double percent = 0) {
            payload = value;
            perc = percent;
            next_nodes.first = nullptr;
            next_nodes.second = nullptr;
        }

        ~huffman_node_t() {
            delete next_nodes.first, next_nodes.first = nullptr;
            delete next_nodes.second, next_nodes.second = nullptr;
        }

        huffman_node_t<T> * get_left() {
            return next_nodes.first;
        }

        huffman_node_t<T> * get_right() {
            return next_nodes.second;
        }

        T &get_payload() {
            return payload;
        }

        double &get_perc() {
            return perc;
        }

        void set_left(huffman_node_t<T> * node) {
            this->next_nodes.first = node;
        }

        void set_right(huffman_node_t<T> * node) {
            this->next_nodes.second = node;
        }
    };

    template<typename T>
    class huffman_structure {
    public:
        std::vector<huffman_node_t<T>*> base;

        huffman_structure() = default;

        ~huffman_structure() = default;

        void add_node(huffman_node_t<T> * node) {
            base.push_back(node);
        }

        void sort() {
            for (size_t i(0); i < base.size(); ++i) {
                size_t min(i);
                for (size_t j(i); j < base.size(); ++j) {
                    if(base[j]->get_perc() < base[min]->get_perc()) {
                        min = j;
                    }
                }
                std::swap(base[i], base[min]);
            }
        }
    };
}


#endif //SWE_BAJIM_UE08_HUFFMAN_STRUCTURE_H
