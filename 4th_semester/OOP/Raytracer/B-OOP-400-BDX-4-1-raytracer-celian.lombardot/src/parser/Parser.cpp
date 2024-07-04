/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** parsing
*/

#include "Parser.hpp"

#include "Math.hpp"

VectorMaker::VectorMaker(const libconfig::Setting &set) : origin({})
{
    set.lookupValue("x", this->origin[0]);
    set.lookupValue("y", this->origin[1]);
    set.lookupValue("z", this->origin[2]);
}

ColorMaker::ColorMaker(const libconfig::Setting &_color) : colors({})
{
    _color.lookupValue("r", this->colors[0]);
    _color.lookupValue("g", this->colors[1]);
    _color.lookupValue("b", this->colors[2]);
}

raytracer::Parser::Parser(const std::string &configPath)
{
    this->config.readFile(configPath);
    this->parseConfig();
}

void raytracer::Parser::addSpheres(const libconfig::Setting &_primitive)
{
    const libconfig::Setting &spheres = _primitive["spheres"];

    for (int i = 0; i < spheres.getLength(); i += 1) {
        double radius = 0;
        double reflection = 0;
        double lightR = 0;
        VectorMaker center(spheres[i]);
        ColorMaker color(spheres[i]["color"]);
        spheres[i].lookupValue("r", radius);
        spheres[i].lookupValue("reflection", reflection);
        spheres[i].lookupValue("lightR", lightR);
        math::Point3 point(
            center.origin[0], center.origin[1], center.origin[2]);
        math::Color sColor(
            double(color.colors[0]) / 255, double(color.colors[1]) / 255,
            double(color.colors[2]) / 255);
        factory.addSphere(point, radius, sColor, reflection, lightR);
    }
}

void raytracer::Parser::addCones(const libconfig::Setting &_primitive)
{
    const libconfig::Setting &cones = _primitive["cones"];

    for (int i = 0; i < cones.getLength(); i += 1) {
        double radius = 0;
        double reflection = 0;
        double lightR = 0;
        VectorMaker center(cones[i]);
        ColorMaker color(cones[i]["color"]);
        VectorMaker normal(cones[i]["normal"]);
        cones[i].lookupValue("r", radius);
        cones[i].lookupValue("reflection", reflection);
        cones[i].lookupValue("lightR", lightR);
        math::Point3 point(
            center.origin[0], center.origin[1], center.origin[2]);
        math::Color sColor(
            double(color.colors[0]) / 255, double(color.colors[1]) / 255,
            double(color.colors[2]) / 255);
        math::Vec3 norm = {normal.origin[0], normal.origin[1], normal.origin[2]};
        factory.addCone(point, radius, norm, sColor, reflection, lightR);
    }
}

void raytracer::Parser::addCylinders(const libconfig::Setting &_primitive)
{
    const libconfig::Setting &cones = _primitive["cylinders"];

    for (int i = 0; i < cones.getLength(); i += 1) {
        double radius = 0;
        double reflection = 0;
        double lightR = 0;
        VectorMaker center(cones[i]);
        ColorMaker color(cones[i]["color"]);
        VectorMaker normal(cones[i]["normal"]);
        cones[i].lookupValue("r", radius);
        cones[i].lookupValue("reflection", reflection);
        cones[i].lookupValue("lightR", lightR);
        math::Point3 point(
            center.origin[0], center.origin[1], center.origin[2]);
        math::Color sColor(
            double(color.colors[0]) / 255, double(color.colors[1]) / 255,
            double(color.colors[2]) / 255);
        math::Vec3 norm = {normal.origin[0], normal.origin[1], normal.origin[2]};
        factory.addCylinder(point, radius, norm, sColor, reflection, lightR);
    }
}

void raytracer::Parser::addPlanes(const libconfig::Setting &_primitive)
{
    const libconfig::Setting &planes = _primitive["planes"];

    for (int i = 0; i < planes.getLength(); i += 1) {
        double reflection = 0;
        double lightR = 0;
        VectorMaker origin(planes[i]["origin"]);
        VectorMaker normal(planes[i]["normal"]);
        ColorMaker color(planes[i]["color"]);
        planes[i].lookupValue("reflection", reflection);
        planes[i].lookupValue("lightR", lightR);
        factory.addPlanes(
            math::Vec3(normal.origin[0], normal.origin[1], normal.origin[2]),
            math::Point3(origin.origin[0], origin.origin[1], origin.origin[2]),
            math::Color(
                double(color.colors[0]) / 255, double(color.colors[1]) / 255,
                double(color.colors[2]) / 255),
            reflection, lightR);
    }
}

void raytracer::Parser::parseShapes(libconfig::Config &m_config)
{
    if (!m_config.exists("primitives"))
        return;
    const libconfig::Setting &_primitive = m_config.lookup("primitives");

    if (_primitive.exists("spheres"))
        addSpheres(_primitive);
    if (_primitive.exists("planes"))
        addPlanes(_primitive);
    if (_primitive.exists("cones"))
        addCones(_primitive);
    if (_primitive.exists("cylinders"))
        addCylinders(_primitive);
}

void raytracer::Parser::parseCamera()
{
    try {
        const libconfig::Setting &_camera = this->config.lookup("camera");
        const libconfig::Setting &resolution = _camera["resolution"];

        resolution.lookupValue("width", this->camera.width);
        resolution.lookupValue("height", this->camera.height);
        VectorMaker pos(_camera["position"]);
        VectorMaker rotation(_camera["rotation"]);
        this->camera.pos =
            math::Point3(pos.origin[0], pos.origin[1], pos.origin[2]);
        this->camera.rotation = math::Vec3(
            rotation.origin[0], rotation.origin[1], rotation.origin[2]);
        _camera.lookupValue("fieldOfView", this->camera.fov);
    } catch (libconfig::SettingNotFoundException &e) {
        this->camera.fov = 90;
        this->camera.height = 1080;
        this->camera.width = 1920;
        this->camera.pos = {};
        this->camera.rotation = {};
    }
}

void raytracer::Parser::addLights(
    const libconfig::Setting &_lights, const std::string &name, bool isPoint)
{
    const libconfig::Setting &dir = _lights[name];

    for (int i = 0; i < dir.getLength(); i += 1) {
        double intensity = 0;
        VectorMaker direction(dir[i]);
        ColorMaker color(dir[i]["color"]);
        math::Vec3 vec;
        dir[i].lookupValue("intensity", intensity);
        math::Color c(
            color.colors[0] / 255.0, color.colors[1] / 255.0,
            color.colors[2] / 255.0);
        if (!isPoint)
            vec = math::unitVector(
                {direction.origin[0], direction.origin[1],
                 direction.origin[2]});
        else
            vec = math::Vec3(
                direction.origin[0], direction.origin[1], direction.origin[2]);
        this->lights.m_dir.emplace_back(
            raytracer::Light(vec, intensity, c, isPoint));
    }
}

void raytracer::Parser::parseLight(libconfig::Config &m_config)
{
    if (!m_config.exists("lights"))
        return;
    const libconfig::Setting &_lights = m_config.lookup("lights");

    std::vector<Light> directional;
    std::vector<Light> point;
    double diffuse = -1;
    double ambient = -1;

    _lights.lookupValue("diffuse", diffuse);
    _lights.lookupValue("ambient", ambient);
    if (_lights.exists("directional"))
        addLights(_lights, "directional", false);
    if (_lights.exists("point"))
        addLights(_lights, "point", true);
    if (diffuse != -1)
        this->lights.m_diffuse = diffuse;
    if (ambient != -1)
        this->lights.m_ambiant = ambient;
}

void raytracer::Parser::parseSubConfigs(libconfig::Config &m_config)
{
    if (!m_config.exists("subConfigs"))
        return;
    const libconfig::Setting &configs = m_config.lookup("subConfigs");
    if (!configs.exists("files"))
        return;
    const libconfig::Setting &files = configs.lookup("files");

    for (int i = 0; i < files.getLength(); i += 1) {
        libconfig::Config m_config;
        std::string fileName;
        files[i].lookupValue("fileName", fileName);
        m_config.readFile(fileName);
        this->parseShapes(m_config);
        this->parseLight(m_config);
        this->parseSubConfigs(m_config);
    }
}

void raytracer::Parser::parseConfig()
{
    try {
        this->parseCamera();
        this->parseShapes(this->config);
        this->parseLight(this->config);
        this->parseSubConfigs(this->config);
    } catch (libconfig::SettingNotFoundException &e) {
        return;
    }
}
