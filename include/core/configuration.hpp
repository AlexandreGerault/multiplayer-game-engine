#ifndef WEREWOLF_CONFIGURATION_HPP
#define WEREWOLF_CONFIGURATION_HPP

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <spdlog/spdlog.h>

template<typename T>
struct expected {
    static char const *name() { return "SHOULD NOT BE USED"; }
};

template<>
struct expected<std::string> {
    static char const *name() { return "a string"; }
};

template<>
struct expected<int> {
    static char const *name() { return "an int"; }
};

template<>
struct expected<double> {
    static char const *name() { return "a double"; }
};

template<typename T>
struct decoder {
    static T decode(std::string const &text, std::string const &name) {
        std::istringstream iss(text);
        if (T value; (iss >> value).eof()) {
            return value;
        }
        throw std::runtime_error("Cannot extract parameter " + name + " as " +
                                 expected<T>::name() + " from \"" + text + "\"");
    }
};

template<>
struct decoder<std::string> {
    static std::string const &decode(std::string const &text,
                                     std::string const &name) {
        return text;
    }
};

namespace ww {
    class configuration {
    public:
        configuration();

        explicit configuration(std::string path);

        bool has(const std::string &key) const;

        void set(const std::string &key, const std::string &value);

        void add(const std::string &key, const std::string &value);

        void remove(const std::string &key);

        bool load();

        bool save() const;

        /**
         * Get a value from the map and convert to T it if possible.
         * If it cannot convert it returns the string.
         * If it doesn't find the option it does nothing.
         *
         * @tparam T
         * @param key
         * @return a converted value
         * */
        template<typename T>
        T get(const std::string &key, T defaultValue = T{}) const {
            auto iterator = m_fields.find(key);
            if (iterator == m_fields.end()) {
                return defaultValue;
            }
            return decoder<T>::decode(iterator->second, key);
        };

    private:
        std::unordered_map<std::string, std::string> m_fields;
        std::string m_file;
    };
}// namespace ww

#endif// WEREWOLF_CONFIGURATION_HPP
