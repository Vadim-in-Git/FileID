#include "loader.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

std::unique_ptr<IGeometry> load_geometry(const std::string& path_file) {
	if (path_file.rfind(IGeometry::extension) == std::string::npos)
		throw std::runtime_error("Invalid geometry extension: " + path_file);
	std::ifstream fin(path_file);
	if (!fin) throw std::runtime_error("Can't open file: " + path_file);
	std::string id;
	std::getline(fin, id);
	FactoryGeom* ptr_factory = FactoryGeom::Find(id.c_str());
	if (!ptr_factory) throw std::runtime_error("Can't find such an id: " + id);
	std::unique_ptr<IGeometry> ptr_geom(ptr_factory->create());
	if (ptr_geom->load(fin)) return ptr_geom; // выйти из функции если загрузка успешная
	throw std::runtime_error("Incorrect format of file with id: " + id);
}

std::unique_ptr<IMaterial> load_material(const std::string& path_file) {
	if (path_file.rfind(IMaterial::extension) == std::string::npos)
		throw std::runtime_error("Invalid material extension: " + path_file);
	std::ifstream fin(path_file);
	if (!fin) throw std::runtime_error("Can't open file: " + path_file);
	std::string id;
	std::getline(fin, id);
	FactoryMater* ptr_factory = FactoryMater::Find(id.c_str());
	if (!ptr_factory) throw std::runtime_error("Can't find such an id: " + id);
	std::unique_ptr<IMaterial> ptr_mater(ptr_factory->create());
	if (ptr_mater->load(fin)) return ptr_mater; // выйти из функции если загрузка успешная
	throw std::runtime_error("Incorrect format of file with id: " + id);
}

std::variant<std::monostate, std::unique_ptr<IGeometry>, std::unique_ptr<IMaterial>> load(const std::string& path_file) {
	if (path_file.rfind(IGeometry::extension) != std::string::npos)
		return load_geometry(path_file);
	if (path_file.rfind(IMaterial::extension) != std::string::npos)
		return load_material(path_file);
	return {}; // monostate т.е. не нужное расширение не найдено
}