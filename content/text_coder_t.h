//
// Created by Hakim Bajim on 15.02.23.
//

#ifndef SWE_BAJIM_UE08_TEXT_CODER_T_H
#define SWE_BAJIM_UE08_TEXT_CODER_T_H

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <map>

#include "huffman_structure.h"

namespace coder {

    class text_coder_t {
    private:
        std::map<char, int> values;

        std::map<char, std::string> result;

        huffman::huffman_structure<char> head;
        int amount = 0;

        std::istream &read(std::istream &input = std::cin) {
            std::string res;
            while (input >> res) {

                for (char c: res) {
                    if (values.find(c) == values.end()) {
                        values[c] = 1;
                    } else {
                        ++values[c];
                    }
                    ++amount;
                }
            }
            create_and_fill_tree();
            return input;
        }

        void create_and_fill_tree() {
            for (auto &value: values) {
                double tmp = (double) value.second / amount;
                auto *t = new huffman::huffman_node_t<char>((char) value.first, tmp);
                t->set_left(nullptr);
                t->set_right(nullptr);

                head.add_node(t);
            }
            head.sort();
        }

        void read(const std::string &file) {
            std::ifstream ifs(file);
            read(ifs);
            ifs.close();
        }

        std::ostream &write(std::ostream &out, const std::string &file) {
            std::ifstream ifs(file);

            if(ifs.peek() != std::ifstream::traits_type::eof()) {
                fill_result_map(head.base[0], "");

                std::string res;
                while (ifs >> res) {
                    for (const char c: res) {
                        out << result[c];
                    }
                }

                ifs.close();
            }

            return out;
        }

        void fill_result_map(huffman::huffman_node_t<char> *node, const std::string code) {
            if (code.size() && node->get_payload() != 0) {
                result[node->get_payload()] = code;
            }
            if (node->get_payload() == 0) {
                fill_result_map(node->get_left(), code + "0");
                fill_result_map(node->get_right(), code + "1");
            }
        }

    public:
        text_coder_t() = default;

        void encode(const std::string &file) {
            read(file);
            while (head.base.size() > 1) {
                double tmp = head.base[0]->get_perc() + head.base[1]->get_perc();
                auto *t = new huffman::huffman_node_t<char>((char) 0, tmp);
                t->set_left(head.base[0]);
                t->set_right(head.base[1]);

                head.base.erase(head.base.begin());
                head.base.erase(head.base.begin());

                head.add_node(t);
                head.sort();
            }
            std::string t(file.substr(0, file.find_last_of('.')));
            t += ".enc";

            std::ofstream ofs(t);
            write(ofs, file);
            ofs.close();
        }

        void decode(const std::string &file) {
            std::ifstream ifs(file);

            std::string res;

            while (ifs >> res) {
                auto t = head.base[0];
                int i(0);

                while (i < res.size()) {
                    char current(res[i]);

                    if (current == '0') {
                        t = t->get_left();
                    } else {
                        t = t->get_right();
                    }

                    if (t->get_payload() != 0) {
                        std::cout << t->get_payload();
                        t = head.base[0];
                    }

                    ++i;
                }
            }

            ifs.close();
        }
    };
}

#endif //SWE_BAJIM_UE08_TEXT_CODER_T_H
