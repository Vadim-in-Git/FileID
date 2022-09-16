#pragma once
#include "factory_geometry.h"
#include <string>

class GeomFrame : public IGeometry {
public:
	GeomFrame() = default; // нужен для создания пустого объекта перед загрузкой из файла
	void set_data(const std::string& data) { m_data = data; }
	const char* get_json() const override { return m_data.c_str(); };
	bool load(std::istream& in) override;
	bool save(const std::string& path_file) const override;
private:
	std::string m_data;
};