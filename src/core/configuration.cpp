#include <core/configuration.hpp>

using namespace ww;

configuration::configuration() : m_file("default.config") {
    load();
}

configuration::configuration(std::string path) : m_file(std::move(path)) {
    if (load()) {
        spdlog::debug("Configuration loaded successfully!");
    } else {
        spdlog::error("Cannot load configuration {}", m_file);
    }
}

/**
 * Check whether the options map contains a key or not
 *
 * @param key
 * @return true if the map has the option
 */
bool configuration::has(const std::string &key) const {
    return m_fields.contains(key);
}

/**
 * Update the value of an existing option identified by its key.
 * If the key does not exist then the function does nothing
 *
 * @param key
 * @param value
 */
void configuration::set(const std::string &key, const std::string &value) {
    auto iterator = m_fields.find(key);
    if (iterator != m_fields.end()) {
        iterator->second = value;
    }
}

/**
 * Add a new option entry if the entry does not still exist
 * Else it throw an exception
 *
 * @param key
 * @param value
 */
void configuration::add(const std::string &key, const std::string &value) {
    m_fields.insert({key, value});
}

/**
 * Remove an option if it finds it.
 * Else it does nothing.
 *
 * @param key
 */
void configuration::remove(const std::string &key) { m_fields.erase(key); }

/**
 * Reset the map and fill it with the content of a configuration file
 * The syntax of the configuration file must be like this
 * KEY=VALUE
 * with 1 pair per line
 *
 * @param path
 * @return
 */
bool configuration::load() {
    m_fields.clear();
    std::ifstream loadingFile(m_file);

    spdlog::debug("Load configuration...");

    if (loadingFile.is_open()) {
        std::string line;
        std::string delimiter{"="};
        while (std::getline(loadingFile, line)) {
            spdlog::debug("Loading a value");
            if (auto pos = line.find(delimiter); pos != std::string::npos) {
                std::string key{line.substr(0, pos)};
                std::string value{line.substr(pos + 1, line.length())};
                m_fields.insert({key, value});
                spdlog::debug("Key: {} | Value: {}", key, value);
            }
        }
        return true;
    }

    return false;
}

/**
 * Saves the current fields to a configuration file.
 * If the file already exists it is previously cleared.
 * It stores each option on a new line matching the below syntax:
 * KEY=VALUE
 *
 * @param path
 * @return whether the configuration was successfully saved
 */
bool configuration::save() const {
    std::ofstream savingFile(m_file);
    savingFile.clear();
    for (auto const &[key, value] : m_fields) {
        savingFile << key << "=" << value << std::endl;
    }
    savingFile.close();
    return !savingFile.fail();
}
