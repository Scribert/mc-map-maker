// #include <corecrt.h> // Fixes pybind11 bug
#include <glm/glm.hpp>
#include <pybind11/embed.h>
namespace py = pybind11;

PYBIND11_EMBEDDED_MODULE(editor, m) {
    py::class_<glm::vec2>(m, "vec2")
        .def(py::init<float, float>())
        .def_readwrite("x", &glm::vec2::x)
        .def_readwrite("y", &glm::vec2::y)
        .def_readwrite("r", &glm::vec2::r)
        .def_readwrite("g", &glm::vec2::g)
        .def_readwrite("s", &glm::vec2::s)
        .def_readwrite("t", &glm::vec2::t);

    py::class_<glm::vec3>(m, "vec3")
        .def(py::init<float, float, float>())
        .def_readwrite("x", &glm::vec3::x)
        .def_readwrite("y", &glm::vec3::y)
        .def_readwrite("z", &glm::vec3::z)
        .def_readwrite("r", &glm::vec3::r)
        .def_readwrite("g", &glm::vec3::g)
        .def_readwrite("b", &glm::vec3::b)
        .def_readwrite("s", &glm::vec3::s)
        .def_readwrite("t", &glm::vec3::t)
        .def_readwrite("p", &glm::vec3::p);

    py::class_<glm::ivec2>(m, "ivec2")
        .def(py::init<int , int>())
        .def_readwrite("x", &glm::ivec2::x)
        .def_readwrite("y", &glm::ivec2::y)
        .def_readwrite("r", &glm::ivec2::r)
        .def_readwrite("g", &glm::ivec2::g)
        .def_readwrite("s", &glm::ivec2::s)
        .def_readwrite("t", &glm::ivec2::t);
    
    py::class_<glm::ivec3>(m, "ivec3")
        .def(py::init<int, int, int>())
        .def_readwrite("x", &glm::ivec3::x)
        .def_readwrite("y", &glm::ivec3::y)
        .def_readwrite("z", &glm::ivec3::z)
        .def_readwrite("r", &glm::ivec3::r)
        .def_readwrite("g", &glm::ivec3::g)
        .def_readwrite("b", &glm::ivec3::b)
        .def_readwrite("s", &glm::ivec3::s)
        .def_readwrite("t", &glm::ivec3::t)
        .def_readwrite("p", &glm::ivec3::p);
}