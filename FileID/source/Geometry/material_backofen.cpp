#include "material_backofen.h"
#include <iostream>
#include <string>
#include <fstream>

bool MaterBackofen::load(std::istream& in) {
	for (std::string str; std::getline(in, str); )
		m_data += str + '\n';
	return in.eof();
}

bool MaterBackofen::save(const std::string& path_file) const {
	if (path_file.rfind(IMaterial::extension) == std::string::npos)
		throw std::runtime_error("Invalid material extension: " + path_file);
	std::ofstream fout(path_file);
	if (!fout) throw std::runtime_error("Can't open file: " + path_file);
	fout << "Backofen\n" << m_data;
	return fout.good();
}

static class FactoryMaterBackofen : public FactoryMater {
public:
	FactoryMaterBackofen() : FactoryMater("Backofen") {}
	std::unique_ptr<IMaterial> create() override {
		return std::make_unique<MaterBackofen>();
	};
} s_factory_mater_backofen;