/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** Widget
*/

#pragma once

#include <deque>
#include <optional>
#include <string>

/**
 * @brief Base class for all display Widgets.
 *
 * This class is meant to be used as a base class and should not be instantiated
 * directly.
 */
class Widget {
   public:
    virtual ~Widget() = default;
};

class TextWidget : public Widget {
   public:
    enum Color { INFO, SUCCESS, WARNING, ERROR };

    TextWidget(std::string title, std::string text, Color level = INFO);
    ~TextWidget() override = default;

    std::string getTitle() const;
    std::string getText() const;
    Color getColor() const;

    void setText(std::string text);
    void setColor(Color level);

    template <typename T>
    static Color colorFrom(std::optional<T> value, Color onNull = ERROR,
                           Color onSome = INFO) {
        return value.has_value() ? onSome : onNull;
    }

   private:
    std::string _title;
    std::string _text;
    Color _color;
};

class HistogramWidget : public TextWidget {
   public:
    HistogramWidget(std::string title);
    ~HistogramWidget() override = default;

    std::deque<float> getValues() const;
    std::optional<float> getLastValue() const;
    void pushValue(float value);


   private:
    std::deque<float> _values;  // values between 0 and 1
};
