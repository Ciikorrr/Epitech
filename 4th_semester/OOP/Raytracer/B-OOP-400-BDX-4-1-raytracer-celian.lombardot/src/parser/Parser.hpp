/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Config
*/

#pragma once

#include <array>
#include <iostream>
#include <libconfig.h++>
#include <memory>
#include <vector>

#include "Light.hpp"
#include "Factory.hpp"
#include "IShape.hpp"
#include "Math.hpp"

class ColorMaker
{   public:
        ColorMaker(const libconfig::Setting &);

        std::array<int, 3> colors;
};

class VectorMaker
{
    public:
        VectorMaker(const libconfig::Setting &);

        std::array<double, 3> origin;
};

namespace raytracer {

class Camera
{
   public:
    int width;
    int height;
    math::Point3 pos;
    math::Vec3 rotation;
    double fov;
};

class Parser
{
   public:
    Parser(const Parser &) = delete;
    Parser(Parser &&) = delete;
    Parser &operator=(const Parser &) = delete;
    Parser &operator=(Parser &&) = delete;
    Parser(const std::string &configPath);
    ~Parser() = default;

    void parseConfig();
    void parseCamera();
    void parseShapes(libconfig::Config &m_config);
    void parseLight(libconfig::Config &m_config);
    void parseSubConfigs(libconfig::Config &m_config);
    void addSpheres(const libconfig::Setting &_primitive);
    void addCones(const libconfig::Setting &_primitive);
    void addCylinders(const libconfig::Setting &_primitive);
    void addPlanes(const libconfig::Setting &_primitive);
    void addLights(const libconfig::Setting &_lights, const std::string &name, bool isPoint);

    libconfig::Config config;
    raytracer::Camera camera;
    raytracer::Lights lights;
    Factory factory;

   protected:
   private:
};
}  // namespace raytracer
