/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Util
*/

#pragma once

#include <format>
#include <iostream>
#include <optional>
#include <type_traits>
#include <unordered_map>
#include <vector>

namespace zizi::util {

template <typename T, typename K>
std::optional<typename std::decay<T>::type::mapped_type> map_get(T &&map, K &&key)
{
    auto it = map.find(std::forward<K>(key));
    if (it == map.end()) {
        return std::nullopt;
    }
    return it->second;
}

template <typename K, typename V>
std::vector<V> map_values(const std::unordered_map<K, V> &map)
{
    std::vector<V> values;
    for (const auto &[_, value] : map) {
        values.push_back(value);
    }
    return values;
}

template <typename T, typename F>
std::optional<T> find_if(const std::vector<T> &vec, F predicate)
{
    auto it = std::find_if(vec.begin(), vec.end(), predicate);
    if (it == vec.end()) {
        return std::nullopt;
    }
    return *it;
}

#ifndef NDEBUG
template <class... Args>
void debug(std::format_string<Args...> fmt, Args &&...args)
{
    std::string formatted = std::format(fmt, std::forward<Args>(args)...);
    std::cout << "\033[90m[DEBUG] " << formatted << "\033[0m\n";
}
#else
template <class... Args>
inline void debug([[maybe_unused]] std::format_string<Args...> fmt, [[maybe_unused]] Args &&...args)
{}  // NOLINT
#endif

}  // namespace zizi::util
