/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** TextWidget
*/

#include <utility>

#include "Widget.hpp"

TextWidget::TextWidget(std::string title, std::string text, Color level)
    : _title(std::move(title)), _text(std::move(text)), _color(level) {}

std::string TextWidget::getTitle() const { return _title; }
std::string TextWidget::getText() const { return _text; }
TextWidget::Color TextWidget::getColor() const { return _color; }

void TextWidget::setText(std::string text) { _text = std::move(text); }
void TextWidget::setColor(Color level) { _color = level; }
