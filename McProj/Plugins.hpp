#pragma once

#include <string>
#include <unordered_map>

#include <pybind11/pybind11.h>
namespace py = pybind11;

class Plugins : public std::unordered_map<std::string, py::module_> {
public:
	void loadPlugin(std::string name);
	void loadAllPlugins();
};