/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "Cone.hpp"
#include "Cylinder.hpp"
#include "IShape.hpp"
#include "Math.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"
#include <memory>
#include <vector>

class Factory {
    public:
        Factory() = default;
        Factory(const Factory &) = default;
        Factory(Factory &&) = delete;
        Factory &operator=(const Factory &) = delete;
        Factory &operator=(Factory &&) = delete;
        ~Factory() = default;

        void addSphere(math::Point3 point, double radius, math::Color color, double reflection, double lightR)
        {
            m_shapes.emplace_back(std::make_unique<raytracer::Sphere>(point,
            radius, color, reflection, lightR));
        }

        void addCylinder(math::Point3 point, double radius,  math::Vec3 normal, math::Color color, double reflection, double lightR)
        {
            m_shapes.emplace_back(std::make_unique<raytracer::Cylinder>(point,
            radius, normal, color, reflection, lightR));
        }

        void addCone(math::Point3 point, double radius, math::Vec3 normal, math::Color color, double reflection, double lightR)
        {
            m_shapes.emplace_back(std::make_unique<raytracer::Cone>(point,
            radius, normal, color, reflection, lightR));
        }

        void addPlanes(math::Vec3 normal, math::Point3 point, math::Color color, double reflection, double lightR)
        {
            m_shapes.emplace_back(std::make_unique<raytracer::Plane>(normal,
            point, color, reflection, lightR));
        }

        std::vector<std::unique_ptr<raytracer::IShape>> m_shapes;
    protected:
    private:
};

#endif /* !FACTORY_HPP_ */
