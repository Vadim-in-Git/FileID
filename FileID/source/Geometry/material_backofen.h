#pragma once
#include "factory_material.h"
#include <string>

class MaterBackofen : public IMaterial {
public:
	MaterBackofen() = default; // нужен для создания пустого объекта перед загрузкой из файла
	void set_data(const std::string& data) { m_data = data; }
	const char* get_json() const override { return m_data.c_str(); };
	bool load(std::istream& in) override;
	bool save(const std::string& path_file) const override;
private:
	std::string m_data;
};