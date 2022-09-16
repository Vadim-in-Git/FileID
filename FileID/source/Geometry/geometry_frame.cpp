#include "geometry_frame.h"
#include <iostream>
#include <string>
#include <fstream>

bool GeomFrame::load(std::istream& in) {
	for (std::string str; std::getline(in, str); )  // считываю строку из file.txt в str
		m_data += str + '\n';
	return in.eof();
}

bool GeomFrame::save(const std::string& path_file) const {
	if (path_file.rfind(IGeometry::extension) == std::string::npos)
		throw std::runtime_error("Invalid geometry extension: " + path_file);
	std::ofstream fout(path_file);
	if (!fout) throw std::runtime_error("Can't open file: " + path_file);
	fout << "Frame\n" << m_data;
	return fout.good();
}

static class FactoryGeomFrame : public FactoryGeom {
public:
	FactoryGeomFrame() : FactoryGeom("Frame") {}
	std::unique_ptr<IGeometry> create() override {
		return std::make_unique<GeomFrame>();
	};
} s_factory_geom_frame;