/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Composite
*/

#pragma once

#include "Ray.hpp"
#include "IShape.hpp"
#include <memory>
#include <utility>
#include <vector>

namespace raytracer {
    class Composite {
        public:
            Composite(std::vector<std::unique_ptr<IShape>> &shapes) : m_shapes(shapes)
            {};
            ~Composite() = default;

            std::pair<size_t, double> getClosestHit(const raytracer::Ray &ray)
            {
                double t = -1;
                size_t lastHit = -1;

                for (size_t i = 0; i < this->m_shapes.size(); i += 1) {
                    double n = m_shapes[i]->hits(ray);
                    if (n > 0 && (n < t || t < 0)) {
                        t = n;
                        lastHit = i;
                    }
                }
                return {lastHit, t};
            }

            bool does_hit(raytracer::Ray &ray, size_t except)
            {
                for (size_t i = 0; i < this->m_shapes.size(); ++i) {
                    if (i == except)
                        continue;
                    auto &currentShape = this->m_shapes[i];
                    double n = currentShape->hits(ray);
                    if (n > 0)
                        return true;
                }
                return false;
            }

            std::vector<std::unique_ptr<raytracer::IShape>> &getShapes()
            {
                return m_shapes;
            }

        protected:
        private:
            std::vector<std::unique_ptr<raytracer::IShape>> &m_shapes;
    };

} // namespace raytracer
