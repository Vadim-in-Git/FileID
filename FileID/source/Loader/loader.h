#pragma once
#include "factory_geometry.h"
#include "factory_material.h"
#include <variant>

std::unique_ptr<IGeometry> load_geometry(const std::string& path_file);
std::unique_ptr<IMaterial> load_material(const std::string& path_file);

std::variant<std::monostate, std::unique_ptr<IGeometry>, std::unique_ptr<IMaterial>> load(const std::string& path_file);