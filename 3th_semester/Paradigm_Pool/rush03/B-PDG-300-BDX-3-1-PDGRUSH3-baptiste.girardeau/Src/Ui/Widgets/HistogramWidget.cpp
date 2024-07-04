/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** HistogramWidget
*/

#include <cstddef>

#include "Widget.hpp"

constexpr size_t MAX_VALUES = 60;

HistogramWidget::HistogramWidget(std::string title)
    : TextWidget(std::move(title), ""), _values(MAX_VALUES, 0.f) {}

std::deque<float> HistogramWidget::getValues() const { return _values; }

void HistogramWidget::pushValue(float value) {
    _values.push_back(value);

    if (_values.size() > MAX_VALUES) {
        _values.pop_front();
    }
}

std::optional<float> HistogramWidget::getLastValue() const {
    if (_values.empty()) {
        return std::nullopt;
    }
    return _values.back();
}
