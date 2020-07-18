#ifndef MGE_FACTORY_HPP
#define MGE_FACTORY_HPP

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <cassert>

namespace mge {
    template<class Object, class... Args>
    class factory {

    public:
        /**
         * Just an alias to avoid repeating long type
         */
        using Creator = std::function<std::unique_ptr<Object>(Args...)>;


        /**
         * Register a new creatable class from a specialized class of <Object>.
         *
         * @param key
         * @param creator Function that handle the creation of the object
         */
        void registers(std::string const &key, Creator const &creator) {
            m_registry.emplace(key, creator);
        }

        /**
         * Find the creation function from the map if key exists.
         * Then call the creation function with given arguments (if they are arguments)
         *
         * @param key
         * @param args
         * @return
         */
        std::unique_ptr<Object> make(std::string const &key, Args &&... args) const {
            auto it = m_registry.find(key);
            assert(("[FACTORY] Key not found", it != m_registry.end()));
            auto& r = it->second;
            return r(std::forward<Args>(args)...);
        }

    private:
        std::unordered_map<std::string, Creator> m_registry;
    };
}// namespace mge


#endif//MGE_FACTORY_HPP
